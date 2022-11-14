/**
  * @file	Brakes.c
  * @author	cosmin.marcu
  * @date	Nov 4, 2022
  * @brief
  */

/* INCLUDES: */
#include "Brakes.h"
#include "Rte_Brakes.h"

/* DEFINES: */

/* TYPES: */

/* VARIABLES: */
static boolean Brakes_InitDone_b = FALSE;							///< Module initialization flag

/* CONSTANTS: */

/* FUNCTIONS PROTOTYPES: */

/* STATIC FUNCTIONS: */

/* PUBLIC FUNCTIONS: */
/**
  * @brief	Brakes module initialization function
  * @return	None
  */
void Brakes_Init(void)
{

	/* Set initialization flag to done */
	Brakes_InitDone_b = TRUE;
}

/**
  * @brief	Brakes module main function (runs in task)
  * @return	None
  */
void Brakes_MainFunction(void)
{
	/* Check if initialization is done */
	if(TRUE == Brakes_InitDone_b)
	{

	}
}
/* END OF FILE */
