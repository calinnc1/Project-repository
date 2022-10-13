/*
 * Rte_Bsw_Int.c
 *
 *  Created on: Oct 10, 2022
 *      Author: cosmin.marcu
 */

#include "avProj_Config.h"
#include "Rte_Bsw_Int.h"
#include "LED.h"

uint8_t ButtonState = 0u;

void Rte_Trigger_Bsw_Int_ButtonEvent(void)
{
	/* Notify apps */
	if(ButtonState == 0u)
	{
		ButtonState = 1u;
	}
	else
	{
		ButtonState = 0u;
	}
}

void Rte_Read_ButtonState(uint8_t *state)
{
	*state = ButtonState;
}

void Rte_Switch_LEDState()
{
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
}

void Rte_Call_Asw_Main(void)
{
	LED_Main();
}
