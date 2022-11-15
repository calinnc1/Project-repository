/**
  * @file	Steering.c
  * @author	cosmin.marcu
  * @date	Nov 4, 2022
  * @brief
  */

/* INCLUDES: */
#include "Steering.h"
#include "Rte_Steering.h"

/* DEFINES: */

/* TYPES: */

/* VARIABLES: */
static boolean g_Steering_InitDone_b = FALSE;							///< Module initialization flag

/* CONSTANTS: */

/* FUNCTIONS PROTOTYPES: */

/* STATIC FUNCTIONS: */

/* PUBLIC FUNCTIONS: */
/**
  * @brief	Steering module initialization function
  * @return	None
  */
void Steering_Init(void)
{

	/* Set initialization flag to done */
	g_Steering_InitDone_b = TRUE;
}

/**
  * @brief	Steering module main function (runs in task)
  * @return	None
  */
void Steering_MainFunction(void)
{
	/* Check if initialization is done */
	if(TRUE == g_Steering_InitDone_b)
	{

	}
}
/* END OF FILE */
