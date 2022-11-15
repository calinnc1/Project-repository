/**
  * @file	FrontLights.c
  * @author	cosmin.marcu
  * @date	Nov 15, 2022
  * @brief
  */

/* INCLUDES: */
#include "FrontLights.h"
#include "Rte_FrontLights.h"

/* DEFINES: */

/* TYPES: */

/* VARIABLES: */
static boolean g_FrontLights_InitDone_b = FALSE;							///< Module initialization flag

/* CONSTANTS: */

/* FUNCTIONS PROTOTYPES: */

/* STATIC FUNCTIONS: */

/* PUBLIC FUNCTIONS: */
/**
  * @brief	FrontLights module initialization function
  * @return	None
  */
void FrontLights_Init(void)
{

	/* Set initialization flag to done */
	g_FrontLights_InitDone_b = TRUE;
}

/**
  * @brief	FrontLights module main function (runs in task)
  * @return	None
  */
void FrontLights_MainFunction(void)
{
	/* Check if initialization is done */
	if(TRUE == g_FrontLights_InitDone_b)
	{

	}
}
/* END OF FILE */
