/**
  * @file	Os_scheduler.c
  * @author	cosmin.marcu
  * @date	Nov 22, 2022
  * @brief	OS scheduler header file
  */

#ifndef BSW_SYS_OS_OS_SCHEDULER_H_
#define BSW_SYS_OS_OS_SCHEDULER_H_

#include "stm32f3xx_hal.h"
#include "Os_task.h"
#include "Platform_Types.h"

__attribute__((naked))void Os_Scheduler_Start(void);

void Os_Scheduler_Init();

#endif /* BSW_SYS_OS_OS_SCHEDULER_H_ */
