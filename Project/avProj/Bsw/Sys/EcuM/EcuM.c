/*
 * EcuM.c
 *
 *  Created on: Oct 10, 2022
 *      Author: cosmin.marcu
 */

#include "EcuM.h"
#include "BswM.h"
#include "Rte_Bsw_Int.h"

int EcuM_main(void)
{
	(void)HAL_Init();
	BswM_Init();

	/* Start Scheduler */
	Os_Scheduler();

	return 0;
}
