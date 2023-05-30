/*
 * Cdd_Servo.c
 *
 *  Created on: Nov 2, 2022
 *      Author: cosmin.marcu
 */

#include "Cdd_Servo.h"

typedef struct
{
	uint16  Period_Min_u16;
	uint16  Period_Max_u16;
}Cdd_Servo_Info_t;

TIM_HandleTypeDef g_TimerHandler_s = {0};

static Cdd_Servo_Info_t g_SERVO_info_s = {0};

const Cdd_Servo_CfgType c_SERVO_CfgParam_s =
{
	/* Servo Motor Configuration */
    GPIOA,
	GPIO_PIN_5,
	TIM2,
	&TIM2->CCR1,
	TIM_CHANNEL_1,
	72000000,
	0.0,
	20.0
};

void Cdd_Servo_Driver_Init(void)
{
	GPIO_InitTypeDef l_GPIO_InitStruct_s = {0};
	TIM_ClockConfigTypeDef l_ClockSourceConfig_s = {0};
    TIM_MasterConfigTypeDef l_MasterConfig_s = {0};
    TIM_OC_InitTypeDef l_ConfigOC_s = {0};
    uint32 l_PSC_Value_u32 = 0UL;
    uint32 l_ARR_Value_u32 = 0UL;
    //DWT_Delay_Init();

	/*--------[ Configure The Servo PWM GPIO Pin ]-------*/

    if(c_SERVO_CfgParam_s.SERVO_GPIO == GPIOA)
    {
    	__HAL_RCC_GPIOA_CLK_ENABLE();
    }
    else if(c_SERVO_CfgParam_s.SERVO_GPIO == GPIOB)
    {
    	__HAL_RCC_GPIOB_CLK_ENABLE();
    }
    else if(c_SERVO_CfgParam_s.SERVO_GPIO == GPIOC)
    {
        __HAL_RCC_GPIOC_CLK_ENABLE();
    }
    else if(c_SERVO_CfgParam_s.SERVO_GPIO == GPIOD)
    {
        __HAL_RCC_GPIOD_CLK_ENABLE();
    }
    else if(c_SERVO_CfgParam_s.SERVO_GPIO == GPIOE)
    {
        __HAL_RCC_GPIOE_CLK_ENABLE();
    }
	l_GPIO_InitStruct_s.Pin = c_SERVO_CfgParam_s.SERVO_PIN;
	l_GPIO_InitStruct_s.Mode = GPIO_MODE_AF_PP;
	l_GPIO_InitStruct_s.Speed = GPIO_SPEED_FREQ_LOW;
	l_GPIO_InitStruct_s.Alternate = GPIO_AF1_TIM2;
	HAL_GPIO_Init(c_SERVO_CfgParam_s.SERVO_GPIO, &l_GPIO_InitStruct_s);

	/*--------[ Calculate The PSC & ARR Values To Maximize PWM Resolution ]-------*/

	/* Those Equations Sets The F_pwm = 50Hz & Maximizes The Resolution*/
	l_PSC_Value_u32 = (uint32) (c_SERVO_CfgParam_s.TIM_CLK / 3276800.0);
	l_ARR_Value_u32 = (uint32) ((c_SERVO_CfgParam_s.TIM_CLK / (50.0*(l_PSC_Value_u32+1.0)))-1.0);

	/*--------[ Configure The Servo PWM Timer Channel ]-------*/

	/*--[Check The Timer & Enable Its Clock]--*/
	if(c_SERVO_CfgParam_s.TIM_Instance == TIM1)
	{
		__HAL_RCC_TIM1_CLK_ENABLE();
	}
	else if(c_SERVO_CfgParam_s.TIM_Instance == TIM2)
	{
		__HAL_RCC_TIM2_CLK_ENABLE();
	}
	else if(c_SERVO_CfgParam_s.TIM_Instance == TIM3)
	{
		__HAL_RCC_TIM3_CLK_ENABLE();
	}
	else if(c_SERVO_CfgParam_s.TIM_Instance == TIM4)
	{
		__HAL_RCC_TIM4_CLK_ENABLE();
	}

	g_TimerHandler_s.Instance = c_SERVO_CfgParam_s.TIM_Instance;
	g_TimerHandler_s.Init.Prescaler = l_PSC_Value_u32;
	g_TimerHandler_s.Init.CounterMode = TIM_COUNTERMODE_UP;
	g_TimerHandler_s.Init.Period = l_ARR_Value_u32;
	g_TimerHandler_s.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	g_TimerHandler_s.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
	HAL_TIM_Base_Init(&g_TimerHandler_s);
	l_ClockSourceConfig_s.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	HAL_TIM_ConfigClockSource(&g_TimerHandler_s, &l_ClockSourceConfig_s);
	HAL_TIM_PWM_Init(&g_TimerHandler_s);
	l_MasterConfig_s.MasterOutputTrigger = TIM_TRGO_RESET;
	l_MasterConfig_s.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	HAL_TIMEx_MasterConfigSynchronization(&g_TimerHandler_s, &l_MasterConfig_s);
	l_ConfigOC_s.OCMode = TIM_OCMODE_PWM1;
	l_ConfigOC_s.Pulse = 0;
	l_ConfigOC_s.OCPolarity = TIM_OCPOLARITY_HIGH;
	l_ConfigOC_s.OCFastMode = TIM_OCFAST_DISABLE;
	HAL_TIM_PWM_ConfigChannel(&g_TimerHandler_s, &l_ConfigOC_s, c_SERVO_CfgParam_s.PWM_TIM_CH);

	/*--------[ Calculate & Save The Servo Pulse Information ]-------*/

	g_SERVO_info_s.Period_Min_u16 = (uint16) (l_ARR_Value_u32 * (c_SERVO_CfgParam_s.MinPulse/20.0));
	g_SERVO_info_s.Period_Max_u16 = (uint16) (l_ARR_Value_u32 * (c_SERVO_CfgParam_s.MaxPulse/20.0));
}

void Cdd_Servo_Init(void)
{
	/*--------[ Start The PWM Channel ]-------*/
	HAL_TIM_PWM_Start(&g_TimerHandler_s, c_SERVO_CfgParam_s.PWM_TIM_CH);
}


/* Moves A Specific Motor To A Specific Degree That Can Be Float Number */
void Cdd_Servo_MoveTo(float32 Angle)
{
	uint16 l_Pulse_u16 = 0;

	l_Pulse_u16 = ((Angle*(g_SERVO_info_s.Period_Max_u16 - g_SERVO_info_s.Period_Min_u16))/180.0)
			+ g_SERVO_info_s.Period_Min_u16;

	*(c_SERVO_CfgParam_s.TIM_CCRx) = l_Pulse_u16;
}

/* Moves A Specific Motor With A Raw Pulse Width Value */
void Cdd_Servo_RawMove(uint16 Pulse)
{
	if(Pulse <= g_SERVO_info_s.Period_Max_u16 && Pulse >= g_SERVO_info_s.Period_Min_u16)
	{
		*(c_SERVO_CfgParam_s.TIM_CCRx) = Pulse;
	}
}

/* Gets The Maximum Pulse Width Value For A Specific Motor */
uint16 Cdd_Servo_Get_MaxPulse(void)
{
	return (g_SERVO_info_s.Period_Max_u16);
}


/* Gets The Minimum Pulse Width Value For A Specific Motor */
uint16 Cdd_Servo_Get_MinPulse(void)
{
	return (g_SERVO_info_s.Period_Min_u16);
}


/* Move A Motor From 0 deg to 180 And Back to 0 again */
void Cdd_Servo_Sweep(void)
{
	uint8 l_Angle_u8 = 0;

	Cdd_Servo_MoveTo(0);

	while(l_Angle_u8 < 180)
	{
		Cdd_Servo_MoveTo(l_Angle_u8++);
	}
	while(l_Angle_u8 > 0)
	{
		Cdd_Servo_MoveTo(l_Angle_u8--);
	}
}

void Cdd_Servo_MainFunction(void)
{

}
