/**
  * @file	InteriorLights.c
  * @author	cosmin.marcu
  * @date	Nov 15, 2022
  * @brief
  */

/* INCLUDES: */
#include "InteriorLights.h"
#include "Rte_InteriorLights.h"

/* DEFINES: */

/* TYPES: */

/* VARIABLES: */
static boolean g_InteriorLights_InitDone_b = FALSE;							///< Module initialization flag

/* CONSTANTS: */

/* FUNCTIONS PROTOTYPES: */

/* STATIC FUNCTIONS: */

/* PUBLIC FUNCTIONS: */
/**
  * @brief	InteriorLights module initialization function
  * @return	None
  */
void InteriorLights_Init(void)
{

	/* Set initialization flag to done */
	g_InteriorLights_InitDone_b = TRUE;
}

/**
  * @brief	InteriorLights module main function (runs in task)
  * @return	None
  */
void InteriorLights_MainFunction(void)
{
	/* Check if initialization is done */
	if(TRUE == g_InteriorLights_InitDone_b)
	{

	}
}
/* END OF FILE */
