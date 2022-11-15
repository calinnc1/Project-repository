/**
  * @file	Access.c
  * @author	cosmin.marcu
  * @date	Nov 4, 2022
  * @brief
  */

/* INCLUDES: */
#include "Access.h"
#include "Rte_Access.h"

/* DEFINES: */

/* TYPES: */

/* VARIABLES: */
static boolean g_Access_InitDone_b = FALSE;							///< Module initialization flag

/* CONSTANTS: */

/* FUNCTIONS PROTOTYPES: */

/* STATIC FUNCTIONS: */

/* PUBLIC FUNCTIONS: */
/**
  * @brief	Access module initialization function
  * @return	None
  */
void Access_Init(void)
{

	/* Set initialization flag to done */
	g_Access_InitDone_b = TRUE;
}

/**
  * @brief	Access module main function (runs in task)
  * @return	None
  */
void Access_MainFunction(void)
{
	/* Check if initialization is done */
	if(TRUE == g_Access_InitDone_b)
	{

	}
}
/* END OF FILE */
