/*
 * Gpt.c
 *
 *  Created on: Oct 12, 2022
 *      Author: cosmin.marcu
 */

#include "Gpt.h"

volatile uint32_t tim3_count = 0u;
volatile uint32_t tim3_5count = 0u;
volatile uint32_t tim3_10count = 0u;
volatile uint32_t tim3_50count = 0u;
volatile uint32_t tim3_100count = 0u;
volatile uint32_t tim3_500count = 0u;

TIM_HandleTypeDef htim3;

static uint8_t Gpt_InitDone = 0u;

static void Gpt_TIM3_Init(void);
static void Gpt_Error_Handler(void);

void Gpt_Init(void)
{
	Gpt_TIM3_Init();
	Gpt_InitDone = 1u;
}

void Gpt_TIM3_Start_IT(void)
{
	if(1u == Gpt_InitDone)
	{
		HAL_TIM_Base_Start_IT(&htim3);
	}
}

void Gpt_TIM3_Stop_IT(void)
{
	if(1u == Gpt_InitDone)
	{
		HAL_TIM_Base_Stop_IT(&htim3);
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
	/* Increment HAL counter */
	HAL_IncTick();
	//TODO: Remove and redirect timer callback
	if(tim3_count == 9999)
	{
		tim3_count = 0u;
		tim3_5count = 0u;
		tim3_10count = 0u;
		tim3_50count = 0u;
		tim3_100count = 0u;
		tim3_500count = 0u;
	}
	else
	{
		tim3_count++;
	}

	if((tim3_count % 5) == 0u)
	{
		tim3_5count++;
	}

	if((tim3_count % 10) == 0u)
	{
		tim3_10count++;
	}

	if((tim3_count % 50) == 0u)
	{
		tim3_50count++;
	}

	if((tim3_count % 100) == 0u)
	{
		tim3_100count++;
	}

	if((tim3_count % 500) == 0u)
	{
		tim3_500count++;
	}
	//HAL_IncTick();
}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void Gpt_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 10;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 7200;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
	  Gpt_Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
	  Gpt_Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
	  Gpt_Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
static void Gpt_Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
