/*
 * Rte.h
 *
 *  Created on: Oct 19, 2022
 *      Author: cosmin.marcu
 */

#ifndef RTE_RTE_H_
#define RTE_RTE_H_
#include "stm32f3xx_hal.h"
#include "avProj_Config.h"
#include "Platform_Types.h"

extern void Rte_Init(void);
/* Rte Tasks */
extern void Rte_Task_Master(void);
extern void Rte_Task_10ms(void);
extern void Rte_Task_50ms(void);
extern void Rte_Task_100ms(void);
extern void Rte_Task_500ms(void);

extern void Rte_Write_PC13_Pin_State(uint8 state);
extern void Rte_Switch_PA5_Pin_State(void);
extern void Rte_Read_PC13_Pin_State(uint8 *state);
extern void Rte_Cdd_Servo_RawMove(uint16 pulse);
extern void Rte_Read_NvM_Block_0(uint8 *data);
extern void Rte_Write_AN0_Voltage_u16(uint16 voltage);
extern void Rte_Read_AN0_Voltage_u16(uint16 *voltage);
#endif /* RTE_RTE_H_ */
