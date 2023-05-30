/*
 * Cdd_Servo.h
 *
 *  Created on: Nov 2, 2022
 *      Author: cosmin.marcu
 */

#ifndef BSW_CDD_CDD_SERVO_SERVO_H_
#define BSW_CDD_CDD_SERVO_SERVO_H_

#include "stm32f3xx_hal.h"
#include "Platform_Types.h"

typedef struct
{
	GPIO_TypeDef * 		SERVO_GPIO;
	uint16	       		SERVO_PIN;
	TIM_TypeDef*		TIM_Instance;
	volatile uint32*	TIM_CCRx;
	uint32       		PWM_TIM_CH;
	uint32       		TIM_CLK;
	float32         	MinPulse;
	float32        		MaxPulse;
} Cdd_Servo_CfgType;

extern void Cdd_Servo_Init(void);
extern void Cdd_Servo_Driver_Init(void);
extern void Cdd_Servo_MainFunction(void);
extern void Cdd_Servo_MoveTo(float32 Angle);
extern void Cdd_Servo_RawMove(uint16 Pulse);
extern uint16_t Cdd_Servo_Get_MaxPulse(void);
extern uint16_t Cdd_Servo_Get_MinPulse(void);
extern void Cdd_Servo_Sweep(void);

#endif /* BSW_CDD_CDD_SERVO_SERVO_H_ */
