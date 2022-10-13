/*
 * Int.c
 *
 *  Created on: Oct 10, 2022
 *      Author: cosmin.marcu
 */


#include "Int.h"
#include "Rte_Bsw_Int.h"
#include "stm32f3xx_hal.h"
#include "avProj_Config.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == BUTTON_Pin)
	{
		Rte_Trigger_Bsw_Int_ButtonEvent();
	}
}

