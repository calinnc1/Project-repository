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
#define INCREMENT_SPEED  (uint8)10u                                  ///< The number by which the speed is increased
#define DECREMENT_SPEED  (uint8)10u                                  ///< The number by which the speed is decreased

#define TRESHOLD_FORWARD (uint8)45u                                  ///< The number indicating the threshold for the front direction, given by the joystick
#define TRESHOLD_BACKWARD (uint8)60u                                 ///< The number indicating the threshold for the back direction, given by the joystick
#define TRESHOLD_RIGHT (uint8)45u                                    ///< The number indicating the threshold for the right direction, given by the joystick
#define TRESHOLD_LEFT (uint8)65u                                     ///< The number indicating the threshold for the left direction, given by the joystick

#define	ENGINE_CRITICAL_DISTANCE_CM_F32	(float32)30.0f		         ///< Autobrakes enable critical distance [cm]

/* TYPES: */

/* VARIABLES: */
static boolean g_Engine_InitDone_b = FALSE;							 ///< Module initialization flag

static uint8 g_Engine_SW_u8 = 0u;                                    ///< The value of the switch from the joystick
static uint8 g_Engine_SW_Previous_State_u8 = 0u;                     ///< The previous value of the switch from the joystick

static uint16 g_Engine_Joystick_0_Voltage_mV_u16 = 0u;               ///< Value in volts of the horizontal axis from the joystick
static uint16 g_Engine_Joystick_1_Voltage_mV_u16 = 0u;               ///< Value in volts of the vertical axis from the joystick
static uint8 g_Switch_CNT_u8 = 0u;                                   ///< Counter value allowing switching between remote control and joystick
static uint8 g_Engine_Joystick_0_Duty_Cycle_u8 = 0u;                 ///< Duty Cycle value of the horizontal axis from the joystick
static uint8 g_Engine_Joystick_1_Duty_Cycle_u8 = 0u;                 ///< Duty Cycle value of the vertical axis from the joystick

static float32 g_Engine_Ultrasonic_Distance_cm_f32 = 0.0f;		     ///< Distance measured by the ultrasonic sensor [cm]
static uint16 g_Engine_Ultrasonic_Distance_cm_u16 = 0;				 ///< Distance measured by the ultrasonic sensor [cm] integer value

static uint8 g_Remote_Control_Status_D0_u8 = 0;                      ///< Pin value D0 from RF module
static uint8 g_Remote_Control_Status_D1_u8 = 0;                      ///< Pin value D1 from RF module
static uint8 g_Remote_Control_Status_D2_u8 = 0;                      ///< Pin value D2 from RF module
static uint8 g_Remote_Control_Status_D3_u8 = 0;                      ///< Pin value D3 from RF module

static uint8 g_Remote_Control_Previous_Status_D0_u8 = 0;             ///< Previous pin value D0 from RF module
static uint8 g_Remote_Control_Previous_Status_D1_u8 = 0;             ///< Previous pin value D1 from RF module
static uint8 g_Remote_Control_Previous_Status_D2_u8 = 0;             ///< Previous pin value D2 from RF module
static uint8 g_Remote_Control_Previous_Status_D3_u8 = 0;             ///< Previous pin value D3 from RF module

static uint8 g_Speed_0_u8 = 0;                                       ///< Unsigned Engine Speed Value 0
static uint8 g_Speed_1_u8 = 0;                                       ///< Unsigned Engine Speed Value 1

static sint8 g_Speed_0_s8 = 0;                                       ///< Signed Engine Speed Value 0
static sint8 g_Speed_1_s8 = 0;                                       ///< Signed Engine Speed Value 1

static sint8 g_Speed_Before_s8 = 0;                                  ///< Saved value of speed

static uint8 g_Direction_u8 = 0;                                     ///< Direction value

/* CONSTANTS: */

/* FUNCTIONS PROTOTYPES: */

/* STATIC FUNCTIONS: */

/* Move forward remote control */
void move_Forward_Remote(uint8 *current_Status, uint8 *previous_Status, sint8 *speed_0, sint8 *speed_1, uint8 increment)
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

/* Move right remote control */
void move_Right_Remote(uint8 *current_Status, uint8 *previous_Status, sint8 *speed_0, sint8 *speed_1, sint8 *speed_Before_Turn)
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

/* Move left remote control */
void move_Left_Remote(uint8 *current_Status, uint8 *previous_Status, sint8 *speed_0, sint8 *speed_1, sint8 *speed_Before_Turn)
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

/* Move backward remote control */
void move_Backward_Remote(uint8 *current_Status, uint8 *previous_Status, sint8 *speed_0, sint8 *speed_1, uint8 decrement)
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

/* Conversion from mV to duty cycle */
void mV_To_DutyCycle(uint16 *mV_Value, uint8 *duty_Cylce_Value)
{
	*duty_Cylce_Value = *mV_Value * 0.030303;
}

/* Move commanded by joystick */
void move_From_Joystick(uint8 *horizontal_Axis_Duty, uint8 *vertical_Axis_Duty, sint8 *speed_0, sint8 *speed_1)
{
	if(*vertical_Axis_Duty < TRESHOLD_FORWARD)
	{
		*speed_0 = 100 - (*vertical_Axis_Duty * 2);
		*speed_1 = *speed_0;
		if(*horizontal_Axis_Duty < TRESHOLD_RIGHT)
		{
			*speed_0 = 0;
		}
		else if(*horizontal_Axis_Duty > TRESHOLD_LEFT)
		{
			*speed_1 = 0;
		}
		else
		{

		}
	}
	else if(*vertical_Axis_Duty > TRESHOLD_BACKWARD)
	{
		*speed_0 = -(*vertical_Axis_Duty - 50) * 2;
		*speed_1 = *speed_0;
		if(*horizontal_Axis_Duty < TRESHOLD_RIGHT)
		{
			*speed_0 = 0;
		}
		else if(*horizontal_Axis_Duty > TRESHOLD_LEFT)
		{
			*speed_1 = 0;
		}
		else
		{

		}
	}
	else
	{
		*speed_0 = 0;
		*speed_1 = 0;
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
		/* Read RT module */
		Rte_Read_Remote_Channel0(&g_Remote_Control_Status_D0_u8);
		Rte_Read_Remote_Channel1(&g_Remote_Control_Status_D1_u8);
		Rte_Read_Remote_Channel2(&g_Remote_Control_Status_D2_u8);
		Rte_Read_Remote_Channel3(&g_Remote_Control_Status_D3_u8);

		/* Read Joystick */
		Rte_Engine_Switch_Joystick(&g_Engine_SW_u8);
		Rte_Read_ADC_0_Joystick_Voltage_u16(&g_Engine_Joystick_0_Voltage_mV_u16);
		Rte_Read_ADC_1_Joystick_Voltage_u16(&g_Engine_Joystick_1_Voltage_mV_u16);
		mV_To_DutyCycle(&g_Engine_Joystick_0_Voltage_mV_u16, &g_Engine_Joystick_0_Duty_Cycle_u8);
		mV_To_DutyCycle(&g_Engine_Joystick_1_Voltage_mV_u16, &g_Engine_Joystick_1_Duty_Cycle_u8);

		/* Read Ultrasonic distance */
		Rte_Read_Ultrasonic(&g_Engine_Ultrasonic_Distance_cm_f32);
		/* Convert ultrasonic distance value to uint16 */
		g_Engine_Ultrasonic_Distance_cm_u16 = (uint16) g_Engine_Ultrasonic_Distance_cm_f32;

		/* The selection that shows whether the instructions are given from the remote control or from the joystick */
		if(g_Engine_SW_u8 == 0 && g_Engine_SW_Previous_State_u8 == 1)
		{
			if(g_Switch_CNT_u8 == 2)
			{
				g_Switch_CNT_u8 = 0;
			}
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

		if(g_Engine_Ultrasonic_Distance_cm_u16 < ENGINE_CRITICAL_DISTANCE_CM_F32 && !g_Direction_u8)
		{
			g_Speed_0_s8 = 0;
			g_Speed_1_s8 = 0;
		}
		else
		{
			if( g_Switch_CNT_u8 % 2 == 0)
			{
				/* Turn off the LED that shows that the joystick is giving the command and indicates that the instructions are given by the remote control now */
				Rte_Write_Green_LED_Status(FALSE);
				/* Moves from remote control */
				move_Forward_Remote(&g_Remote_Control_Status_D2_u8, &g_Remote_Control_Previous_Status_D2_u8, &g_Speed_0_s8, &g_Speed_1_s8, INCREMENT_SPEED);
				move_Right_Remote(&g_Remote_Control_Status_D0_u8, &g_Remote_Control_Previous_Status_D0_u8, &g_Speed_0_s8, &g_Speed_1_s8, &g_Speed_Before_s8);
				move_Left_Remote(&g_Remote_Control_Status_D3_u8, &g_Remote_Control_Previous_Status_D3_u8, &g_Speed_0_s8, &g_Speed_1_s8, &g_Speed_Before_s8);
				move_Backward_Remote(&g_Remote_Control_Status_D1_u8, &g_Remote_Control_Previous_Status_D1_u8, &g_Speed_0_s8, &g_Speed_1_s8, DECREMENT_SPEED);
			}
			else
			{
				/* Lights up a LED that indicates that the joystick is giving the command now */
				Rte_Write_Green_LED_Status(TRUE);
				/* Moves from joystick */
				move_From_Joystick(&g_Engine_Joystick_0_Duty_Cycle_u8, &g_Engine_Joystick_1_Duty_Cycle_u8, &g_Speed_0_s8, &g_Speed_1_s8);
			}
		}


		/* Set speed and direction */
		set_Speed_And_Direction(&g_Speed_0_s8, &g_Speed_1_s8, &g_Speed_0_u8, &g_Speed_1_u8, &g_Direction_u8);
        /* Write on DC motor */
		Rte_Speed_DCMotor(DC_MOTOR_ID_0, g_Speed_0_u8);
		Rte_Speed_DCMotor(DC_MOTOR_ID_1, g_Speed_1_u8);
		Rte_Direction_DCMotor(DC_MOTOR_ID_0, g_Direction_u8);
		Rte_Direction_DCMotor(DC_MOTOR_ID_1, g_Direction_u8);
	}
}
/* END OF FILE */
