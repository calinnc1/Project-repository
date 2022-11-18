/*
 * Os.c
 *
 *  Created on: Oct 12, 2022
 *      Author: cosmin.marcu
 */


#include "Os.h"
#include "Os_scheduler.h"

void Os_Start()
{
	Os_Scheduler_Init();
	Os_Scheduler_Start();

	while(1)
	{

	}
}
