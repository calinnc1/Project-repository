/*
 * LED.c
 *
 *  Created on: Oct 10, 2022
 *      Author: cosmin.marcu
 */


#include "LED.h"
#include "Rte_Bsw_Int.h"
#include "stm32f3xx_hal.h"

static uint8_t ButtonState = 0u;

void LED_Main(void)
{
	//HAL_Delay(500); //TODO: remove this when tasks are available
	Rte_Read_ButtonState(&ButtonState);
	if(ButtonState == 1u)
	{
		Rte_Switch_LEDState();
	}
}
