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
typedef enum {
	NVM_STATE_INIT 			= 0u,
	NVM_STATE_READY 		= 1u,
	NVM_STATE_READY_READ 	= 2u,
	NVM_STATE_READ 			= 3u,
	NVM_STATE_READALL 		= 4u,
	NVM_STATE_READY_WRITE 	= 5u,
	NVM_STATE_WRITE 		= 6u,
	NVM_STATE_WRITEALL 		= 7u,
	NVM_STATE_SHUTDOWN 		= 8u,
	NVM_STATE_ERROR 		= 9u
}NvM_State_t;

/* VARIABLES: */
static boolean g_NvM_InitDone_b = FALSE;							///< Module initialization flag
static NvM_State_t g_NvM_State_e = NVM_STATE_INIT;					///< NvM state
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
	g_NvM_State_e = NVM_STATE_INIT;
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
	if(FALSE != g_NvM_InitDone_b)
	{
		switch(g_NvM_State_e)
		{
			case NVM_STATE_INIT:
			{
				g_NvM_State_e = NVM_STATE_READALL;
			}break;
			case NVM_STATE_READY:
			{

			}break;
			case NVM_STATE_READY_READ:
			case NVM_STATE_READ:
			case NVM_STATE_READALL:
			{
				g_NvM_State_e = NVM_STATE_READY;
			}break;
			case NVM_STATE_READY_WRITE:
			case NVM_STATE_WRITE:
			case NVM_STATE_WRITEALL:
			case NVM_STATE_SHUTDOWN:
			case NVM_STATE_ERROR:
			default:
			{

			}break;
		}
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
