/**
  * @file	Rte_Blinker.h
  * @author	cosmin.marcu
  * @date	Nov 15, 2022
  * @brief
  */

#ifndef RTE_RTE_BLINKER_H_
#define RTE_RTE_BLINKER_H_

#include "Rte.h"

#define Rte_Read_Blinker_Autobrakes_Status                      Rte_Read_DIO_Autobrakes_State_b

#define Rte_Write_Left_Blinker_Autobrakes_Status                Rte_Write_PC_2
#define Rte_Write_Right_Blinker_Autobrakes_Status               Rte_Write_PC_3


#endif /* RTE_RTE_BLINKER_H_ */
