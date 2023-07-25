/**
  * @file	Rte_Engine.h
  * @author	cosmin.marcu
  * @date	Nov 4, 2022
  * @brief
  */

#ifndef RTE_RTE_ENGINE_H_
#define RTE_RTE_ENGINE_H_

#include "Rte.h"

#define Rte_Read_Remote_Channel0                  Rte_Read_Remote_D0
#define Rte_Read_Remote_Channel1                  Rte_Read_Remote_D1
#define Rte_Read_Remote_Channel2                  Rte_Read_Remote_D2
#define Rte_Read_Remote_Channel3                  Rte_Read_Remote_D3

#define Rte_Start_DCMotor                         Rte_Call_DCMotor_Start
#define Rte_Speed_DCMotor                         Rte_Call_DCMotor_Set_Speed
#define Rte_Direction_DCMotor                     Rte_Call_DCMotor_Set_Dir
#define Rte_Stop_DCMotor                          Rte_Call_DCMotor_Stop

#define Rte_Read_ADC_0_Joystick_Voltage_u16	      Rte_Read_AN0_Voltage_u16
#define Rte_Read_ADC_1_Joystick_Voltage_u16       Rte_Read_AN2_Voltage_u16
#define Rte_Engine_Switch_Joystick                Rte_Read_PC6_Pin_State

#define Rte_Read_Ultrasonic				          Rte_Read_Cdd_Ultrasonic_Distance_f32

#endif /* RTE_RTE_ENGINE_H_ */
