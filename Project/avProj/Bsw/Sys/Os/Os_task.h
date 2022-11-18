/*
 * Os_task.h
 *
 *  Created on: Oct 14, 2022
 *      Author: cosmin.marcu
 */

#ifndef BSW_SYS_OS_OS_TASK_H_
#define BSW_SYS_OS_OS_TASK_H_

#define TASK_FCT(x) void Os_Task_ ## x
#define TASK(x)	TASK_FCT(x)

void Os_Task_Master(void);
void Os_Task_5ms(void);
void Os_Task_10ms(void);
void Os_Task_20ms(void);
void Os_Task_50ms(void);
void Os_Task_100ms(void);
void Os_Task_500ms(void);

#endif /* BSW_SYS_OS_OS_TASK_H_ */
