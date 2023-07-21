/**
  * @file	Cdd_DCMotor.c
  * @author	cosmin.marcu
  * @date	Jul 20, 2023
  * @brief
  */

/* INCLUDES: */
#include "Cdd_DCMotor.h"
#include "Rte_Cdd_DCMotor.h"

/* DEFINES: */

// DC Motor PWM Properties
#define DC_MOTOR_PWM_RES  10
#define DC_MOTOR_F_PWM    500

// The Number OF DC MOTORs To Be Used In The Project
#define DC_MOTOR_UNITS  2

/* TYPES: */
typedef struct
{
	GPIO_TypeDef * DIR1_GPIO;
	GPIO_TypeDef * DIR2_GPIO;
	uint16_t       DIR1_PIN;
	uint16_t       DIR2_PIN;
	TIM_TypeDef*   TIM_Instance;
	uint32_t       PWM_TIM_CH;
	uint32_t       TIM_CLK_MHz;
	uint32_t       PWM_FREQ_Hz;
	uint8_t        PWM_RES_BITS;
}DC_MOTOR_CfgType;

/* VARIABLES: */
static boolean g_Cdd_DCMotor_InitDone_b = FALSE;							///< Module initialization flag

/* CONSTANTS: */
const DC_MOTOR_CfgType DC_MOTOR_CfgParam[DC_MOTOR_UNITS] =
{
	// DC MOTOR 1 Configurations
    {
	    GPIOA,
		GPIOA,
		GPIO_PIN_11,
		GPIO_PIN_12,
		TIM4,
		TIM_CHANNEL_1,
		72000000,
		DC_MOTOR_F_PWM,
		DC_MOTOR_PWM_RES
	},
	// DC MOTOR 2 Configurations
	{
		GPIOA,
		GPIOB,
		GPIO_PIN_1,
		GPIO_PIN_0,
		TIM4,
		TIM_CHANNEL_2,
		72000000,
		DC_MOTOR_F_PWM,
		DC_MOTOR_PWM_RES
	}
};

/* FUNCTIONS PROTOTYPES: */
static uint16 Cdd_DCMotor_ConvertSpeedToARR(uint8 ub_Speed);

/* STATIC FUNCTIONS: */
/**
  * @brief	Cdd_DCMotor_ConvertSpeedToARR speed conversion function
  * @param	ub_Speed DC Motor speed in percents
  * @return	ARR speed value
  */
static uint16 Cdd_DCMotor_ConvertSpeedToARR(uint8 ub_Speed)
{
	uint16 Speed_u16;
	if(ub_Speed < 100u)
	{
		Speed_u16 = (uint16)(ub_Speed * 599);
	}
	else
	{
		Speed_u16 = 59999;
	}

	return Speed_u16;
}
/* PUBLIC FUNCTIONS: */

/**
  * @brief	Cdd_DCMotor module initialization function
  * @return	None
  */
void Cdd_DCMotor_Driver_Init(void)
{
    DC_MOTOR_Init(DC_MOTOR_ID_0);
    DC_MOTOR_Init(DC_MOTOR_ID_1);
}

/**
  * @brief	Cdd_DCMotor module initialization function
  * @return	None
  */
void Cdd_DCMotor_Init(void)
{
    DC_MOTOR_Start(DC_MOTOR_ID_0, DC_MOTOR_DIR_CW, 0);
    DC_MOTOR_Start(DC_MOTOR_ID_1, DC_MOTOR_DIR_CW, 0);
	/* Set initialization flag to done */
	g_Cdd_DCMotor_InitDone_b = TRUE;
}

uint32 arr_val = 0;
void DC_MOTOR_Init(uint8 au8_MOTOR_Instance)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	TIM_ClockConfigTypeDef sClockSourceConfig = {0};
    TIM_MasterConfigTypeDef sMasterConfig = {0};
    TIM_OC_InitTypeDef sConfigOC = {0};
    TIM_HandleTypeDef htim;
    uint32 PSC_Value = 0;
    uint32 ARR_Value = 0;

	/*--------[ Configure The 2 Direction Control GPIO Pins ]-------*/

    if(DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR1_GPIO == GPIOA || DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR2_GPIO == GPIOA)
    {
    	__HAL_RCC_GPIOA_CLK_ENABLE();
    }
    else if(DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR1_GPIO == GPIOB || DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR2_GPIO == GPIOB)
    {
    	__HAL_RCC_GPIOB_CLK_ENABLE();
    }
    else if(DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR1_GPIO == GPIOC || DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR2_GPIO == GPIOC)
    {
        __HAL_RCC_GPIOC_CLK_ENABLE();
    }
    else if(DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR1_GPIO == GPIOD || DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR2_GPIO == GPIOD)
    {
        __HAL_RCC_GPIOD_CLK_ENABLE();
    }
    else if(DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR1_GPIO == GPIOE || DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR2_GPIO == GPIOE)
    {
        __HAL_RCC_GPIOE_CLK_ENABLE();
    }
	GPIO_InitStruct.Pin = DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR1_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR1_GPIO, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR2_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR2_GPIO, &GPIO_InitStruct);

	HAL_GPIO_WritePin(DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR1_GPIO, DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR1_PIN, 0);
	HAL_GPIO_WritePin(DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR2_GPIO, DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR2_PIN, 0);

	/*--------[ Calculate The PSC & ARR Values To Set PWM Resolution And Approx. The F_pwm ]-------*/

	/* Those Equations Sets The PWM Resolution & Approximates The F_pwm */
	/*
	ARR_Value = 1;
	for(i=0; i<DC_MOTOR_CfgParam[au8_MOTOR_Instance].PWM_RES_BITS; i++)
	{
		ARR_Value *= 2;
	}
	PSC_Value = (uint32_t) ((DC_MOTOR_CfgParam[au8_MOTOR_Instance].TIM_CLK_MHz*1000000) / (ARR_Value*DC_MOTOR_CfgParam[au8_MOTOR_Instance].PWM_FREQ_Hz));
	PSC_Value--;
	ARR_Value -= 2;
*/
	PSC_Value = 23;//(uint32) (DC_MOTOR_CfgParam[au8_MOTOR_Instance].TIM_CLK_MHz / 3600000.0);
	ARR_Value = (uint32) ((DC_MOTOR_CfgParam[au8_MOTOR_Instance].TIM_CLK_MHz / (50*(PSC_Value+1.0)))-1.0);

	arr_val = ARR_Value;
	/*--------[ Configure The DC Motor PWM Timer Channel ]-------*/

	htim.Instance = DC_MOTOR_CfgParam[au8_MOTOR_Instance].TIM_Instance;
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
	HAL_TIM_PWM_ConfigChannel(&htim, &sConfigOC, DC_MOTOR_CfgParam[au8_MOTOR_Instance].PWM_TIM_CH);
	HAL_TIM_MspPostInit(&htim);

	/*--------[ Start The PWM Channel ]-------*/

	HAL_TIM_PWM_Start(&htim, DC_MOTOR_CfgParam[au8_MOTOR_Instance].PWM_TIM_CH);
}

void DC_MOTOR_Start(uint8 au8_MOTOR_Instance, uint8 au8_DIR, uint8 au8_SPEED)
{
	uint16 au16_SPEED = Cdd_DCMotor_ConvertSpeedToARR(au8_SPEED);
	/* Write To The 2 Direction Control Pins */
	if(au8_DIR == DC_MOTOR_DIR_CW)
	{
		HAL_GPIO_WritePin(DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR1_GPIO, DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR1_PIN, 1);
		HAL_GPIO_WritePin(DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR2_GPIO, DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR2_PIN, 0);
	}
	else if(au8_DIR == DC_MOTOR_DIR_CCW)
	{
		HAL_GPIO_WritePin(DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR1_GPIO, DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR1_PIN, 0);
		HAL_GPIO_WritePin(DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR2_GPIO, DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR2_PIN, 1);
	}

	/* Write The Speed Value To The PWM CH DutyCycle Register */
	if(DC_MOTOR_CfgParam[au8_MOTOR_Instance].PWM_TIM_CH == TIM_CHANNEL_1)
	{
		DC_MOTOR_CfgParam[au8_MOTOR_Instance].TIM_Instance->CCR1 = au16_SPEED;
	}
	else if(DC_MOTOR_CfgParam[au8_MOTOR_Instance].PWM_TIM_CH == TIM_CHANNEL_2)
	{
		DC_MOTOR_CfgParam[au8_MOTOR_Instance].TIM_Instance->CCR2 = au16_SPEED;
	}
	else if(DC_MOTOR_CfgParam[au8_MOTOR_Instance].PWM_TIM_CH == TIM_CHANNEL_3)
	{
		DC_MOTOR_CfgParam[au8_MOTOR_Instance].TIM_Instance->CCR3 = au16_SPEED;
	}
	else
	{
		DC_MOTOR_CfgParam[au8_MOTOR_Instance].TIM_Instance->CCR4 = au16_SPEED;
	}
}

void DC_MOTOR_Set_Speed(uint8 au8_MOTOR_Instance, uint8 au8_SPEED)
{
	uint16 au16_SPEED = Cdd_DCMotor_ConvertSpeedToARR(au8_SPEED);
	/* Write The Speed Value To The PWM CH DutyCycle Register */
	if(DC_MOTOR_CfgParam[au8_MOTOR_Instance].PWM_TIM_CH == TIM_CHANNEL_1)
	{
		DC_MOTOR_CfgParam[au8_MOTOR_Instance].TIM_Instance->CCR1 = au16_SPEED;
	}
	else if(DC_MOTOR_CfgParam[au8_MOTOR_Instance].PWM_TIM_CH == TIM_CHANNEL_2)
	{
		DC_MOTOR_CfgParam[au8_MOTOR_Instance].TIM_Instance->CCR2 = au16_SPEED;
	}
	else if(DC_MOTOR_CfgParam[au8_MOTOR_Instance].PWM_TIM_CH == TIM_CHANNEL_3)
	{
		DC_MOTOR_CfgParam[au8_MOTOR_Instance].TIM_Instance->CCR3 = au16_SPEED;
	}
	else
	{
		DC_MOTOR_CfgParam[au8_MOTOR_Instance].TIM_Instance->CCR4 = au16_SPEED;
	}
}

void DC_MOTOR_Set_Dir(uint8 au8_MOTOR_Instance, uint8 au8_DIR)
{
	/* Write To The 2 Direction Control Pins */
	if(au8_DIR == DC_MOTOR_DIR_CW)
	{
		HAL_GPIO_WritePin(DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR1_GPIO, DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR1_PIN, 1);
		HAL_GPIO_WritePin(DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR2_GPIO, DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR2_PIN, 0);
	}
	else if(au8_DIR == DC_MOTOR_DIR_CCW)
	{
		HAL_GPIO_WritePin(DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR1_GPIO, DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR1_PIN, 0);
		HAL_GPIO_WritePin(DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR2_GPIO, DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR2_PIN, 1);
	}
	else
	{

	}
}

void DC_MOTOR_Stop(uint8 au8_MOTOR_Instance)
{
	/* Write To The 2 Direction Control Pins */
	HAL_GPIO_WritePin(DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR1_GPIO, DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR1_PIN, 0);
	HAL_GPIO_WritePin(DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR2_GPIO, DC_MOTOR_CfgParam[au8_MOTOR_Instance].DIR2_PIN, 0);

	/* Write ZERO To The PWM Ch DutyCycle Register */
	if(DC_MOTOR_CfgParam[au8_MOTOR_Instance].PWM_TIM_CH == TIM_CHANNEL_1)
	{
		DC_MOTOR_CfgParam[au8_MOTOR_Instance].TIM_Instance->CCR1 = 0;
	}
	else if(DC_MOTOR_CfgParam[au8_MOTOR_Instance].PWM_TIM_CH == TIM_CHANNEL_2)
	{
		DC_MOTOR_CfgParam[au8_MOTOR_Instance].TIM_Instance->CCR2 = 0;
	}
	else if(DC_MOTOR_CfgParam[au8_MOTOR_Instance].PWM_TIM_CH == TIM_CHANNEL_3)
	{
		DC_MOTOR_CfgParam[au8_MOTOR_Instance].TIM_Instance->CCR3 = 0;
	}
	else
	{
		DC_MOTOR_CfgParam[au8_MOTOR_Instance].TIM_Instance->CCR4 = 0;
	}
}

uint32 DC_MOTOR_Get_MaxFreq(uint8 au8_MOTOR_Instance)
{
    uint8 i = 0;
    uint32 ARR_Value = 1;
	for(i=0; i<DC_MOTOR_CfgParam[au8_MOTOR_Instance].PWM_RES_BITS; i++)
	{
		ARR_Value *= 2;
	}

	return ((DC_MOTOR_CfgParam[au8_MOTOR_Instance].TIM_CLK_MHz)/ARR_Value);
}

/**
  * @brief	Cdd_DCMotor module main function (runs in task)
  * @return	None
  */
int inc = 0;
uint32 freq = 0;
uint8 dir = 0;
void Cdd_DCMotor_MainFunction(void)
{
	/* Check if initialization is done */
	if(TRUE == g_Cdd_DCMotor_InitDone_b)
	{

		/*if(dir == 0)
		{
			inc= inc+1;
		}
		else
		{
			inc= inc-1;
		}

		if(inc > 100)
		{
			dir = 1;
		}
		if(inc < 1)
		{
			dir = 0;
		}

		DC_MOTOR_Set_Speed(DC_MOTOR_ID_0, inc);
		DC_MOTOR_Set_Speed(DC_MOTOR_ID_1, inc);*/

	}
}
/* END OF FILE */
