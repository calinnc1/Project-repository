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

enum {
	RTE_NVM_RAM_BLOCK_ID_LED_E		= 0u,
	RTE_NVM_RAM_BLOCK_ID_BRAKES_E	= 1u,
	RTE_NVM_RAM_BLOCK_ID_ENGINE_E	= 2u,
	RTE_NVM_RAM_BLOCK_ID_STEERING_E	= 3u,
	RTE_NVM_RAM_BLOCK_ID_ACCESS_E	= 4u,
	RTE_NVM_RAM_BLOCK_ID_LIGHTS_E	= 5u,

	/* LAST NVM RAM block ID */
	RTE_NVM_RAM_BLOCK_ID_MAX_E		= 6u
};

extern void Rte_Init(void);
/* Rte Tasks */
extern void Rte_Task_Master(void);
extern void Rte_Task_10ms(void);
extern void Rte_Task_50ms(void);
extern void Rte_Task_100ms(void);
extern void Rte_Task_500ms(void);
extern void Rte_Task_Shutdown(void);

/* CDD */
extern void Rte_Call_Cdd_Ultrasonic_TriggerMeasurement(void);
extern void Rte_Read_Cdd_Ultrasonic_Distance_f32(float32 *distance);
extern void Rte_Write_PC13_Pin_State(uint8 state);
extern void Rte_Switch_PA5_Pin_State(void);
extern void Rte_Read_PC13_Pin_State(uint8 *state);
extern void Rte_Cdd_Servo_RawMove(uint16 pulse);
extern void Rte_Read_NvM_Block(uint16 blockID, uint8 *data);
extern void Rte_Write_NvM_Block(uint16 blockID, uint8 *data);

extern void Rte_Write_AN0_Voltage_u16(uint16 voltage);
extern void Rte_Read_AN0_Voltage_u16(uint16 *voltage);

extern void Rte_Write_AN2_Voltage_u16(uint16 voltage);
extern void Rte_Read_AN2_Voltage_u16(uint16 *voltage);

extern void Rte_Write_DIO_Autobrakes_State_b(boolean state);

extern void Rte_Read_g_CollisionWarning_Status(uint8 *status);
extern void Rte_Write_g_CollisionWarning_Status(uint8 status);

extern void Rte_Read_DIO_Autobrakes_State_b(boolean *state);
void Rte_Write_PC_2(boolean state);
void Rte_Write_PC_3(boolean state);

void Rte_Read_Remote_D0(uint8 *status);
void Rte_Read_Remote_D1(uint8 *status);
void Rte_Read_Remote_D2(uint8 *status);
void Rte_Read_Remote_D3(uint8 *status);

void Rte_Write_PB_13(boolean state);
void Rte_Write_PB_14(boolean state);
void Rte_Write_PB_15(boolean state);

#endif /* RTE_RTE_H_ */
