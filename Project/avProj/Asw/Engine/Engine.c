/**
  * @file	Engine.c
  * @author	cosmin.marcu
  * @date	Nov 4, 2022
  * @brief
  */

/* INCLUDES: */
#include "Engine.h"
#include "Rte_Engine.h"

/* DEFINES: */

/* TYPES: */

/* VARIABLES: */
static boolean g_Engine_InitDone_b = FALSE;							///< Module initialization flag
uint8 g_Remote_Control_Status_D0_u8 = 0;
uint8 g_Remote_Control_Status_D1_u8 = 0;
uint8 g_Remote_Control_Status_D2_u8 = 0;
uint8 g_Remote_Control_Status_D3_u8 = 0;

/* CONSTANTS: */

/* FUNCTIONS PROTOTYPES: */

/* STATIC FUNCTIONS: */

/* PUBLIC FUNCTIONS: */
/**
  * @brief	Engine module initialization function
  * @return	None
  */
void Engine_Init(void)
{

	/* Set initialization flag to done */
	g_Engine_InitDone_b = TRUE;
}

/**
  * @brief	Engine module main function (runs in task)
  * @return	None
  */
void Engine_MainFunction(void)
{
	/* Check if initialization is done */
	if(TRUE == g_Engine_InitDone_b)
	{
		/* Read adc */
		Rte_Read_Remote_Channel0(&g_Remote_Control_Status_D0_u8);
		Rte_Read_Remote_Channel1(&g_Remote_Control_Status_D1_u8);
		Rte_Read_Remote_Channel2(&g_Remote_Control_Status_D2_u8);
		Rte_Read_Remote_Channel3(&g_Remote_Control_Status_D3_u8);

		/* Write on DC motor */

	}
}
/* END OF FILE */
