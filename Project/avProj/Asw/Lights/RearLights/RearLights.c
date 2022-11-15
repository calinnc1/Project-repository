/**
  * @file	RearLights.c
  * @author	cosmin.marcu
  * @date	Nov 15, 2022
  * @brief
  */

/* INCLUDES: */
#include "RearLights.h"
#include "Rte_RearLights.h"

/* DEFINES: */

/* TYPES: */

/* VARIABLES: */
static boolean g_RearLights_InitDone_b = FALSE;							///< Module initialization flag

/* CONSTANTS: */

/* FUNCTIONS PROTOTYPES: */

/* STATIC FUNCTIONS: */

/* PUBLIC FUNCTIONS: */
/**
  * @brief	RearLights module initialization function
  * @return	None
  */
void RearLights_Init(void)
{

	/* Set initialization flag to done */
	g_RearLights_InitDone_b = TRUE;
}

/**
  * @brief	RearLights module main function (runs in task)
  * @return	None
  */
void RearLights_MainFunction(void)
{
	/* Check if initialization is done */
	if(TRUE == g_RearLights_InitDone_b)
	{

	}
}
/* END OF FILE */
