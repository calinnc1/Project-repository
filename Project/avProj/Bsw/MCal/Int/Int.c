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
	/* Check if interrupt is triggered by PC13 */
	if(GPIO_Pin == BUTTON_Pin)
	{
		/* Check Pin state */
        if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13))
        {
            Rte_Write_PC13_Pin_State(1u);
        }
        else
        {
        	Rte_Write_PC13_Pin_State(0u);
        }
	}
}

