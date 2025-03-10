/*
 * @file test_nissan_vq_vvt.cpp
 *
 *  Created on: Jul 2, 2021
 * @author Andrey Belomutskiy, (c) 2012-2021
 */

#include "pch.h"
#include "trigger_nissan.h"
#include "nissan_vq.h"

class TriggerCallback {
public:
	Engine *engine;
	int toothIndex;
	TriggerWaveform *form;
	bool isVvt;
	int vvtBankIndex;
	scheduling_s sched;
};

static void func(TriggerCallback *callback) {
	int formIndex = callback->toothIndex % callback->form->getSize();
	Engine *engine = callback->engine;


	TriggerValue value = callback->form->wave.getChannelState(0, formIndex);
	efitick_t nowNt = getTimeNowNt();
	if (callback->isVvt) {
		hwHandleVvtCamSignal(value, nowNt, callback->vvtBankIndex * CAMS_PER_BANK);
	} else {
		handleShaftSignal(0, value == TriggerValue::RISE, nowNt);
	}
}


static void scheduleTriggerEvents(TriggerWaveform *shape,
		float timeScale,
		int count,
		bool isVvt,
		int vvtBankIndex,
		int vvtOffset,
		std::vector<std::shared_ptr<TriggerCallback>>& ptrs) {
	int totalIndex = 0;

	/**
	 * yet another approach to trigger testing: let's schedule a huge list of events from heap
	 * and then execute those one
	 */
	for (int r = 0; r < count; r++) {
		for (size_t i = 0; i < shape->getSize(); i++) {
			float angle = vvtOffset + shape->getAngle(totalIndex);

			std::shared_ptr<TriggerCallback> param = std::make_shared<TriggerCallback>();
			ptrs.push_back(param);

			param->engine = engine;
			param->toothIndex = totalIndex;
			param->form = shape;
			param->isVvt = isVvt;
			param->vvtBankIndex = vvtBankIndex;

			engine->executor.scheduleByTimestamp("test", &param->sched, timeScale * 1000 * angle, { func, param.get() });
			totalIndex++;
		}
	}
}


TEST(nissan, vq_vvt) {
	// hold a reference to the heap allocated scheduling events until the test is done
	std::vector<std::shared_ptr<TriggerCallback>> ptrs;

	EngineTestHelper eth (HELLEN_121_NISSAN_6_CYL);
	engineConfiguration->isFasterEngineSpinUpEnabled = false;
	engineConfiguration->isIgnitionEnabled = false;
	engineConfiguration->isInjectionEnabled = false;

	int cyclesCount = 48;

	{
		static TriggerWaveform crank;
		initializeNissanVQ35crank(&crank);

		scheduleTriggerEvents(&crank,
				/* timeScale */ 1,
				cyclesCount, false, -1, 0, ptrs);
	}
	float vvtTimeScale = 1;

	angle_t testVvtOffset = 13;

	{
		static TriggerWaveform vvt;
		initializeNissanVQvvt(&vvt);

		scheduleTriggerEvents(&vvt,
				/* timeScale */ vvtTimeScale,
				cyclesCount / 6, true,
				/* vvtBankIndex */ 0,
				/* vvtOffset */ testVvtOffset,
				ptrs);
	}

	{
		static TriggerWaveform vvt;
		initializeNissanVQvvt(&vvt);

		scheduleTriggerEvents(&vvt,
				/* timeScale */ vvtTimeScale,
				cyclesCount / 6, true,
				/* vvtBankIndex */1,
				/* vvtOffset */ testVvtOffset + NISSAN_VQ_CAM_OFFSET,
				ptrs);
	}

	eth.executeUntil(1473000);
	ASSERT_EQ(167, round(Sensor::getOrZero(SensorType::Rpm)));

	eth.executeUntil(1475000);
	ASSERT_EQ(167, round(Sensor::getOrZero(SensorType::Rpm)));
	TriggerCentral *tc = &engine->triggerCentral;

	eth.executeUntil(3593000);
	ASSERT_TRUE(tc->vvtState[0][0].getShaftSynchronized());

	scheduling_s *head;
	while ((head = engine->executor.getHead()) != nullptr) {
		eth.setTimeAndInvokeEventsUs(head->momentX);

		ASSERT_TRUE(tc->vvtState[0][0].getShaftSynchronized());
		// let's celebrate that vvtPosition stays the same
    	ASSERT_NEAR(-testVvtOffset, tc->vvtPosition[0][0], EPS2D);
	}

	ASSERT_TRUE(tc->vvtState[1][0].getShaftSynchronized());

	ASSERT_NEAR(-testVvtOffset, tc->vvtPosition[0][0], EPS2D);
	ASSERT_NEAR(-testVvtOffset, tc->vvtPosition[1][0], EPS2D);

	EXPECT_EQ(0, eth.recentWarnings()->getCount());
}
