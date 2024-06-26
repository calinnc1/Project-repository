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
#define	BRAKES_CRITICAL_DISTANCE_CM_F32				(float32)30.0f		///< Autobrakes enable critical distance [cm]
#define	BRAKES_AUTOBRAKES_DISABLE_DISTANCE_CM_F32	(float32)40.0f		///< Autobrakes disable distance [cm]
#define	BRAKES_AUTOBRAKES_STATE_CNT_U8				(uint8)10u			///< Autobraked enable/disable debounce counter

/* TYPES: */

/* VARIABLES: */
static boolean g_Brakes_InitDone_b = FALSE;								///< Module initialization flag
static uint16 g_Brakes_AN0_Voltage_mV_u16 = 0u;							///< ADC AN0 analog voltage [mV]
static float32 g_Brakes_Ultrasonic_Distance_cm_f32 = 0.0f;				///< Distance measured by the ultrasonic sensor [cm]
static boolean g_Brakes_Autobrakes_Status_b = FALSE;					///< Autobrakes status
static uint8 g_Brakes_Autobrakes_Disable_Cnt_u8 = 0u;					///< Autobrakes disable counter
static uint8 g_Brakes_Autobrakes_Enable_Cnt_u8 = 0u;					///< Autobrakes enable counter
static uint8 g_Brakes_NvMBlock_a[NVM_BLOCK_SIZE] = {0u};				///< Brakes NvM block
/* CONSTANTS: */

/* FUNCTIONS PROTOTYPES: */
static void Brakes_OnAutobrakesEnabled(void);
static void Brakes_OnAutobrakesDisabled(void);
/* STATIC FUNCTIONS: */
/**
  * @brief	Triggers the actions for Autobrakes enabled state
  * @return	None
  */
static void Brakes_OnAutobrakesEnabled(void)
{
	/* Check critical distance */
	if((g_Brakes_Ultrasonic_Distance_cm_f32 < BRAKES_CRITICAL_DISTANCE_CM_F32) && (g_Brakes_Autobrakes_Enable_Cnt_u8 >= BRAKES_AUTOBRAKES_STATE_CNT_U8))
	{
		/* Set Autobrakes flag */
		g_Brakes_Autobrakes_Status_b = TRUE;
		/* Reset Autobrakes enable counter */
		g_Brakes_Autobrakes_Enable_Cnt_u8 = 0u;
		/* Set Autobrakes */
		Rte_Write_Autobrakes_State_b(g_Brakes_Autobrakes_Status_b);
	}
	else if (g_Brakes_Ultrasonic_Distance_cm_f32 < BRAKES_CRITICAL_DISTANCE_CM_F32)
	{
		/* Increment Autobrakes enable counter */
		g_Brakes_Autobrakes_Enable_Cnt_u8++;
	}
	else
	{
		/* Reset Autobrakes enable counter */
		g_Brakes_Autobrakes_Enable_Cnt_u8 = 0u;
	}
}

/**
  * @brief	Triggers the actions for Autobrakes disabled state
  * @return	None
  */
static void Brakes_OnAutobrakesDisabled(void)
{
	/* Check Autobrakes disable distance */
	if((g_Brakes_Ultrasonic_Distance_cm_f32 > BRAKES_AUTOBRAKES_DISABLE_DISTANCE_CM_F32) && (g_Brakes_Autobrakes_Disable_Cnt_u8 >= BRAKES_AUTOBRAKES_STATE_CNT_U8))
	{
		/* Reset Autobrakes flag */
		g_Brakes_Autobrakes_Status_b = FALSE;
		/* Reset Autobrakes disable counter */
		g_Brakes_Autobrakes_Disable_Cnt_u8 = 0u;
		/* Reset Autobrakes */
		Rte_Write_Autobrakes_State_b(g_Brakes_Autobrakes_Status_b);
	}
	else if(g_Brakes_Ultrasonic_Distance_cm_f32 > BRAKES_AUTOBRAKES_DISABLE_DISTANCE_CM_F32)
	{
		/* Increment Autobrakes disable counter */
		g_Brakes_Autobrakes_Disable_Cnt_u8++;
	}
	else
	{
		/* Reset Autobrakes disable counter */
		g_Brakes_Autobrakes_Disable_Cnt_u8 = 0u;
	}
}
/* PUBLIC FUNCTIONS: */
/**
  * @brief	Brakes module initialization function
  * @return	None
  */
void Brakes_Init(void)
{
	/* Initialize variables */
	g_Brakes_AN0_Voltage_mV_u16 = 0u;
	g_Brakes_Ultrasonic_Distance_cm_f32 = 0.0f;
	g_Brakes_Autobrakes_Status_b = FALSE;
	g_Brakes_Autobrakes_Disable_Cnt_u8 = 0u;
	g_Brakes_Autobrakes_Enable_Cnt_u8 = 0u;
	/* Read Brakes NvM block */
	Rte_Read_NvM_Brakes_Block(g_Brakes_NvMBlock_a);
	/* Set initialization flag to done */
	g_Brakes_InitDone_b = TRUE;
}

/**
  * @brief	Brakes module main function (runs in task)
  * @return	None
  */
void Brakes_MainFunction(void)
{
	/* Check if initialization is done */
	if(FALSE != g_Brakes_InitDone_b)
	{
		/* Read AN0 analog voltage (mV) */
		Rte_Read_ADC_AN0_Voltage_u16(&g_Brakes_AN0_Voltage_mV_u16);
		/* Read distance from ultrasonic sensor */
		Rte_Read_Ultrasonic_Distance_f32(&g_Brakes_Ultrasonic_Distance_cm_f32);
		/* Check Autobrakes condition */
		if(FALSE == g_Brakes_Autobrakes_Status_b)
		{
			/* Autobrakes enabled actions */
			Brakes_OnAutobrakesEnabled();
		}
		else
		{
			/* Autobrakes disabled actions */
			Brakes_OnAutobrakesDisabled();
		}
	}
}

/**
  * @brief  Shutdown the Brakes module
  * @return None
  */
void Brakes_Shutdown(void)
{
	/* Write Brakes NvM block */
	Rte_Write_NvM_Brakes_Block(g_Brakes_NvMBlock_a);
	/* Reset initialization flag */
	g_Brakes_InitDone_b = FALSE;
}
/* END OF FILE */
