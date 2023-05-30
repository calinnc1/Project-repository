/*
 * Rte_LED.h
 *
 *  Created on: Oct 19, 2022
 *      Author: cosmin.marcu
 */

#ifndef RTE_RTE_LED_H_
#define RTE_RTE_LED_H_
#include "Rte.h"

#define Rte_Switch_LED_State						Rte_Switch_PA5_Pin_State
#define Rte_Read_Button_State						Rte_Read_PC13_Pin_State
#define Rte_Write_Servo_RawPulseWidth_u16(data)		Rte_Cdd_Servo_RawMove(data)
#define Rte_Read_NvM_LED_Block(data)				Rte_Read_NvM_Block(RTE_NVM_RAM_BLOCK_ID_LED_E, data)
#define Rte_Write_NvM_LED_Block(data)				Rte_Write_NvM_Block(RTE_NVM_RAM_BLOCK_ID_LED_E, data)

#endif /* RTE_RTE_LED_H_ */
