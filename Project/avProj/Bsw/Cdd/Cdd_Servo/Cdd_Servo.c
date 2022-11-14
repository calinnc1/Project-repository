/*
 * Cdd_Servo.c
 *
 *  Created on: Nov 2, 2022
 *      Author: cosmin.marcu
 */

#include "Cdd_Servo.h"

typedef struct
{
	uint16_t  Period_Min;
	uint16_t  Period_Max;
}Cdd_Servo_info;

static Cdd_Servo_info gs_SERVO_info = {0};

const Cdd_Servo_CfgType SERVO_CfgParam =
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

void Cdd_Servo_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	TIM_ClockConfigTypeDef sClockSourceConfig = {0};
    TIM_MasterConfigTypeDef sMasterConfig = {0};
    TIM_OC_InitTypeDef sConfigOC = {0};
    TIM_HandleTypeDef htim;
    uint32 PSC_Value = 0;
    uint32 ARR_Value = 0;
    //DWT_Delay_Init();

	/*--------[ Configure The Servo PWM GPIO Pin ]-------*/

    if(SERVO_CfgParam.SERVO_GPIO == GPIOA)
    {
    	__HAL_RCC_GPIOA_CLK_ENABLE();
    }
    else if(SERVO_CfgParam.SERVO_GPIO == GPIOB)
    {
    	__HAL_RCC_GPIOB_CLK_ENABLE();
    }
    else if(SERVO_CfgParam.SERVO_GPIO == GPIOC)
    {
        __HAL_RCC_GPIOC_CLK_ENABLE();
    }
    else if(SERVO_CfgParam.SERVO_GPIO == GPIOD)
    {
        __HAL_RCC_GPIOD_CLK_ENABLE();
    }
    else if(SERVO_CfgParam.SERVO_GPIO == GPIOE)
    {
        __HAL_RCC_GPIOE_CLK_ENABLE();
    }
	GPIO_InitStruct.Pin = SERVO_CfgParam.SERVO_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
	HAL_GPIO_Init(SERVO_CfgParam.SERVO_GPIO, &GPIO_InitStruct);

	/*--------[ Calculate The PSC & ARR Values To Maximize PWM Resolution ]-------*/

	/* Those Equations Sets The F_pwm = 50Hz & Maximizes The Resolution*/
	PSC_Value = (uint32) (SERVO_CfgParam.TIM_CLK / 3276800.0);
	ARR_Value = (uint32) ((SERVO_CfgParam.TIM_CLK / (50.0*(PSC_Value+1.0)))-1.0);

	/*--------[ Configure The Servo PWM Timer Channel ]-------*/

	/*--[Check The Timer & Enable Its Clock]--*/
	if(SERVO_CfgParam.TIM_Instance == TIM1)
	{
		__HAL_RCC_TIM1_CLK_ENABLE();
	}
	else if(SERVO_CfgParam.TIM_Instance == TIM2)
	{
		__HAL_RCC_TIM2_CLK_ENABLE();
	}
	else if(SERVO_CfgParam.TIM_Instance == TIM3)
	{
		__HAL_RCC_TIM3_CLK_ENABLE();
	}
	else if(SERVO_CfgParam.TIM_Instance == TIM4)
	{
		__HAL_RCC_TIM4_CLK_ENABLE();
	}

	htim.Instance = SERVO_CfgParam.TIM_Instance;
	htim.Init.Prescaler = PSC_Value;
	htim.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim.Init.Period = ARR_Value;
	htim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
	HAL_TIM_Base_Init(&htim);
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	HAL_TIM_ConfigClockSource(&htim, &sClockSourceConfig);
	HAL_TIM_PWM_Init(&htim);
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	HAL_TIMEx_MasterConfigSynchronization(&htim, &sMasterConfig);
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = 0;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	HAL_TIM_PWM_ConfigChannel(&htim, &sConfigOC, SERVO_CfgParam.PWM_TIM_CH);

	/*--------[ Calculate & Save The Servo Pulse Information ]-------*/

	gs_SERVO_info.Period_Min = (uint16) (ARR_Value * (SERVO_CfgParam.MinPulse/20.0));
	gs_SERVO_info.Period_Max = (uint16) (ARR_Value * (SERVO_CfgParam.MaxPulse/20.0));

	/*--------[ Start The PWM Channel ]-------*/

	HAL_TIM_PWM_Start(&htim, SERVO_CfgParam.PWM_TIM_CH);
}

/* Moves A Specific Motor To A Specific Degree That Can Be Float Number */
void Cdd_Servo_MoveTo(float32 Angle)
{
	uint16 Pulse = 0;

	Pulse = ((Angle*(gs_SERVO_info.Period_Max - gs_SERVO_info.Period_Min))/180.0)
			+ gs_SERVO_info.Period_Min;

	*(SERVO_CfgParam.TIM_CCRx) = Pulse;
}

/* Moves A Specific Motor With A Raw Pulse Width Value */
void Cdd_Servo_RawMove(uint16 Pulse)
{
	if(Pulse <= gs_SERVO_info.Period_Max && Pulse >= gs_SERVO_info.Period_Min)
	{
		*(SERVO_CfgParam.TIM_CCRx) = Pulse;
	}
}

/* Gets The Maximum Pulse Width Value For A Specific Motor */
uint16 Cdd_Servo_Get_MaxPulse(void)
{
	return (gs_SERVO_info.Period_Max);
}


/* Gets The Minimum Pulse Width Value For A Specific Motor */
uint16 Cdd_Servo_Get_MinPulse(void)
{
	return (gs_SERVO_info.Period_Min);
}


/* Move A Motor From 0 deg to 180 And Back to 0 again */
void Cdd_Servo_Sweep(void)
{
	uint8 Angle = 0;

	Cdd_Servo_MoveTo(0);

	while(Angle < 180)
	{
		Cdd_Servo_MoveTo(Angle++);
	}
	while(Angle > 0)
	{
		Cdd_Servo_MoveTo(Angle--);
	}
}

void Cdd_Servo_MainFunction(void)
{

}
