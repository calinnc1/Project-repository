/*
 * Os.c
 *
 *  Created on: Oct 12, 2022
 *      Author: cosmin.marcu
 */


#include "Os.h"
#include "Rte_Bsw_Int.h"

static uint8_t Os_Task_Cnt = 0u;

static void Os_Task_10ms(void);
static void Os_Task_20ms(void);
static void Os_Task_500ms(void);

void Os_Scheduler()
{
	while(1)
	{
		while(Os_Task_Cnt == tim3_count)
		{
			/*wait*/
		}

		Os_Task_Cnt = tim3_count;

		Os_Task_10ms();

		if((Os_Task_Cnt % 2) == 0u)
		{
			Os_Task_20ms();
		}

		if((Os_Task_Cnt % 50) == 0u)
		{
			Os_Task_500ms();
		}
	}
}

void Os_Task_10ms(void)
{

}

void Os_Task_20ms(void)
{
	//Rte_Call_Asw_Main();
}

void Os_Task_500ms(void)
{
	Rte_Call_Asw_Main();
}
