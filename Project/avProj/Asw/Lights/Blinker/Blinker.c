/**
  * @file	Blinker.c
  * @author	cosmin.marcu
  * @date	Nov 15, 2022
  * @brief
  */

/* INCLUDES: */
#include "Blinker.h"
#include "Rte_Blinker.h"

/* DEFINES: */

/* TYPES: */

/* VARIABLES: */
static boolean g_Blinker_InitDone_b = FALSE;							///< Module initialization flag

/* CONSTANTS: */

/* FUNCTIONS PROTOTYPES: */

/* STATIC FUNCTIONS: */

/* PUBLIC FUNCTIONS: */
/**
  * @brief	Blinker module initialization function
  * @return	None
  */
void Blinker_Init(void)
{

	/* Set initialization flag to done */
	g_Blinker_InitDone_b = TRUE;
}

/**
  * @brief	Blinker module main function (runs in task)
  * @return	None
  */
void Blinker_MainFunction(void)
{
	/* Check if initialization is done */
	if(TRUE == g_Blinker_InitDone_b)
	{

	}
}
/* END OF FILE */
