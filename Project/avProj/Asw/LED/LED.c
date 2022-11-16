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
#define LED_FADE_MIN_PULSE					1000u				///< Minimum PWM pulse width
#define LED_FADE_MAX_PULSE					64000u				///< Maximum PWM pulse width
#define LED_FADE_PULSE_STEP					800u				///< Pulse step
#define LED_PULSE_DIRECTION_UP				0u					///< Upward pulse direction
#define LED_PULSE_DIRECTION_DOWN			1u					///< Downward pulse direction

/* TYPES: */

/* VARIABLES: */
static boolean g_LED_InitDone_b = FALSE;							///< Module initialization flag
static boolean g_LED_ButtonState_b = FALSE;							///< Blue button state
static uint16 g_LED_Pulse_u16 = 0u;									///< PWM Pulse width
static uint8 g_LED_Pulse_Direction_u8 = LED_PULSE_DIRECTION_UP;		///< PWM Pulse direction
static boolean g_LED_NvMReadRequestFinished_b = FALSE;				///< Saves the status of NvM Read request
static uint8 g_LED_NvMBlock_a[32] = {0u};							///< LED NvM block

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
	if(g_LED_Pulse_u16 >= LED_FADE_MAX_PULSE)
	{
		/* Switch pulse direction to downward */
		g_LED_Pulse_Direction_u8 = LED_PULSE_DIRECTION_DOWN;
	}
	/* Check is pulse value reached the minimum allowed value */
	if(g_LED_Pulse_u16 <= LED_FADE_MIN_PULSE)
	{
		/* Switch pulse direction to upward */
		g_LED_Pulse_Direction_u8 = LED_PULSE_DIRECTION_UP;
	}
}

/**
  * @brief  Updates the PWM pulse step
  * @return None
  */
static void LED_UpdatePulseWidth(void)
{
	/* Check if pulse direction is upward */
	if(LED_PULSE_DIRECTION_UP == g_LED_Pulse_Direction_u8)
	{
		if(g_LED_Pulse_u16 <= LED_FADE_MAX_PULSE)
		{
			/* Increment the pulse width */
			g_LED_Pulse_u16 = g_LED_Pulse_u16+LED_FADE_PULSE_STEP;
		}
	}
	else
	{
		if(g_LED_Pulse_u16 >= LED_FADE_PULSE_STEP)
		{
			/* Decrement the pulse width */
			g_LED_Pulse_u16 = g_LED_Pulse_u16-LED_FADE_PULSE_STEP;
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
		/* Send NvM Read request once */
		if(FALSE == g_LED_NvMReadRequestFinished_b)
		{
			Rte_Read_NvM_LED_Block(g_LED_NvMBlock_a);
			g_LED_NvMReadRequestFinished_b = TRUE;
		}
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
