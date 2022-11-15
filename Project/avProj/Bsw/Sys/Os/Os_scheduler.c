/*
 * Os_scheduler.c
 *
 *  Created on: Apr 26, 2020
 *      Author: Sudeep Chandrasekaran
 */
#include <Os_scheduler.h>
#include <stdint.h>
#include <stdbool.h>

#define NUM_OF_THREADS  6

/// Task control block, implemented as a linked list to point to the
/// TCB of the next task.
struct tcb{
  int32_t    *stackPt;
  struct tcb *nextPt;
};
/// Define tcb_t datatype
typedef struct tcb tcb_t;
/// Define an array to store TCB's for the tasks.
tcb_t tcbs[NUM_OF_THREADS];
/// Points to the TCB of the currently active task
tcb_t *pCurntTcb;


#define STACKSIZE       200
/// Define stack for each task. Node that the processor expects the stacks
/// to be ended on word boundaries.
int32_t TCB_STACK[NUM_OF_THREADS][STACKSIZE];

volatile uint32_t Os_Task5ms_0_cnt = 0;
volatile uint32_t task5ms_cnt = 0;
volatile uint32_t Os_Task10ms_0_cnt = 0;
volatile uint32_t task10ms_cnt = 0;
volatile uint32_t Os_Task20ms_0_cnt = 0;
volatile uint32_t task20ms_cnt = 0;
volatile uint32_t Os_Task50ms_0_cnt = 0;
volatile uint32_t task50ms_cnt = 0;
volatile uint32_t Os_Task100ms_0_cnt = 0;
volatile uint32_t task100ms_cnt = 0;
volatile uint32_t Os_Task500ms_0_cnt = 0;
volatile uint32_t task500ms_cnt = 0;

__attribute__((naked)) void SysTick_Handler(void)
{
	/// STEP 1 - SAVE THE CURRENT TASK CONTEXT

	/// At this point the processor has already pushed PSR, PC, LR, R12, R3, R2, R1 and R0
	/// onto the stack. We need to push the rest(i.e R4, R5, R6, R7, R8, R9, R10 & R11) to save the
	/// context of the current task.
	/// Disable interrupts
    __asm("CPSID   I");
    /// Push registers R4 to R7
    __asm("PUSH    {R4-R7}");
    /// Push registers R8-R11
    __asm("MOV     R4, R8");
    __asm("MOV     R5, R9");
    __asm("MOV     R6, R10");
    __asm("MOV     R7, R11");
    __asm("PUSH    {R4-R7}");
    /// Load R0 with the address of pCurntTcb
    __asm("LDR     R0, =pCurntTcb");
    /// Load R1 with the content of pCurntTcb(i.e post this, R1 will contain the address of current TCB).
    __asm("LDR     R1, [R0]");
    /// Move the SP value to R4
    __asm("MOV     R4, SP");
    /// Store the value of the stack pointer(copied in R4) to the current tasks "stackPt" element in its TCB.
    /// This marks an end to saving the context of the current task.
    __asm("STR     R4, [R1]");


    /// STEP 2: LOAD THE NEW TASK CONTEXT FROM ITS STACK TO THE CPU REGISTERS, UPDATE pCurntTcb.

    /// Load the address of the next task TCB onto the R1.
    __asm("LDR     R1, [R1,#4]");
    /// Load the contents of the next tasks stack pointer to pCurntTcb, equivalent to pointing pCurntTcb to
    /// the newer tasks TCB. Remember R1 contains the address of pCurntTcb.
    __asm("STR     R1, [R0]");
    /// Load the newer tasks TCB to the SP using R4.
    __asm("LDR     R4, [R1]");
    __asm("MOV     SP, R4");
    /// Pop registers R8-R11
    __asm("POP     {R4-R7}");
    __asm("MOV     R8, R4");
    __asm("MOV     R9, R5");
    __asm("MOV     R10, R6");
    __asm("MOV     R11, R7");
    /// Pop registers R4-R7
    __asm("POP     {R4-R7}");
    __asm("CPSIE   I ");
    __asm("BX      LR");

}

void Os_Scheduler_Init()
{
	/// Enter critical section
	/// Disable interrupts
	__asm("CPSID   I");
	/// Make the TCB linked list circular
	tcbs[0].nextPt = &tcbs[1];
	tcbs[1].nextPt = &tcbs[2];
	tcbs[2].nextPt = &tcbs[3];
	tcbs[3].nextPt = &tcbs[4];
	tcbs[4].nextPt = &tcbs[5];
	tcbs[5].nextPt = &tcbs[0];

	/// Setup stack for task0

	/// Setup the stack such that it is holding one task context.
	/// Remember it is a descending stack and a context consists of 16 registers.
	tcbs[0].stackPt = &TCB_STACK[0][STACKSIZE-16];
	/// Set the 'T' bit in stacked xPSR to '1' to notify processor
	/// on exception return about the thumb state. V6-m and V7-m cores
	/// can only support thumb state hence this should be always set
	/// to '1'.
	TCB_STACK[0][STACKSIZE-1] = 0x01000000;
	/// Set the stacked PC to point to the task
	TCB_STACK[0][STACKSIZE-2] = (int32_t)(Task5ms_0);


	/// Setup stack for task1

	/// Setup the stack such that it is holding one task context.
	/// Remember it is a descending stack and a context consists of 16 registers.
    tcbs[1].stackPt = &TCB_STACK[1][STACKSIZE-16];
    /// Set the 'T' bit in stacked xPSR to '1' to notify processor
    /// on exception return about the thumb state. V6-m and V7-m cores
    /// can only support thumb state hence this should be always set
    /// to '1'.
    TCB_STACK[1][STACKSIZE-1] = 0x01000000;
    /// Set the stacked PC to point to the task
    TCB_STACK[1][STACKSIZE-2] = (int32_t)(Task10ms_0);


    tcbs[2].stackPt = &TCB_STACK[2][STACKSIZE-16];
    TCB_STACK[2][STACKSIZE-1] = 0x01000000;
    TCB_STACK[2][STACKSIZE-2] = (int32_t)(Task20ms_0);

    tcbs[3].stackPt = &TCB_STACK[3][STACKSIZE-16];
    TCB_STACK[3][STACKSIZE-1] = 0x01000000;
    TCB_STACK[3][STACKSIZE-2] = (int32_t)(Task50ms_0);

    tcbs[4].stackPt = &TCB_STACK[4][STACKSIZE-16];
    TCB_STACK[4][STACKSIZE-1] = 0x01000000;
    TCB_STACK[4][STACKSIZE-2] = (int32_t)(Task100ms_0);

    tcbs[5].stackPt = &TCB_STACK[5][STACKSIZE-16];
    TCB_STACK[5][STACKSIZE-1] = 0x01000000;
    TCB_STACK[5][STACKSIZE-2] = (int32_t)(Task500ms_0);

    /// Make current tcb pointer point to task0
    pCurntTcb = &tcbs[0];
    /// Enable interrupts
    __asm("CPSIE   I ");
}


__attribute__((naked)) void Os_Scheduler_Start(void)
{
    /// R0 contains the address of currentPt
    __asm("LDR     R0, =pCurntTcb");
    /// R2 contains the address in currentPt(value of currentPt)
    __asm("LDR     R2, [R0]");
    /// Load the SP reg with the stacked SP value
    __asm("LDR     R4, [R2]");
    __asm("MOV     SP, R4");
    /// Pop registers R8-R11(user saved context)
    __asm("POP     {R4-R7}");
    __asm("MOV     R8, R4");
    __asm("MOV     R9, R5");
    __asm("MOV     R10, R6");
    __asm("MOV     R11, R7");
    /// Pop registers R4-R7(user saved context)
    __asm("POP     {R4-R7}");
    ///  Start poping the stacked exception frame.
    __asm("POP     {R0-R3}");
    __asm("POP     {R4}");
    __asm("MOV     R12, R4");
    /// Skip the saved LR
    __asm("ADD     SP,SP,#4");
    /// POP the saved PC into LR via R4, We do this to jump into the
    /// first task when we execute the branch instruction to exit this routine.
    __asm("POP     {R4}");
    __asm("MOV     LR, R4");
    __asm("ADD     SP,SP,#4");
    /// Enable interrupts
    __asm("CPSIE   I ");
    __asm("BX      LR");
}

void Os_Task_StartUp_0()
{
	Os_Task_StartUp();
}

volatile void Task5ms_0()
{
    while(1)
    {
    	while(task5ms_cnt == tim3_5count)
    	{

    	}
   		Os_Task5ms_0_cnt++;
    	task5ms_cnt = tim3_5count;

    	Os_Task_5ms();
    }
}

volatile void Task10ms_0()
{
    while(1)
    {
    	while(task10ms_cnt == tim3_10count)
    	{

    	}
   		Os_Task10ms_0_cnt++;
    	task10ms_cnt = tim3_10count;

    	Os_Task_10ms();
    }
}

volatile void Task20ms_0()
{
    while(1)
    {
    	while(task20ms_cnt == tim3_20count)
    	{

    	}
   		Os_Task20ms_0_cnt++;
    	task20ms_cnt = tim3_20count;

    	Os_Task_20ms();
    }
}


volatile void Task50ms_0()
{
    while(1)
    {
    	while(task50ms_cnt == tim3_50count)
    	{

    	}
   		Os_Task50ms_0_cnt++;
    	task50ms_cnt = tim3_50count;

    	Os_Task_50ms();
    }
}


volatile void Task100ms_0()
{
    while(1)
    {
    	while(task100ms_cnt == tim3_100count)
    	{

    	}
   		Os_Task100ms_0_cnt++;
    	task100ms_cnt = tim3_100count;

    	Os_Task_100ms();
    }
}


volatile void Task500ms_0()
{
    while(1)
    {
    	while(task500ms_cnt == tim3_500count)
    	{

    	}
   		Os_Task500ms_0_cnt++;
    	task500ms_cnt = tim3_500count;

    	Os_Task_500ms();
    }
}
