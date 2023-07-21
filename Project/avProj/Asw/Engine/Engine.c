/**
  * @file	Engine.c
  * @author	cosmin.marcu
  * @date	Nov 4, 2022
  * @brief
  */

/* INCLUDES: */
#include "Engine.h"
#include "Rte_Engine.h"

/* DEFINES: */
#define INCREMENT_SPEED (uint8)10u                                  ///< The number by which the speed is increased
#define DECREMENT_SPEED (uint8)10u                                  ///< The number by which the speed is decreased
/* TYPES: */

/* VARIABLES: */
static boolean g_Engine_InitDone_b = FALSE;							///< Module initialization flag
uint8 g_Remote_Control_Status_D0_u8 = 0;
uint8 g_Remote_Control_Status_D1_u8 = 0;
uint8 g_Remote_Control_Status_D2_u8 = 0;
uint8 g_Remote_Control_Status_D3_u8 = 0;

uint8 g_Remote_Control_Previous_Status_D0_u8 = 0;
uint8 g_Remote_Control_Previous_Status_D1_u8 = 0;
uint8 g_Remote_Control_Previous_Status_D2_u8 = 0;
uint8 g_Remote_Control_Previous_Status_D3_u8 = 0;

uint8 g_Speed_u8 = 0;
sint8 g_Speed_s8 = 0;

uint8 g_Direction_u8 = 0;

/* CONSTANTS: */

/* FUNCTIONS PROTOTYPES: */

/* STATIC FUNCTIONS: */

/* PUBLIC FUNCTIONS: */
/**
  * @brief	Engine module initialization function
  * @return	None
  */
void Engine_Init(void)
{

	/* Set initialization flag to done */
	g_Engine_InitDone_b = TRUE;
}

/**
  * @brief	Engine module main function (runs in task)
  * @return	None
  */
void Engine_MainFunction(void)
{
	/* Check if initialization is done */
	if(TRUE == g_Engine_InitDone_b)
	{
		/* Read adc */
		Rte_Read_Remote_Channel0(&g_Remote_Control_Status_D0_u8);
		Rte_Read_Remote_Channel1(&g_Remote_Control_Status_D1_u8);
		Rte_Read_Remote_Channel2(&g_Remote_Control_Status_D2_u8);
		Rte_Read_Remote_Channel3(&g_Remote_Control_Status_D3_u8);

		//Rte_Start_DCMotor();
		if(g_Remote_Control_Status_D2_u8 == 1 && g_Remote_Control_Previous_Status_D2_u8 == 0)
		{
			if(g_Speed_s8 < 100)
			{
				g_Speed_s8 = g_Speed_s8 + INCREMENT_SPEED;
			}
			else
			{

			}
			g_Remote_Control_Previous_Status_D2_u8 = 1;
		}
		else if(g_Remote_Control_Status_D2_u8 == 0 && g_Remote_Control_Previous_Status_D2_u8 == 1)
		{
			g_Remote_Control_Previous_Status_D2_u8 = 0;
		}
		else
		{

		}

		if(g_Remote_Control_Status_D1_u8 == 1 && g_Remote_Control_Previous_Status_D1_u8 == 0)
		{
			if(g_Speed_s8 >= -90)
			{
				g_Speed_s8 = g_Speed_s8 - DECREMENT_SPEED;
			}
			else
			{

			}
			g_Remote_Control_Previous_Status_D1_u8 = 1;
		}
		else if(g_Remote_Control_Status_D1_u8 == 0 && g_Remote_Control_Previous_Status_D1_u8 == 1)
		{
			g_Remote_Control_Previous_Status_D1_u8 = 0;
		}
		else
		{

		}

		if(g_Speed_s8 >= 0)
		{
			g_Speed_u8 = g_Speed_s8;
			g_Direction_u8 = DC_MOTOR_DIR_CW;
		}
		else
		{
			g_Speed_u8 = -g_Speed_s8;
			g_Direction_u8 = DC_MOTOR_DIR_CCW;
		}
		Rte_Speed_DCMotor(DC_MOTOR_ID_0, g_Speed_u8);
		Rte_Speed_DCMotor(DC_MOTOR_ID_1, g_Speed_u8);
		Rte_Direction_DCMotor(DC_MOTOR_ID_0, g_Direction_u8);
		Rte_Direction_DCMotor(DC_MOTOR_ID_1, g_Direction_u8);
		//Rte_Stop_DCMotor();
		/* Write on DC motor */

	}
}
/* END OF FILE */
