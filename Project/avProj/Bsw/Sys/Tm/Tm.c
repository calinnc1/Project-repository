/*
 * Tm.c
 *
 *  Created on: Oct 12, 2022
 *      Author: cosmin.marcu
 */

#include "Tm.h"
#include "Gpt.h"

void Tm_Init(void)
{
	Gpt_TIM3_Start_IT();
}
