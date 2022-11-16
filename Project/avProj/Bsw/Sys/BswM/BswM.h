/*
 * BswM.h
 *
 *  Created on: Oct 10, 2022
 *      Author: cosmin.marcu
 */

#ifndef BSW_SYS_BSWM_BSWM_H_
#define BSW_SYS_BSWM_BSWM_H_

#include "stm32f3xx_hal.h"
#include "avProj_Config.h"

#include "Gpt.h"
#include "Tm.h"
void DMA1_ReceiveComplete_Callback(void);
void DMA1_TransmitComplete_Callback(void);

extern void BswM_Init(void);
extern void BswM_MainFunction(void);

#endif /* BSW_SYS_BSWM_BSWM_H_ */
