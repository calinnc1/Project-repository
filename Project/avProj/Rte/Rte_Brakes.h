/**
  * @file	Rte_Brakes.h
  * @author	cosmin.marcu
  * @date	Nov 4, 2022
  * @brief
  */

#ifndef RTE_RTE_BRAKES_H_
#define RTE_RTE_BRAKES_H_

#include "Rte.h"

#define Rte_Read_ADC_AN0_Voltage_u16(voltage)					Rte_Read_AN0_Voltage_u16(voltage)
#define Rte_Read_Ultrasonic_Distance_f32(distance)				Rte_Read_Cdd_Ultrasonic_Distance_f32(distance)
#define Rte_Write_Autobrakes_State_b(state)						Rte_Write_DIO_Autobrakes_State_b(state)
#define Rte_Read_NvM_Brakes_Block(data)							Rte_Read_NvM_Block(RTE_NVM_RAM_BLOCK_ID_BRAKES_E, data)
#define Rte_Write_NvM_Brakes_Block(data)						Rte_Write_NvM_Block(RTE_NVM_RAM_BLOCK_ID_BRAKES_E, data)

#define Rte_Write_Brakes_Collission_Status                      Rte_Write_g_CollisionWarning_Status
#define Rte_Read_ADC_AN2_Voltage_u16(voltage)					Rte_Read_AN2_Voltage_u16(voltage)

#endif /* RTE_RTE_BRAKES_H_ */
