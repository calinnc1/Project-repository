/**
  * @file	Cdd_Ultrasonic.h
  * @author	cosmin.marcu
  * @date	Jan 3, 2023
  * @brief
  */

#ifndef BSW_CDD_CDD_ULTRASONIC_CDD_ULTRASONIC_H_
#define BSW_CDD_CDD_ULTRASONIC_CDD_ULTRASONIC_H_

#include "stm32f3xx_hal.h"
#include "Platform_Types.h"

typedef struct
{
	GPIO_TypeDef* 	TRIG_GPIO;
	uint16       	TRIG_PIN;
	TIM_TypeDef*   	TIM_Instance;
	uint32       	IC_TIM_CH;
	uint32       	TIM_CLK_MHz;
}Cdd_Ultrasonic_CfgType_t;

extern void Cdd_Ultrasonic_Init(void);
extern void Cdd_Ultrasonic_MainFunction(void);
extern void Cdd_Ultrasonic_Driver_Init(void);
extern float32 Cdd_Ultrasonic_ReadDistance(void);

#endif /* BSW_CDD_CDD_ULTRASONIC_CDD_ULTRASONIC_H_ */
