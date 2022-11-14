/*
 * premptive_scheduler.h
 *
 *  Created on: Apr 26, 2020
 *      Author: sudeep_subi
 */

#ifndef INC_PREMPTIVE_SCHEDULER_H_
#define INC_PREMPTIVE_SCHEDULER_H_

#include "stm32f3xx_hal.h"
#include "Rte_Bsw_Int.h"
#include "Os_task.h"
extern uint32_t tim3_5count;
extern uint32_t tim3_10count;
extern uint32_t tim3_20count;
extern uint32_t tim3_50count;
extern uint32_t tim3_100count;
extern uint32_t tim3_500count;

__attribute__((naked))void Os_Scheduler_Start(void);
void Os_Task_StartUp_0();
void Os_Scheduler_Init();
volatile void Task5ms_0();
volatile void Task10ms_0();
volatile void Task20ms_0();
volatile void Task50ms_0();
volatile void Task100ms_0();
volatile void Task500ms_0();

#endif /* INC_PREMPTIVE_SCHEDULER_H_ */
