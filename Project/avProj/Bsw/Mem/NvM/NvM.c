/**
  * @file	NvM.c
  * @author	cosmin.marcu
  * @date	Nov 16, 2022
  * @brief
  */

/* INCLUDES: */
#include "NvM.h"
#include "Ea.h"

/* DEFINES: */

/* TYPES: */

/* VARIABLES: */
static boolean g_NvM_InitDone_b = FALSE;							///< Module initialization flag

/* CONSTANTS: */

/* FUNCTIONS PROTOTYPES: */

/* STATIC FUNCTIONS: */

/* PUBLIC FUNCTIONS: */
/**
  * @brief	NvM module initialization function
  * @return	None
  */
void NvM_Init(void)
{

	/* Set initialization flag to done */
	g_NvM_InitDone_b = TRUE;
}

/**
  * @brief	NvM module main function (runs in task)
  * @return	None
  */
void NvM_MainFunction(void)
{
	/* Check if initialization is done */
	if(TRUE == g_NvM_InitDone_b)
	{

	}
}

/**
  * @brief	NvM Write block function
  * @param	BlockId		ID of the block to be written
  * @param  NvM_SrcPtr	Pointer to the data to be written
  * @return	None
  */
void NvM_WriteBlock(uint16 BlockId, uint8 *NvM_SrcPtr)
{
	/* Call FRAM block write function */
	Ea_Write(BlockId, NvM_SrcPtr);
}

/**
  * @brief	NvM Read block function
  * @param	BlockId		ID of the block to be read
  * @param  NvM_SrcPtr	Pointer to the data to be read
  * @return	None
  */
void NvM_ReadBlock(uint16 BlockId, uint8 *NvM_SrcPtr)
{
	/* Call FRAM block read function */
	Ea_Read(BlockId, NvM_SrcPtr);
}
/* END OF FILE */
