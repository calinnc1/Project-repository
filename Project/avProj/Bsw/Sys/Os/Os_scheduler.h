/*
 * Os_scheduler.h
 *
 *  Created on: Oct 14, 2022
 *      Author: cosmin.marcu
 */

#ifndef BSW_SYS_OS_OS_SCHEDULER_H_
#define BSW_SYS_OS_OS_SCHEDULER_H_

#include "stm32f3xx_hal.h"
#include "Os_task.h"

__attribute__((naked))void Os_Scheduler_Start(void);

void Os_Scheduler_Init();

#endif /* BSW_SYS_OS_OS_SCHEDULER_H_ */
