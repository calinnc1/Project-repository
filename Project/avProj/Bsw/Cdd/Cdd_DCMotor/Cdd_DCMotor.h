/**
  * @file	Cdd_DCMotor.h
  * @author	cosmin.marcu
  * @date	Jul 20, 2023
  * @brief
  */

#ifndef BSW_CDD_CDD_DCMOTOR_CDD_DCMOTOR_H_
#define BSW_CDD_CDD_DCMOTOR_CDD_DCMOTOR_H_

#include "stm32f3xx_hal.h"
#include "Platform_Types.h"
#include "avProj_Config.h"

extern void Cdd_DCMotor_Init(void);
extern void Cdd_DCMotor_Driver_Init(void);
extern void Cdd_DCMotor_MainFunction(void);

extern void DC_MOTOR_Init(uint8 au8_MOTOR_Instance);
extern void DC_MOTOR_Start(uint8 au8_MOTOR_Instance, uint8 au8_DIR, uint8 au8_SPEED);
extern void DC_MOTOR_Set_Speed(uint8 au8_MOTOR_Instance, uint8 au8_SPEED);
extern void DC_MOTOR_Set_Dir(uint8 au8_MOTOR_Instance, uint8 au8_DIR);
extern void DC_MOTOR_Stop(uint8 au8_MOTOR_Instance);
extern uint32 DC_MOTOR_Get_MaxFreq(uint8 au8_MOTOR_Instance);

#endif /* BSW_CDD_CDD_DCMOTOR_CDD_DCMOTOR_H_ */
