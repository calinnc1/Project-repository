/*
 * Rte_Bsw_Int.h
 *
 *  Created on: Oct 10, 2022
 *      Author: cosmin.marcu
 */

#ifndef RTE_RTE_BSW_INT_H_
#define RTE_RTE_BSW_INT_H_
#include "stm32f3xx_hal.h"

extern void Rte_Trigger_Bsw_Int_ButtonEvent(void);
extern void Rte_Read_ButtonState(uint8_t *state);
extern void Rte_Switch_LEDState(void);
extern void Rte_Call_Asw_Main(void);

#endif /* RTE_RTE_BSW_INT_H_ */
