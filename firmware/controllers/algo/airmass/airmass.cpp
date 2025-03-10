#include "pch.h"

#include "airmass.h"
#include "idle_thread.h"

AirmassVeModelBase::AirmassVeModelBase(const ValueProvider3D& veTable) : m_veTable(&veTable) {}

float AirmassVeModelBase::getVeLoadAxis(float passedLoad) const {
	switch(engineConfiguration->veOverrideMode) {
		case VE_None: return passedLoad;
		case VE_MAP: return Sensor::getOrZero(SensorType::Map);
		case VE_TPS: return Sensor::getOrZero(SensorType::Tps1);
		default: return 0;
	}
}

float AirmassVeModelBase::getVe(int rpm, float load) const {
	efiAssert(OBD_PCM_Processor_Fault, m_veTable != nullptr, "VE table null", 0);

	// Override the load value if necessary
	load = getVeLoadAxis(load);

	percent_t ve = m_veTable->getValue(rpm, load);

	auto tps = Sensor::get(SensorType::Tps1);
	// get VE from the separate table for Idle if idling
	if (engine->module<IdleController>()->isIdlingOrTaper() &&
	    tps && engineConfiguration->useSeparateVeForIdle) {
		percent_t idleVe = interpolate3d(
			config->idleVeTable,
			config->idleVeLoadBins, load,
			config->idleVeRpmBins, rpm
		);
		// interpolate between idle table and normal (running) table using TPS threshold
		ve = interpolateClamped(0.0f, idleVe, engineConfiguration->idlePidDeactivationTpsThreshold, ve, tps.Value);
	}

	// Add any adjustments if configured
	for (size_t i = 0; i < efi::size(config->veBlends); i++) {
		auto result = calculateBlend(config->veBlends[i], rpm, load);

		engine->outputChannels.veBlendBias[i] = result.Bias;
		engine->outputChannels.veBlendOutput[i] = result.Value;

		if (result.Value == 0) {
			continue;
		}

		// Apply as a multiplier, not as an adder
		// Value of +5 means add 5%, aka multiply by 1.05
		ve *= ((100 + result.Value) * 0.01f);
	}

	engine->engineState.currentVe = ve;
	engine->engineState.currentVeLoad = load;
	return ve * PERCENT_DIV;
}
