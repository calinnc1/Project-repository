/*
 * EcuM.c
 *
 *  Created on: Oct 10, 2022
 *      Author: cosmin.marcu
 */

#include "EcuM.h"
#include "Os_task.h"
#include "BswM.h"

void EcuM_StartUp_Two()
{
	(void)HAL_Init();
	BswM_Init();
}

int EcuM_Init(void)
{

	Os_Task_StartUp();

	/* Start Scheduler */
	Os_Start();

	return 0;
}
