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
static boolean g_Brakes_InitDone_b = FALSE;							///< Module initialization flag
static uint16 g_Brakes_AN0_Voltage_u16 = 0u;						///< ADC AN0 analog voltage
static float32 g_Brakes_Ultrasonic_Distance_f32 = 0.0f;				///< Distance measured by the ultrasonic sensor

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
	g_Brakes_InitDone_b = TRUE;
}

/**
  * @brief	Brakes module main function (runs in task)
  * @return	None
  */
void Brakes_MainFunction(void)
{
	/* Check if initialization is done */
	if(TRUE == g_Brakes_InitDone_b)
	{
		/* Read AN0 analog voltage (mV) */
		Rte_Read_ADC_AN0_Voltage_u16(&g_Brakes_AN0_Voltage_u16);
		/* Read distance from ultrasonic sensor */
		Rte_Read_Ultrasonic_Distance_f32(&g_Brakes_Ultrasonic_Distance_f32);
	}
}
/* END OF FILE */
