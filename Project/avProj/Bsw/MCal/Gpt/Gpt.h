/*
 * Gpt.h
 *
 *  Created on: Oct 12, 2022
 *      Author: cosmin.marcu
 */

#ifndef BSW_MCAL_GPT_GPT_H_
#define BSW_MCAL_GPT_GPT_H_

#include "stm32f3xx_hal.h"

extern void Gpt_Init(void);
extern void Gpt_TIM3_Start_IT(void);
extern void Gpt_TIM3_Stop_IT(void);

#endif /* BSW_MCAL_GPT_GPT_H_ */
