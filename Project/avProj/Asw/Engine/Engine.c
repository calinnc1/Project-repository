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
static uint8 g_Engine_SW_u8 = 0u;
uint8 g_Switch_CNT_u8 = 0u;
uint8 g_Engine_SW_Previous_State_u8 = 0u;
uint8 g_Remote_Control_Status_D0_u8 = 0;
uint8 g_Remote_Control_Status_D1_u8 = 0;
uint8 g_Remote_Control_Status_D2_u8 = 0;
uint8 g_Remote_Control_Status_D3_u8 = 0;

uint8 g_Remote_Control_Previous_Status_D0_u8 = 0;
uint8 g_Remote_Control_Previous_Status_D1_u8 = 0;
uint8 g_Remote_Control_Previous_Status_D2_u8 = 0;
uint8 g_Remote_Control_Previous_Status_D3_u8 = 0;

uint8 g_Speed_0_u8 = 0;
uint8 g_Speed_1_u8 = 0;

sint8 g_Speed_0_s8 = 0;
sint8 g_Speed_1_s8 = 0;

sint8 g_Speed_Before_Turn_s8 = 0;

uint8 g_Direction_u8 = 0;

/* CONSTANTS: */

/* FUNCTIONS PROTOTYPES: */

/* STATIC FUNCTIONS: */

/* Move forward */
void move_Forward(uint8 *current_Status, uint8 *previous_Status, sint8 *speed_0, sint8 *speed_1, uint8 increment)
{
	if(*current_Status == 1 && *previous_Status == 0)
	{
		if(*speed_0 < 100 && *speed_1 < 100)
		{
			if(*speed_0 == 0 && *speed_1 == 0)
			{
				*speed_0 = *speed_0 + 2*increment;
				*speed_1 = *speed_0;
			}
			else
			{
				*speed_0 = *speed_0 + increment;
				*speed_1 = *speed_0;
			}
		}
		else
		{

		}
		*previous_Status = 1;
	}
	else if(*current_Status == 0 && *previous_Status == 1)
	{
		*previous_Status = 0;
	}
	else
	{

	}
}

/* Move right */
void move_Right(uint8 *current_Status, uint8 *previous_Status, sint8 *speed_0, sint8 *speed_1, sint8 *speed_Before_Turn)
{
	if(*current_Status == 1 && *previous_Status == 0)
	{
		*speed_Before_Turn = *speed_0;
		*previous_Status = 1;
	}
	else if(*current_Status == 0 && *previous_Status == 1)
	{
		*speed_0 = *speed_Before_Turn;
		*speed_1 = *speed_Before_Turn;
		*previous_Status = 0;
	}
	else if(*current_Status == 1 && *previous_Status == 1)
	{
		*speed_1 = *speed_Before_Turn;
		*speed_0 = 0;
		*previous_Status = 1;
	}
	else
	{

	}
}

/* Move left */
void move_Left(uint8 *current_Status, uint8 *previous_Status, sint8 *speed_0, sint8 *speed_1, sint8 *speed_Before_Turn)
{
	if(*current_Status == 1 && *previous_Status == 0)
	{
		*speed_Before_Turn = *speed_0;
		*previous_Status = 1;
	}
	else if(*current_Status == 0 && *previous_Status == 1)
	{
		*speed_0 = *speed_Before_Turn;
		*speed_1 = *speed_Before_Turn;
		*previous_Status = 0;
	}
	else if(*current_Status == 1 && *previous_Status == 1)
	{
		*speed_0 = *speed_Before_Turn;
		*speed_1 = 0;
		*previous_Status = 1;
	}
	else
	{

	}
}

/* Move backward */
void move_Backward(uint8 *current_Status, uint8 *previous_Status, sint8 *speed_0, sint8 *speed_1, uint8 decrement)
{
	if(*current_Status == 1 && *previous_Status == 0)
	{
		if(*speed_0 >= -90 && *speed_1 >= -90)
		{
			if(*speed_0 == 0 && *speed_1 == 0)
			{
				*speed_0 = *speed_0 - 2*decrement;
				*speed_1 = *speed_0;
			}
			else
			{
				*speed_0 = *speed_0 - decrement;
				*speed_1 = *speed_0;
			}
		}
		else
		{

		}
		*previous_Status = 1;
	}
	else if(*current_Status == 0 && *previous_Status == 1)
	{
		*previous_Status = 0;
	}
	else
	{

	}
}

/* Set speed and direction */
void set_Speed_And_Direction(sint8 *speed_0_s8, sint8 *speed_1_s8, uint8 *speed_0_u8, uint8 *speed_1_u8, uint8 *direction)
{
	if(*speed_0_s8 == 0)
	{
		if(*speed_1_s8 == 0)
		{
			*speed_0_u8 = 0;
			*speed_1_u8 = 0;
			*direction = DC_MOTOR_DIR_CW;
		}
		else if(*speed_1_s8 > 0)
		{
			*speed_0_u8 = 0;
			*speed_1_u8 = *speed_1_s8;
			*direction = DC_MOTOR_DIR_CW;
		}
		else if(*speed_1_s8 < 0)
		{
			*speed_0_u8 = 0;
			*speed_1_u8 = -*speed_1_s8;
			*direction = DC_MOTOR_DIR_CCW;
		}
		else
		{

		}
	}
	else if(*speed_0_s8 > 0)
	{
		if(*speed_1_s8 == 0)
		{
			*speed_0_u8 = *speed_0_s8;
			*speed_1_u8 = 0;
			*direction = DC_MOTOR_DIR_CW;
		}
		else if(*speed_1_s8 > 0)
		{
			*speed_0_u8 = *speed_0_s8;
			*speed_1_u8 = *speed_1_s8;
			*direction = DC_MOTOR_DIR_CW;
		}
		else if(*speed_1_s8 < 0)
		{
			*speed_0_u8 = *speed_0_s8;
			*speed_1_u8 = -*speed_1_s8;
			*direction = DC_MOTOR_DIR_CCW;
		}
		else
		{

		}
	}
	else if(*speed_0_s8 < 0)
	{
		if(*speed_1_s8 == 0)
		{
			*speed_0_u8 = -*speed_0_s8;
			*speed_1_u8 = 0;
			*direction = DC_MOTOR_DIR_CCW;
		}
		else if(*speed_1_s8 > 0)
		{
			*speed_0_u8 = -*speed_0_s8;
			*speed_1_u8 = *speed_1_s8;
			*direction = DC_MOTOR_DIR_CW;
		}
		else if(*speed_1_s8 < 0)
		{
			*speed_0_u8 = -*speed_0_s8;
			*speed_1_u8 = -*speed_1_s8;
			*direction = DC_MOTOR_DIR_CCW;
		}
		else
		{

		}
	}
	else
	{

	}
}

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
		Rte_Engine_Switch_Joystick(&g_Engine_SW_u8);

		//Rte_Start_DCMotor();

		if(g_Engine_SW_u8 == 0 && g_Engine_SW_Previous_State_u8 == 1)
		{
			g_Switch_CNT_u8++;
			g_Engine_SW_Previous_State_u8 = 0;
		}
		else if(g_Engine_SW_u8 == 1 && g_Engine_SW_Previous_State_u8 == 0)
		{
			g_Engine_SW_Previous_State_u8 = 1;
		}
		else
		{

		}

		if( g_Switch_CNT_u8 % 2 == 0)
		{
			/* Moves from remote control */
			move_Forward(&g_Remote_Control_Status_D2_u8, &g_Remote_Control_Previous_Status_D2_u8, &g_Speed_0_s8, &g_Speed_1_s8, INCREMENT_SPEED);
			move_Right(&g_Remote_Control_Status_D0_u8, &g_Remote_Control_Previous_Status_D0_u8, &g_Speed_0_s8, &g_Speed_1_s8, &g_Speed_Before_Turn_s8);
		    move_Left(&g_Remote_Control_Status_D3_u8, &g_Remote_Control_Previous_Status_D3_u8, &g_Speed_0_s8, &g_Speed_1_s8, &g_Speed_Before_Turn_s8);
			move_Backward(&g_Remote_Control_Status_D1_u8, &g_Remote_Control_Previous_Status_D1_u8, &g_Speed_0_s8, &g_Speed_1_s8, DECREMENT_SPEED);
		}
		else
		{
			/* Moves from joystick */

		}

		/* Set speed and direction */
		set_Speed_And_Direction(&g_Speed_0_s8, &g_Speed_1_s8, &g_Speed_0_u8, &g_Speed_1_u8, &g_Direction_u8);

		Rte_Speed_DCMotor(DC_MOTOR_ID_0, g_Speed_0_u8);
		Rte_Speed_DCMotor(DC_MOTOR_ID_1, g_Speed_1_u8);
		Rte_Direction_DCMotor(DC_MOTOR_ID_0, g_Direction_u8);
		Rte_Direction_DCMotor(DC_MOTOR_ID_1, g_Direction_u8);
		//Rte_Stop_DCMotor();
		/* Write on DC motor */

	}
}
/* END OF FILE */
