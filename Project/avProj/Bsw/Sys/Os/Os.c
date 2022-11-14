/*
 * Os.c
 *
 *  Created on: Oct 12, 2022
 *      Author: cosmin.marcu
 */


#include "Os.h"
#include "Rte_Bsw_Int.h"
#include "Os_scheduler.h"
#include "Os_task.h"


void Os_Start()
{
	Os_Task_StartUp_0();
	Os_Scheduler_Init();
	Os_Scheduler_Start();

	while(1)
	{

	}
}
