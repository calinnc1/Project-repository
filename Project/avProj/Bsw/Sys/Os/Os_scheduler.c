/**
  * @file	Os_scheduler.c
  * @author	cosmin.marcu
  * @date	Nov 22, 2022
  * @brief	OS scheduler source file
  */
#include "Os_scheduler.h"

#define OS_NUM_TASKS  				5u
#define OS_TASK_STACKSIZE       	200u
#define OS_BASETIMER_COUNT_MAX		9999u
#define OS_TASK_XPSR_TBIT_U32		0x01000000
#define OS_VAR						static volatile
#define OS_TASK_FUNC				static volatile
#define OS_DWT						0u

#define OS_TASK_INIT_ID_U8			0u
#define OS_TASK_10MS_ID_U8			1u
#define OS_TASK_50MS_ID_U8			2u
#define OS_TASK_100MS_ID_U8			3u
#define OS_TASK_500MS_ID_U8			4u

#if OS_DWT
  #define KIN1_DWT_CONTROL             (*((volatile uint32_t*)0xE0001000))
    /*!< DWT Control register */
  #define KIN1_DWT_CYCCNTENA_BIT       (1UL<<0)
    /*!< CYCCNTENA bit in DWT_CONTROL register */
  #define KIN1_DWT_CYCCNT              (*((volatile uint32_t*)0xE0001004))
    /*!< DWT Cycle Counter register */
  #define KIN1_DEMCR                   (*((volatile uint32_t*)0xE000EDFC))
    /*!< DEMCR: Debug Exception and Monitor Control Register */
  #define KIN1_TRCENA_BIT              (1UL<<24)
    /*!< Trace enable bit in DEMCR register */

#define KIN1_InitCycleCounter() \
  KIN1_DEMCR |= KIN1_TRCENA_BIT
  /*!< TRCENA: Enable trace and debug block DEMCR (Debug Exception and Monitor Control Register */

#define KIN1_ResetCycleCounter() \
  KIN1_DWT_CYCCNT = 0
  /*!< Reset cycle counter */

#define KIN1_EnableCycleCounter() \
  KIN1_DWT_CONTROL |= KIN1_DWT_CYCCNTENA_BIT
  /*!< Enable cycle counter */

#define KIN1_DisableCycleCounter() \
  KIN1_DWT_CONTROL &= ~KIN1_DWT_CYCCNTENA_BIT
  /*!< Disable cycle counter */

#define KIN1_GetCycleCounter() \
  KIN1_DWT_CYCCNT
  /*!< Read cycle counter register */

#define KIN1_Start() \
	KIN1_InitCycleCounter(); \
	KIN1_ResetCycleCounter(); \
	KIN1_EnableCycleCounter();

#define KIN1_Stop(x) \
	x = (float32)KIN1_GetCycleCounter() / 72000.0f; \
	KIN1_DisableCycleCounter();

#endif

#if OS_DWT
	#define OS_TASK_CALL(x, y) \
	KIN1_Start() \
	x; \
	KIN1_Stop(y)
#else
	#define OS_TASK_CALL(x, y) x;
#endif

/**
  * @brief  Task Control Block Structure
  */
struct Os_TaskControlBlock_s
{
  uint32    *stackPt_pu32;
  struct Os_TaskControlBlock_s *nextPt_ps;
};

/**
  * @brief  Task Control Block data type
  */
typedef struct Os_TaskControlBlock_s Os_TaskControlBlock_st;

/**
  * @brief  Task Control Blocks array
  */
Os_TaskControlBlock_st g_Os_TaskBlock_as[OS_NUM_TASKS];

/**
  * @brief  Pointer to current Task Control Block
  */
Os_TaskControlBlock_st *g_Os_CurrentTaskBlock_ps;

/**
  * @brief  OS state data type
  */
typedef enum Os_Scheduler_State_e
{
	OS_STATE_RESET_E 		= 0u,
	OS_STATE_INIT_E			= 1u,
	OS_STATE_NVMREAD_E		= 2u,
	OS_STATE_RUNNING_E		= 3u,
	OS_STATE_SHUTDOWN_E		= 4u,
	OS_STATE_ERROR_E		= 5u
} Os_Scheduler_State_et;

/**
  * @brief  Tasks stacks definition array
  */
uint32 g_Os_TaskStack_aau32[OS_NUM_TASKS][OS_TASK_STACKSIZE];

OS_VAR uint32 g_Os_BaseTimerISR_count_u32 = 0u;
OS_VAR uint32 g_Os_5msTimerISR_count_u32 = 0u;
OS_VAR uint32 g_Os_10msTimerISR_count_u32 = 0u;
OS_VAR uint32 g_Os_50msTimerISR_count_u32 = 0u;
OS_VAR uint32 g_Os_100msTimerISR_count_u32 = 0u;
OS_VAR uint32 g_Os_500msTimerISR_count_u32 = 0u;

OS_VAR uint32 Os_Task5ms_0_cnt = 0;
OS_VAR uint32 g_Os_Task5ms_count_u32 = 0;
OS_VAR uint32 Os_Task10ms_0_cnt = 0;
OS_VAR uint32 g_Os_Task10ms_count_u32 = 0;
OS_VAR uint32 Os_Task50ms_0_cnt = 0;
OS_VAR uint32 g_Os_Task50ms_count_u32 = 0;
OS_VAR uint32 Os_Task100ms_0_cnt = 0;
OS_VAR uint32 g_Os_Task100ms_count_u32 = 0;
OS_VAR uint32 Os_Task500ms_0_cnt = 0;
OS_VAR uint32 g_Os_Task500ms_count_u32 = 0;

OS_VAR Os_Scheduler_State_et g_OS_State_e = OS_STATE_RESET_E;

/* OS tasks duration measurement variables [ms]
 * Precondition: OS_DWR must be 1
 */
OS_VAR float32 g_Os_dwt_Master_f32 = 0.0f;
OS_VAR float32 g_Os_dwt_10ms_f32 = 0.0f;
OS_VAR float32 g_Os_dwt_50ms_f32 = 0.0f;
OS_VAR float32 g_Os_dwt_100ms_f32 = 0.0f;
OS_VAR float32 g_Os_dwt_500ms_f32 = 0.0f;

OS_TASK_FUNC void Os_Scheduler_TaskMaster_0(void);
OS_TASK_FUNC void Os_Scheduler_Task10ms_0(void);
OS_TASK_FUNC void Os_Scheduler_Task50ms_0(void);
OS_TASK_FUNC void Os_Scheduler_Task100ms_0(void);
OS_TASK_FUNC void Os_Scheduler_Task500ms_0(void);


/**
  * @brief  SysTick IRQ Handler
  * @return None
  */
void SysTick_Handler(void)
{
	/* Increment general counter */
	HAL_IncTick();
	/* Reset counters if base counter reached maximum value */
	if(g_Os_BaseTimerISR_count_u32 == OS_BASETIMER_COUNT_MAX)
	{
		g_Os_BaseTimerISR_count_u32 = 0u;
		g_Os_5msTimerISR_count_u32 = 0u;
		g_Os_10msTimerISR_count_u32 = 0u;
		g_Os_50msTimerISR_count_u32 = 0u;
		g_Os_100msTimerISR_count_u32 = 0u;
		g_Os_500msTimerISR_count_u32 = 0u;
	}
	else
	{
		/* Increment base counter */
		g_Os_BaseTimerISR_count_u32++;
	}

	/* Check for 5ms condition */
	if((g_Os_BaseTimerISR_count_u32 % 5) == 0u)
	{
		/* Increment 5ms counter */
		g_Os_5msTimerISR_count_u32++;
	}

	/* Check for 10ms condition */
	if((g_Os_BaseTimerISR_count_u32 % 10) == 0u)
	{
		/* Increment 10ms counter */
		g_Os_10msTimerISR_count_u32++;
	}

	/* Check for 50ms condition */
	if((g_Os_BaseTimerISR_count_u32 % 50) == 0u)
	{
		/* Increment 50ms counter */
		g_Os_50msTimerISR_count_u32++;
	}

	/* Check for 100ms condition */
	if((g_Os_BaseTimerISR_count_u32 % 100) == 0u)
	{
		/* Increment 100ms counter */
		g_Os_100msTimerISR_count_u32++;
	}

	/* Check for 500ms condition */
	if((g_Os_BaseTimerISR_count_u32 % 500) == 0u)
	{
		/* Increment 500ms counter */
		g_Os_500msTimerISR_count_u32++;
	}

	/* Call PendSV_Handler for context switch */
	if(OS_STATE_RUNNING_E == g_OS_State_e)
	{
		SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
	}
}

/**
  * @brief  PendSV IRQ handler
  * @return None
  */
__attribute__((naked)) void PendSV_Handler(void)
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
    __asm("LDR     R0, =g_Os_CurrentTaskBlock_ps");
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

/**
  * @brief  OS Scheduler initialization function
  * @return None
  */
void Os_Scheduler_Init()
{
	/* Enter critical section: Disable interrupts */
	__asm("CPSID   I");
	/* Make the Task Control Block linked list circular */
	g_Os_TaskBlock_as[OS_TASK_INIT_ID_U8].nextPt_ps = &g_Os_TaskBlock_as[OS_TASK_10MS_ID_U8];
	g_Os_TaskBlock_as[OS_TASK_10MS_ID_U8].nextPt_ps = &g_Os_TaskBlock_as[OS_TASK_50MS_ID_U8];
	g_Os_TaskBlock_as[OS_TASK_50MS_ID_U8].nextPt_ps = &g_Os_TaskBlock_as[OS_TASK_100MS_ID_U8];
	g_Os_TaskBlock_as[OS_TASK_100MS_ID_U8].nextPt_ps = &g_Os_TaskBlock_as[OS_TASK_500MS_ID_U8];
	g_Os_TaskBlock_as[OS_TASK_500MS_ID_U8].nextPt_ps = &g_Os_TaskBlock_as[OS_TASK_INIT_ID_U8];
	/* Setup stack for initialization (master) task */
	g_Os_TaskBlock_as[OS_TASK_INIT_ID_U8].stackPt_pu32 = &g_Os_TaskStack_aau32[OS_TASK_INIT_ID_U8][OS_TASK_STACKSIZE-16];
	g_Os_TaskStack_aau32[OS_TASK_INIT_ID_U8][OS_TASK_STACKSIZE-1] = OS_TASK_XPSR_TBIT_U32;
	g_Os_TaskStack_aau32[OS_TASK_INIT_ID_U8][OS_TASK_STACKSIZE-2] = (uint32)(Os_Scheduler_TaskMaster_0);
	/* Setup stack for 10ms task */
    g_Os_TaskBlock_as[OS_TASK_10MS_ID_U8].stackPt_pu32 = &g_Os_TaskStack_aau32[OS_TASK_10MS_ID_U8][OS_TASK_STACKSIZE-16];
    g_Os_TaskStack_aau32[OS_TASK_10MS_ID_U8][OS_TASK_STACKSIZE-1] = OS_TASK_XPSR_TBIT_U32;
    g_Os_TaskStack_aau32[OS_TASK_10MS_ID_U8][OS_TASK_STACKSIZE-2] = (uint32)(Os_Scheduler_Task10ms_0);
	/* Setup stack for 50ms task */
    g_Os_TaskBlock_as[OS_TASK_50MS_ID_U8].stackPt_pu32 = &g_Os_TaskStack_aau32[OS_TASK_50MS_ID_U8][OS_TASK_STACKSIZE-16];
    g_Os_TaskStack_aau32[OS_TASK_50MS_ID_U8][OS_TASK_STACKSIZE-1] = OS_TASK_XPSR_TBIT_U32;
    g_Os_TaskStack_aau32[OS_TASK_50MS_ID_U8][OS_TASK_STACKSIZE-2] = (uint32)(Os_Scheduler_Task50ms_0);
	/* Setup stack for 100ms task */
    g_Os_TaskBlock_as[OS_TASK_100MS_ID_U8].stackPt_pu32 = &g_Os_TaskStack_aau32[OS_TASK_100MS_ID_U8][OS_TASK_STACKSIZE-16];
    g_Os_TaskStack_aau32[OS_TASK_100MS_ID_U8][OS_TASK_STACKSIZE-1] = OS_TASK_XPSR_TBIT_U32;
    g_Os_TaskStack_aau32[OS_TASK_100MS_ID_U8][OS_TASK_STACKSIZE-2] = (uint32)(Os_Scheduler_Task100ms_0);
	/* Setup stack for 500ms task */
    g_Os_TaskBlock_as[OS_TASK_500MS_ID_U8].stackPt_pu32 = &g_Os_TaskStack_aau32[OS_TASK_500MS_ID_U8][OS_TASK_STACKSIZE-16];
    g_Os_TaskStack_aau32[OS_TASK_500MS_ID_U8][OS_TASK_STACKSIZE-1] = OS_TASK_XPSR_TBIT_U32;
    g_Os_TaskStack_aau32[OS_TASK_500MS_ID_U8][OS_TASK_STACKSIZE-2] = (uint32)(Os_Scheduler_Task500ms_0);
    /* Set the current task control block to point to init task */
    g_Os_CurrentTaskBlock_ps = &g_Os_TaskBlock_as[OS_TASK_INIT_ID_U8];
    /* Leave critical section: Enable interrupts */
    __asm("CPSIE   I ");
}

/**
  * @brief  OS Scheduler start function
  * @return None
  */
__attribute__((naked)) void Os_Scheduler_Start(void)
{
    /// R0 contains the address of currentPt
    __asm("LDR     R0, =g_Os_CurrentTaskBlock_ps");
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

/**
  * @brief  Initialization task
  * @return None
  */
OS_TASK_FUNC void Os_Scheduler_TaskMaster_0(void)
{
    while(1)
    {
    	/* Wait for context switch of master task */
    	while(g_Os_Task5ms_count_u32 == g_Os_5msTimerISR_count_u32)
    	{
    	}
    	Os_Task5ms_0_cnt++;
    	g_Os_Task5ms_count_u32 = g_Os_5msTimerISR_count_u32;

    	/* Check Os state */
    	switch (g_OS_State_e)
    	{
    		case OS_STATE_RESET_E:
    		{
    			g_OS_State_e = OS_STATE_INIT_E;
    		} break;
    		case OS_STATE_INIT_E:
    		{
    			OS_TASK_CALL(Os_Task_Master(), g_Os_dwt_Master_f32);
    			g_OS_State_e = OS_STATE_NVMREAD_E;
    		} break;
    		case OS_STATE_NVMREAD_E:
    		{
    			/* Todo: preform readall here */
    			//g_OS_State_e = OS_STATE_RUNNING_E;
    		}
    		case OS_STATE_RUNNING_E:
    		{
    			/* TODO: add task activate/suspend here */
    			g_OS_State_e = OS_STATE_RUNNING_E;
    		} break;
    		case OS_STATE_SHUTDOWN_E:
    		{
    			/* TODO: add shutdown procedure here */
    		} break;
    		case OS_STATE_ERROR_E:
    		{
    			/* NvM write all, write error */
    		} break;
    		default:
    		{

    		} break;
    	}
    }
}

/**
  * @brief  Periodic 10ms task
  * @return None
  */
OS_TASK_FUNC void Os_Scheduler_Task10ms_0(void)
{
    while(1)
    {
    	if(OS_STATE_RUNNING_E == g_OS_State_e)
    	{
			while(g_Os_Task10ms_count_u32 == g_Os_10msTimerISR_count_u32)
			{

			}
			Os_Task10ms_0_cnt++;
			g_Os_Task10ms_count_u32 = g_Os_10msTimerISR_count_u32;

			OS_TASK_CALL(Os_Task_10ms(), g_Os_dwt_10ms_f32);
    	}
    	else
    	{
    		g_Os_Task10ms_count_u32 = g_Os_10msTimerISR_count_u32;
    	}
    }
}

/**
  * @brief  Periodic 50ms task
  * @return None
  */
OS_TASK_FUNC void Os_Scheduler_Task50ms_0(void)
{
    while(1)
    {
    	if(OS_STATE_RUNNING_E == g_OS_State_e)
    	{
			while(g_Os_Task50ms_count_u32 == g_Os_50msTimerISR_count_u32)
			{

			}
			Os_Task50ms_0_cnt++;
			g_Os_Task50ms_count_u32 = g_Os_50msTimerISR_count_u32;
			OS_TASK_CALL(Os_Task_50ms(), g_Os_dwt_50ms_f32);
    	}
    	else
    	{
    		g_Os_Task50ms_count_u32 = g_Os_50msTimerISR_count_u32;
    	}
    }
}

/**
  * @brief  Periodic 100ms task
  * @return None
  */
OS_TASK_FUNC void Os_Scheduler_Task100ms_0(void)
{
    while(1)
    {
    	if(OS_STATE_RUNNING_E == g_OS_State_e)
    	{
			while(g_Os_Task100ms_count_u32 == g_Os_100msTimerISR_count_u32)
			{

			}
			Os_Task100ms_0_cnt++;
			g_Os_Task100ms_count_u32 = g_Os_100msTimerISR_count_u32;

			OS_TASK_CALL(Os_Task_100ms(), g_Os_dwt_100ms_f32);
    	}
    	else
    	{
    		g_Os_Task100ms_count_u32 = g_Os_100msTimerISR_count_u32;
    	}
    }
}

/**
  * @brief  Periodic 500ms task
  * @return None
  */
OS_TASK_FUNC void Os_Scheduler_Task500ms_0(void)
{
    while(1)
    {
    	if(OS_STATE_RUNNING_E == g_OS_State_e)
    	{
			while(g_Os_Task500ms_count_u32 == g_Os_500msTimerISR_count_u32)
			{

			}
			Os_Task500ms_0_cnt++;
			g_Os_Task500ms_count_u32 = g_Os_500msTimerISR_count_u32;

			OS_TASK_CALL(Os_Task_500ms(), g_Os_dwt_500ms_f32);
    	}
    	else
    	{
    		g_Os_Task500ms_count_u32 = g_Os_500msTimerISR_count_u32;
    	}
    }
}
