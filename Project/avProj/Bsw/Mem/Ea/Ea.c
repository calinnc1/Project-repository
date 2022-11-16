/**
  * @file	Ea.c
  * @author	cosmin.marcu
  * @date	Nov 16, 2022
  * @brief
  */

/* INCLUDES: */
#include "Ea.h"
#include "stm32f3xx_hal_dma.h"
#include "stm32f3xx_hal_i2c.h"

/* DEFINES: */
#define EA_FRAM_HW_ADDR		0xA0u												///< FRAM HW Address
#define EA_FRAM_BASE_ADDR	0x0000u												///< FRAM Base Address
#define EA_FRAM_MAX_BLOCKS	1024u												///< Number of FRAM blocks (32 bytes per block)
#define EA_FRAM_BLOCK_SIZE	32u												///< Size of FRAM blocks
#define EA_FRAM_ADDRESS_OFFSET(x)	(EA_FRAM_BASE_ADDR + x*EA_FRAM_BLOCK_SIZE)	///< Address offset macro
/* TYPES: */

/* VARIABLES: */
extern I2C_HandleTypeDef hi2c1;
static boolean g_Ea_InitDone_b = FALSE;											///< Module initialization flag

/* CONSTANTS: */

/* FUNCTIONS PROTOTYPES: */

/* STATIC FUNCTIONS: */

/* PUBLIC FUNCTIONS: */
/**
  * @brief	Ea module initialization function
  * @return	None
  */
void Ea_Init(void)
{

	/* Set initialization flag to done */
	g_Ea_InitDone_b = TRUE;
}

/**
  * @brief	Ea Read function
  * @param	BlockId		ID of the block to be read
  * @param  data		Pointer to the buffer where read data is stored
  * @return	None
  */
void Ea_Read(uint16 Block_Id, uint8 *data)
{
	if(Block_Id < EA_FRAM_MAX_BLOCKS)
	{
		HAL_I2C_Mem_Read_DMA(&hi2c1, (uint16_t)EA_FRAM_HW_ADDR, EA_FRAM_ADDRESS_OFFSET(Block_Id), I2C_MEMADD_SIZE_16BIT, data, EA_FRAM_BLOCK_SIZE);
	}
}

/**
  * @brief	Ea Write block function
  * @param	BlockId		ID of the block to be written
  * @param  data		Pointer to the data to be written
  * @return	None
  */
void Ea_Write(uint16 Block_Id, uint8 *data)
{
	if(Block_Id < EA_FRAM_MAX_BLOCKS)
	{
		HAL_I2C_Mem_Write_DMA(&hi2c1, (uint16_t)EA_FRAM_HW_ADDR, EA_FRAM_ADDRESS_OFFSET(Block_Id), I2C_MEMADD_SIZE_16BIT, data, EA_FRAM_BLOCK_SIZE);
	}
}
/* END OF FILE */
