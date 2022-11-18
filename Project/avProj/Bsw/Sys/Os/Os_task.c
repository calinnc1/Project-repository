/*
 * Os_task.c
 *
 *  Created on: Oct 14, 2022
 *      Author: cosmin.marcu
 */

#include "Os_task.h"
#include "Rte_Os.h"

TASK(Master)()
{
	Rte_Os_Task_Master();
}

TASK(10ms)()
{
	Rte_Os_Task_10ms();
}

TASK(50ms)()
{
	Rte_Os_Task_50ms();
}

TASK(100ms)()
{
	Rte_Os_Task_100ms();
}

TASK(500ms)()
{
	Rte_Os_Task_500ms();
}

