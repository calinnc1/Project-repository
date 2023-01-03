/**
  * @file	Cdd_Ultrasonic.c
  * @author	cosmin.marcu
  * @date	Jan 3, 2023
  * @brief
  */

/* INCLUDES: */
#include "Cdd_Ultrasonic.h"
#include "Rte_Cdd_Ultrasonic.h"

/* DEFINES: */
#define CDD_ULTRASONIC_DISTANCE_SCALE_FACTOR_F32	(float32)0.017

/* TYPES: */
typedef struct
{
	uint8  	EDGE_STATE;
	uint16 	TMR_OVC;
	uint32 	TMR_PSC;
	uint32 	TMR_ARR;
	uint32 	T1;
	uint32 	T2;
	uint32 	DIFF;
	float32 DISTANCE;
	TIM_HandleTypeDef* HTIM;
	HAL_TIM_ActiveChannel ACTIV_CH;
}Cdd_Ultrasonic_Info_t;

/* VARIABLES: */
TIM_HandleTypeDef htim3;
static Cdd_Ultrasonic_Info_t g_Cdd_Ultrasonic_Info_s;						///< Ultrasonic info structure
static boolean g_Cdd_Ultrasonic_InitDone_b = FALSE;							///< Module initialization flag
static boolean g_Cdd_Ultrasonic_DriverInitDone_b = FALSE;					///< Module driver initialization flag
static uint8 g_Cdd_Ultrasonic_TriggerFlag_b = FALSE;

/* CONSTANTS: */
const Cdd_Ultrasonic_CfgType_t c_Cdd_Ultrasonic_CfgType_s =
{
		GPIOB,
		GPIO_PIN_12,
		TIM3,
		TIM_CHANNEL_1,
		72
};

/* FUNCTIONS PROTOTYPES: */
static void Cdd_Ultrasonic_Trigger(void);
static void Cdd_Ultrasonic_ISR_CaptureCallback(TIM_HandleTypeDef *htim);
static void Cdd_Ultrasonic_ISR_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

/* STATIC FUNCTIONS: */
/**
  * @brief	Cdd_Ultrasonic module trigger measurement function
  * @return	None
  */
static void Cdd_Ultrasonic_Trigger(void)
{
	Rte_Call_TriggerUltrasonicMeasurement();
}

/**
  * @brief	Cdd_Ultrasonic capture callback function
  * @return	None
  * @attention	Runs in ISR
  */
static void Cdd_Ultrasonic_ISR_CaptureCallback(TIM_HandleTypeDef *htim)
{
	uint32 l_PS_u32 = 0UL;

	if((htim->Instance == c_Cdd_Ultrasonic_CfgType_s.TIM_Instance) && (htim->Channel == g_Cdd_Ultrasonic_Info_s.ACTIV_CH))
	{
		if (g_Cdd_Ultrasonic_Info_s.EDGE_STATE == 0u)
		{
			/* Capture T1 & Reverse The ICU Edge Polarity */
			g_Cdd_Ultrasonic_Info_s.T1 = HAL_TIM_ReadCapturedValue(htim, c_Cdd_Ultrasonic_CfgType_s.IC_TIM_CH);
			g_Cdd_Ultrasonic_Info_s.EDGE_STATE = 1u;
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, c_Cdd_Ultrasonic_CfgType_s.IC_TIM_CH, TIM_INPUTCHANNELPOLARITY_FALLING);
			g_Cdd_Ultrasonic_Info_s.TMR_OVC = 0u;
		}
		else if (g_Cdd_Ultrasonic_Info_s.EDGE_STATE == 1u)
		{
			/* Read The Current ARR & Prescaler Values For The Timer */
			l_PS_u32 = c_Cdd_Ultrasonic_CfgType_s.TIM_Instance->PSC;
			g_Cdd_Ultrasonic_Info_s.TMR_ARR = c_Cdd_Ultrasonic_CfgType_s.TIM_Instance->ARR;
			/* Capture T2 & Calculate The Distance */
			g_Cdd_Ultrasonic_Info_s.T2 = HAL_TIM_ReadCapturedValue(htim, c_Cdd_Ultrasonic_CfgType_s.IC_TIM_CH);
			g_Cdd_Ultrasonic_Info_s.T2 += (g_Cdd_Ultrasonic_Info_s.TMR_OVC * (g_Cdd_Ultrasonic_Info_s.TMR_ARR+1u));
			g_Cdd_Ultrasonic_Info_s.DIFF = g_Cdd_Ultrasonic_Info_s.T2 - g_Cdd_Ultrasonic_Info_s.T1;
			/* Write The Distance Value To The Global Struct & Reverse The ICU Edge */
			g_Cdd_Ultrasonic_Info_s.DISTANCE = (g_Cdd_Ultrasonic_Info_s.DIFF * CDD_ULTRASONIC_DISTANCE_SCALE_FACTOR_F32)/(c_Cdd_Ultrasonic_CfgType_s.TIM_CLK_MHz/(l_PS_u32+1u));
			g_Cdd_Ultrasonic_Info_s.EDGE_STATE = 0u;
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, c_Cdd_Ultrasonic_CfgType_s.IC_TIM_CH, TIM_INPUTCHANNELPOLARITY_RISING);
		}
		else
		{
			/* Nothing to do */
		}
	}
}

/**
  * @brief	Cdd_Ultrasonic period elapsed callback function
  * @return	None
  * @attention	Runs in ISR
  */
static void Cdd_Ultrasonic_ISR_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == c_Cdd_Ultrasonic_CfgType_s.TIM_Instance)
	{
		g_Cdd_Ultrasonic_Info_s.TMR_OVC++;
	}
}

/* PUBLIC FUNCTIONS: */
/**
  * @brief	Cdd_Ultrasonic module initialization function
  * @return	None
  */
void Cdd_Ultrasonic_Init(void)
{
	if(TRUE == g_Cdd_Ultrasonic_DriverInitDone_b)
	{
		/*--------[ Start The ICU Channel ]-------*/
		HAL_TIM_Base_Start_IT(&htim3);
		HAL_TIM_IC_Start_IT(&htim3, c_Cdd_Ultrasonic_CfgType_s.IC_TIM_CH);
		/* Set initialization flag to done */
		g_Cdd_Ultrasonic_InitDone_b = TRUE;
	}
}

/**
  * @brief	Cdd_Ultrasonic module driver initialization function
  * @return	None
  */
void Cdd_Ultrasonic_Driver_Init(void)
{
	GPIO_InitTypeDef TRIG_GPIO_InitStruct = {0};
	TIM_ClockConfigTypeDef sClockSourceConfig = {0};
	TIM_MasterConfigTypeDef sMasterConfig = {0};
	TIM_IC_InitTypeDef sConfigIC = {0};

    /*--------[ Configure The HCSR04 TRIGGER GPIO Pin ]-------*/

    if(c_Cdd_Ultrasonic_CfgType_s.TRIG_GPIO == GPIOA)
    {
    	__HAL_RCC_GPIOA_CLK_ENABLE();
    }
    else if(c_Cdd_Ultrasonic_CfgType_s.TRIG_GPIO == GPIOB)
    {
    	__HAL_RCC_GPIOB_CLK_ENABLE();
    }
    else if(c_Cdd_Ultrasonic_CfgType_s.TRIG_GPIO == GPIOC)
    {
        __HAL_RCC_GPIOC_CLK_ENABLE();
    }
    else if(c_Cdd_Ultrasonic_CfgType_s.TRIG_GPIO == GPIOD)
    {
        __HAL_RCC_GPIOD_CLK_ENABLE();
    }
    else if(c_Cdd_Ultrasonic_CfgType_s.TRIG_GPIO == GPIOE)
    {
        __HAL_RCC_GPIOE_CLK_ENABLE();
    }
    TRIG_GPIO_InitStruct.Pin = c_Cdd_Ultrasonic_CfgType_s.TRIG_PIN;
    TRIG_GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    TRIG_GPIO_InitStruct.Pull = GPIO_NOPULL;
    TRIG_GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(c_Cdd_Ultrasonic_CfgType_s.TRIG_GPIO, &TRIG_GPIO_InitStruct);

	/*--------[ Initialize The HCSR04 Static Global Info ]-------*/

	g_Cdd_Ultrasonic_Info_s.TMR_PSC = c_Cdd_Ultrasonic_CfgType_s.TIM_Instance->PSC;
	g_Cdd_Ultrasonic_Info_s.TMR_ARR = c_Cdd_Ultrasonic_CfgType_s.TIM_Instance->ARR;
	g_Cdd_Ultrasonic_Info_s.TMR_OVC = 0u;
	g_Cdd_Ultrasonic_Info_s.HTIM = &htim3;
	if(g_Cdd_Ultrasonic_Info_s.TMR_ARR == 0u)
	{
		g_Cdd_Ultrasonic_Info_s.TMR_ARR = 65535u;
	}
	if(c_Cdd_Ultrasonic_CfgType_s.IC_TIM_CH == TIM_CHANNEL_1)
	{
		g_Cdd_Ultrasonic_Info_s.ACTIV_CH = HAL_TIM_ACTIVE_CHANNEL_1;
	}
	else if(c_Cdd_Ultrasonic_CfgType_s.IC_TIM_CH == TIM_CHANNEL_2)
	{
		g_Cdd_Ultrasonic_Info_s.ACTIV_CH = HAL_TIM_ACTIVE_CHANNEL_2;
	}
	else if(c_Cdd_Ultrasonic_CfgType_s.IC_TIM_CH == TIM_CHANNEL_3)
	{
		g_Cdd_Ultrasonic_Info_s.ACTIV_CH = HAL_TIM_ACTIVE_CHANNEL_3;
	}
	else if(c_Cdd_Ultrasonic_CfgType_s.IC_TIM_CH == TIM_CHANNEL_4)
	{
		g_Cdd_Ultrasonic_Info_s.ACTIV_CH = HAL_TIM_ACTIVE_CHANNEL_4;
	}

	/*--------[ Configure The HCSR04 IC Timer Channel ]-------*/
	htim3.Instance = c_Cdd_Ultrasonic_CfgType_s.TIM_Instance;
	htim3.Init.Prescaler = g_Cdd_Ultrasonic_Info_s.TMR_PSC;
	htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim3.Init.Period = g_Cdd_Ultrasonic_Info_s.TMR_ARR;
	htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
	HAL_TIM_Base_Init(&htim3);
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig);
	HAL_TIM_IC_Init(&htim3);
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig);
	sConfigIC.ICPolarity = TIM_INPUTCHANNELPOLARITY_RISING;
	sConfigIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
	sConfigIC.ICPrescaler = TIM_ICPSC_DIV1;
	sConfigIC.ICFilter = 0u;
	HAL_TIM_IC_ConfigChannel(&htim3, &sConfigIC, c_Cdd_Ultrasonic_CfgType_s.IC_TIM_CH);
	/* Set driver initialization flag to done */
	g_Cdd_Ultrasonic_DriverInitDone_b = TRUE;
}

/**
  * @brief	Cdd_Ultrasonic module main function (runs in task)
  * @return	None
  */
void Cdd_Ultrasonic_MainFunction(void)
{
	/* Check if initialization is done */
	if(TRUE == g_Cdd_Ultrasonic_InitDone_b)
	{
		/* Trigger measurement every 2nd cycle ( 20ms = 2 * task cycle ) */
		if(FALSE == g_Cdd_Ultrasonic_TriggerFlag_b)
		{
			/* Trigger measurement next cycle */
			g_Cdd_Ultrasonic_TriggerFlag_b = TRUE;
		}
		else
		{
			g_Cdd_Ultrasonic_TriggerFlag_b = FALSE;
			/* Call trigger function */
			Cdd_Ultrasonic_Trigger();
		}
	}
}

/**
  * @brief	Cdd_Ultrasonic module read distance function
  * @return	Last measured distance in centimeters
  */
float32 Cdd_Ultrasonic_ReadDistance(void)
{
	float32 l_Distance_f32 = 0.0f;
	l_Distance_f32 = g_Cdd_Ultrasonic_Info_s.DISTANCE;
	return l_Distance_f32;
}

/**
  * @brief	Cdd_Ultrasonic external capture callback function
  * @return	None
  * @attention	Runs in ISR
  */
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	Cdd_Ultrasonic_ISR_CaptureCallback(htim);
}

/**
  * @brief	Cdd_Ultrasonic external period elapsed callback function
  * @return	None
  * @attention	Runs in ISR
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
	Cdd_Ultrasonic_ISR_PeriodElapsedCallback(htim);
}
/* END OF FILE */
