/*
 * EcuM.c
 *
 *  Created on: Oct 10, 2022
 *      Author: cosmin.marcu
 */

#include "EcuM.h"
#include "Os_task.h"
#include "BswM.h"

void EcuM_StartUp_One()
{
	(void)HAL_Init();
	BswM_Init();
}

void EcuM_StartUp_Two()
{

}

int EcuM_Init(void)
{
	EcuM_StartUp_One();
	/* Start Scheduler */
	Os_Start();

	return 0;
}
