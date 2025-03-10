/*
 * sent_hw_icu.cpp
 *
 * SENT protocol glue to ChibiOS ICU driver
 *
 * @date Oct 01, 2022
 * @author Andrey Gusakov <dron0gus@gmail.com>, (c) 2022
 */

#if EFI_PROD_CODE

#include "ch.h"
#include "hal.h"

#include "sent.h"
#include "sent_hw_icu.h"

#include "io_pins.h"
#include "pin_repository.h"

/* This SENT HW driver is based on ChibiOS ICU driver */
#if (HAL_USE_ICU == TRUE)

/* TODO: get at runtime */
#define SENT_ICU_FREQ		(CORE_CLOCK / 2) // == CPU freq / 2

/* TODO: implement helper to get AF from GPIO for TIM2 capture */
#define SENT_INPUT_AF		PAL_MODE_ALTERNATE(1)

/* TODO: implement helper to get ICU and channel from GPIO */
#define SENT_ICU_UNIT		ICUD2	/* TIM2 */
#define SENT_ICU_CHANNEL	ICU_CHANNEL_2

/* ICU callbacks */
static void icuperiodcb_in1(ICUDriver *icup)
{
	SENT_ISR_Handler(0, icuGetPeriodX(icup));
}

/* ICU configs */
static ICUConfig icucfg_in1 =
{
	.mode = ICU_INPUT_ACTIVE_LOW,
	.frequency = SENT_ICU_FREQ,
	.width_cb = NULL,
	.period_cb = icuperiodcb_in1,
	.overflow_cb = NULL,
	.channel = SENT_ICU_CHANNEL,
	.dier = 0U,
	.arr = 0xFFFFFFFFU,
};

/* current config */
static brain_input_pin_e sentPins[SENT_INPUT_COUNT];

void startSent()
{
	for (int i = 0; i < SENT_INPUT_COUNT; i++) {
		brain_input_pin_e sentPin = engineConfiguration->sentInputPins[i];

		if (isBrainPinValid(sentPin)) {
			efiSetPadMode("SENT", sentPin, SENT_INPUT_AF);

			icuStart(&SENT_ICU_UNIT, &icucfg_in1);
			icuStartCapture(&SENT_ICU_UNIT);
			icuEnableNotifications(&SENT_ICU_UNIT);
		}
	}
}

void stopSent()
{
	for (int i = 0; i < SENT_INPUT_COUNT; i++) {
		brain_input_pin_e sentPin = activeConfiguration.sentInputPins[i];

		if (isBrainPinValid(sentPin)) {
			icuDisableNotifications(&SENT_ICU_UNIT);
			icuStopCapture(&SENT_ICU_UNIT);
			icuStop(&SENT_ICU_UNIT);

			efiSetPadUnused(sentPin);
		}
	}
}

#endif /* HAL_USE_ICU */

#endif /* EFI_PROD_CODE */
