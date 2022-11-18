/**
  * @file	LED.c
  * @author	cosmin.marcu
  * @date	Oct 10, 2022
  * @brief
  */

/* INCLUDES: */
#include "LED.h"
#include "Rte_LED.h"

/* DEFINES: */
#define LED_FADE_MIN_PULSE_U16					1000u					///< Minimum PWM pulse width
#define LED_FADE_MAX_PULSE_U16					64000u					///< Maximum PWM pulse width
#define LED_FADE_PULSE_STEP_U16					800u					///< Pulse step
#define LED_PULSE_DIRECTION_UP_U8				0u						///< Upward pulse direction
#define LED_PULSE_DIRECTION_DOWN_U8				1u						///< Downward pulse direction

/* TYPES: */

/* VARIABLES: */
static boolean g_LED_InitDone_b = FALSE;								///< Module initialization flag
static boolean g_LED_ButtonState_b = FALSE;								///< Blue button state
static uint16 g_LED_Pulse_u16 = 0u;										///< PWM Pulse width
static uint8 g_LED_Pulse_Direction_u8 = LED_PULSE_DIRECTION_UP_U8;		///< PWM Pulse direction
static uint8 g_LED_NvMBlock_a[32] = {0u};								///< LED NvM block

/* CONSTANTS: */

/* FUNCTIONS PROTOTYPES: */
static void LED_UpdatePulseDirection(void);
static void LED_UpdatePulseWidth(void);

/* STATIC FUNCTIONS: */
/**
  * @brief  Updates the PWM pulse direction
  * @return None
  */
static void LED_UpdatePulseDirection(void)
{
	/* Check is pulse value reached the maximum allowed value */
	if(g_LED_Pulse_u16 >= LED_FADE_MAX_PULSE_U16)
	{
		/* Switch pulse direction to downward */
		g_LED_Pulse_Direction_u8 = LED_PULSE_DIRECTION_DOWN_U8;
	}
	/* Check is pulse value reached the minimum allowed value */
	if(g_LED_Pulse_u16 <= LED_FADE_MIN_PULSE_U16)
	{
		/* Switch pulse direction to upward */
		g_LED_Pulse_Direction_u8 = LED_PULSE_DIRECTION_UP_U8;
	}
}

/**
  * @brief  Updates the PWM pulse step
  * @return None
  */
static void LED_UpdatePulseWidth(void)
{
	/* Check if pulse direction is upward */
	if(LED_PULSE_DIRECTION_UP_U8 == g_LED_Pulse_Direction_u8)
	{
		if(g_LED_Pulse_u16 <= LED_FADE_MAX_PULSE_U16)
		{
			/* Increment the pulse width */
			g_LED_Pulse_u16 = g_LED_Pulse_u16+LED_FADE_PULSE_STEP_U16;
		}
	}
	else
	{
		if(g_LED_Pulse_u16 >= LED_FADE_PULSE_STEP_U16)
		{
			/* Decrement the pulse width */
			g_LED_Pulse_u16 = g_LED_Pulse_u16-LED_FADE_PULSE_STEP_U16;
		}
	}
	/* Update pulse direction */
	LED_UpdatePulseDirection();
}

/* PUBLIC FUNCTIONS: */
/**
  * @brief  Initializes the LED module
  * @return None
  */
void LED_Init(void)
{
	/* Set servo initial position */
	Rte_Write_Servo_RawPulseWidth_u16(0u);
	/* Read LED NvM block */
	Rte_Read_NvM_LED_Block(g_LED_NvMBlock_a);
	/* Set initialization flag to done */
	g_LED_InitDone_b = TRUE;
}

/**
  * @brief  LED Main function (runs in periodic task)
  * @return None
  */
void LED_MainFunction(void)
{
	/* Check if initialization is done */
	if(TRUE == g_LED_InitDone_b)
	{
		/* Read the blue button state */
		Rte_Read_Button_State(&g_LED_ButtonState_b);
		/* Check if the button is released */
		if(TRUE == (boolean)g_LED_ButtonState_b)
		{
			/* Update PWM pulse width */
			LED_UpdatePulseWidth();
			/* Call the servo interface with the new pulse width */
			Rte_Write_Servo_RawPulseWidth_u16(g_LED_Pulse_u16);
		}
		else
		{
			/* Stop fading */
		}
	}
}

/* END OF FILE */
