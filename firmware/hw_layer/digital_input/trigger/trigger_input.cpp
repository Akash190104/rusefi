/*
 * @file	trigger_input.cpp
 *
 * @date Nov 11, 2019
 * @author Andrey Belomutskiy, (c) 2012-2021
 */

#include "pch.h"
#include "trigger_input.h"

/* TODO:
 * - merge comparator trigger
 */

#if (EFI_SHAFT_POSITION_INPUT) || defined(__DOXYGEN__)

#if (HAL_TRIGGER_USE_PAL == TRUE) || (HAL_TRIGGER_USE_ADC == TRUE)

#if (HAL_TRIGGER_USE_PAL == TRUE)
	int  extiTriggerTurnOnInputPin(const char *msg, int index, bool isTriggerShaft);
	void extiTriggerTurnOffInputPin(brain_pin_e brainPin);
#else
	int  extiTriggerTurnOnInputPin(const char *msg, int index, bool isTriggerShaft) {
		UNUSED(msg);
		UNUSED(index);
		UNUSED(isTriggerShaft);

		return -2;
	}
	#define extiTriggerTurnOffInputPin(brainPin) ((void)0)
#endif

#if (HAL_TRIGGER_USE_ADC == TRUE)
	void adcTriggerTurnOnInputPins();
	int  adcTriggerTurnOnInputPin(const char *msg, int index, bool isTriggerShaft);
	void adcTriggerTurnOffInputPin(brain_pin_e brainPin);
#else
	#define adcTriggerTurnOnInputPins() ((void)0)
	int  adcTriggerTurnOnInputPin(const char *msg, int index, bool isTriggerShaft) {
		UNUSED(msg);
		UNUSED(index);
		UNUSED(isTriggerShaft);

		return -2;
	}
	#define adcTriggerTurnOffInputPin(brainPin) ((void)0)
#endif

enum triggerType {
	TRIGGER_NONE,
	TRIGGER_EXTI,
	TRIGGER_ADC,
};

static triggerType shaftTriggerType[TRIGGER_INPUT_PIN_COUNT];
static triggerType camTriggerType[CAM_INPUTS_COUNT];

static int turnOnTriggerInputPin(const char *msg, int index, bool isTriggerShaft) {
	brain_pin_e brainPin = isTriggerShaft ?
		engineConfiguration->triggerInputPins[index] : engineConfiguration->camInputs[index];

	if (isTriggerShaft) {
		shaftTriggerType[index] = TRIGGER_NONE;
	} else {
		camTriggerType[index] = TRIGGER_NONE;
	}

	if (!isBrainPinValid(brainPin)) {
		return 0;
	}

	/* ... then ADC */
#if HAL_TRIGGER_USE_ADC
	if (adcTriggerTurnOnInputPin(msg, index, isTriggerShaft) >= 0) {
		if (isTriggerShaft) {
			shaftTriggerType[index] = TRIGGER_ADC;
		} else {
			camTriggerType[index] = TRIGGER_ADC;
		}
		return 0;
	}
#endif

	/* ... then EXTI */
	if (extiTriggerTurnOnInputPin(msg, index, isTriggerShaft) >= 0) {
		if (isTriggerShaft) {
			shaftTriggerType[index] = TRIGGER_EXTI;
		} else {
			camTriggerType[index] = TRIGGER_EXTI;
		}
		return 0;
	}

	firmwareError(CUSTOM_ERR_NOT_INPUT_PIN, "%s: Not input pin %s", msg, hwPortname(brainPin));

	return -1;
}

static void turnOffTriggerInputPin(int index, bool isTriggerShaft) {
	brain_pin_e brainPin = isTriggerShaft ?
		activeConfiguration.triggerInputPins[index] : activeConfiguration.camInputs[index];

	if (isTriggerShaft) {
		if (shaftTriggerType[index] == TRIGGER_ADC) {
			adcTriggerTurnOffInputPin(brainPin);
		}

		if (shaftTriggerType[index] == TRIGGER_EXTI) {
			extiTriggerTurnOffInputPin(brainPin);
		}

		shaftTriggerType[index] = TRIGGER_NONE;
	} else {
		if (camTriggerType[index] == TRIGGER_ADC) {
			adcTriggerTurnOffInputPin(brainPin);
		}

		if (camTriggerType[index] == TRIGGER_EXTI) {
			extiTriggerTurnOffInputPin(brainPin);
		}

		camTriggerType[index] = TRIGGER_NONE;
	}
}

/*==========================================================================*/
/* Exported functions.														*/
/*==========================================================================*/

void stopTriggerInputPins() {
	for (int i = 0; i < TRIGGER_INPUT_PIN_COUNT; i++) {
		if (isConfigurationChanged(triggerInputPins[i])) {
			turnOffTriggerInputPin(i, true);
		}
	}
	for (int i = 0; i < CAM_INPUTS_COUNT; i++) {
		if (isConfigurationChanged(camInputs[i])) {
			turnOffTriggerInputPin(i, false);
		}
	}
}

static const char* const camNames[] = { "cam1", "cam2", "cam3", "cam4"};

void startTriggerInputPins() {
	for (int i = 0; i < TRIGGER_INPUT_PIN_COUNT; i++) {
		if (isConfigurationChanged(triggerInputPins[i])) {
			const char * msg = (i == 0 ? "Trigger #1" : (i == 1 ? "Trigger #2" : "Trigger #3"));
			turnOnTriggerInputPin(msg, i, true);
		}
	}

	for (int i = 0; i < CAM_INPUTS_COUNT; i++) {
		if (isConfigurationChanged(camInputs[i])) {
			turnOnTriggerInputPin(camNames[i], i, false);
		}
	}
}

void turnOnTriggerInputPins() {
	applyNewTriggerInputPins();
}

#endif /* (HAL_TRIGGER_USE_PAL == TRUE) || (HAL_TRIGGER_USE_ADC == TRUE) */


void stopTriggerDebugPins() {
	for (int i = 0; i < TRIGGER_INPUT_PIN_COUNT; i++) {
		efiSetPadUnusedIfConfigurationChanged(triggerInputDebugPins[i]);
	}
	for (int i = 0; i < CAM_INPUTS_COUNT; i++) {
		efiSetPadUnusedIfConfigurationChanged(camInputsDebug[i]);
	}
}

void startTriggerDebugPins() {
	for (int i = 0; i < TRIGGER_INPUT_PIN_COUNT; i++) {
		efiSetPadModeIfConfigurationChanged("trigger debug", triggerInputDebugPins[i], PAL_MODE_OUTPUT_PUSHPULL);
	}
	for (int i = 0; i < CAM_INPUTS_COUNT; i++) {
		efiSetPadModeIfConfigurationChanged("cam debug", camInputsDebug[i], PAL_MODE_OUTPUT_PUSHPULL);
	}
}

void applyNewTriggerInputPins() {
	if (hasFirmwareError()) {
		return;
	}

#if EFI_PROD_CODE
	// first we will turn off all the changed pins
	stopTriggerInputPins();
	if (isConfigurationChanged(triggerInputDebugPins[0])) {
		engine->rpmCalculator.unregister();
		if (isBrainPinValid(engineConfiguration->triggerInputDebugPins[0])) {
			// if we do not have primary input channel maybe it's BCM mode and we inject RPM value via Lua?
			engine->rpmCalculator.Register();
		}
	}
	// then we will enable all the changed pins
	startTriggerInputPins();
#endif /* EFI_PROD_CODE */
}

#endif /* EFI_SHAFT_POSITION_INPUT */
