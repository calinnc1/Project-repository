/*
 * Rte.c
 *
 *  Created on: Oct 19, 2022
 *      Author: cosmin.marcu
 */

#include <string.h>
#include <stdio.h>

#include "Rte.h"
#include "Rte_Os.h"
#include "Rte_LED.h"
#include "Rte_Bsw_Int.h"

#include "EcuM.h"
#include "BswM.h"
#include "Cdd_Servo.h"

#include "Access.h"
#include "Engine.h"
#include "Brakes.h"
#include "Steering.h"

#include "Blinker.h"
#include "FrontLights.h"
#include "InteriorLights.h"
#include "RearLights.h"
#include "LED.h"

static volatile uint8 Int_ButtonState = 0;
static volatile uint16 Rte_ADC_AN0_Voltage = 0u;
extern UART_HandleTypeDef huart2;
extern ADC_HandleTypeDef hadc1;
char databuf[16];
uint16 count = 0;
uint8 crlf[1] = { 0x0A };

static inline void Rte_Call_EnterProtectedSection(void);
static inline void Rte_Call_LeaveProtectedSection(void);

static inline void Rte_Call_EnterProtectedSection(void)
{
	__disable_irq();
}

static inline void Rte_Call_LeaveProtectedSection(void)
{
	__enable_irq();
}

void Rte_Init(void)
{
	Int_ButtonState = (uint8)HAL_GPIO_ReadPin(BUTTON_GPIO_Port, BUTTON_Pin);
}

/* Os Tasks*/
/* Init task */
void Rte_Task_StartUp(void)
{
	/* EcuM startup two: MCal drivers init, BswM init */
	EcuM_StartUp_Two();

	/* Bsw stacks init */

	/* Rte init */
	Rte_Init();
	/* Cdd init */
	Cdd_Servo_Init();
	/* Asw init */
	Access_Init();
	Engine_Init();
	Brakes_Init();
	Steering_Init();
	Blinker_Init();
	FrontLights_Init();
	InteriorLights_Init();
	RearLights_Init();
	/* Init function of ASW module used for testing purposes. TODO: remove after tests */
	LED_Init();
}

/* Periodic tasks */
void Rte_Task_5ms(void)
{

}

void Rte_Task_10ms(void)
{
	/* BSW */
	BswM_MainFunction();
	/* CDD */
	Cdd_Servo_MainFunction();
	/* ASW */
	Access_MainFunction();
	Engine_MainFunction();
	Brakes_MainFunction();
	Steering_MainFunction();
	/* MainFunction of ASW module used for testing purposes. TODO: remove after tests */
	LED_MainFunction();
}

void Rte_Task_20ms(void)
{

}

void Rte_Task_50ms(void)
{

}

void Rte_Task_100ms(void)
{
	Blinker_MainFunction();
	FrontLights_MainFunction();
	InteriorLights_MainFunction();
	RearLights_MainFunction();
}

void Rte_Task_500ms(void)
{
	/* UART test section. TODO: remove */
	sprintf(databuf, "%4d X", count);
	databuf[strlen(databuf)] = 0;
	HAL_UART_Transmit(&huart2, (uint8 *)databuf, strlen(databuf), 1000);
	HAL_UART_Transmit(&huart2, crlf, 1, 1000);

	count++;
}


/* Toggle PA5 Pin state */
void Rte_Switch_PA5_Pin_State()
{
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
}

/* Read PC13 pin state - button state */
void Rte_Read_PC13_Pin_State(uint8 *state)
{
	*state = Int_ButtonState;
}

/* Save PC13 Pin state (called from IRQ) - TODO: change this */
void Rte_Write_PC13_Pin_State(uint8 state)
{
	Int_ButtonState = state;
}

void Rte_Cdd_Servo_RawMove(uint16 pulse)
{
	Cdd_Servo_RawMove(pulse);
}

void Rte_Write_AN0_Voltage_u16(uint16 voltage)
{
	Rte_ADC_AN0_Voltage = voltage;
}

void Rte_Read_AN0_Voltage_u16(uint16 *voltage)
{
	/* Disable interrupts */
	Rte_Call_EnterProtectedSection();
	/* Read ADC value */
	*voltage = Rte_ADC_AN0_Voltage;
	/* Enable interrupts */
	Rte_Call_LeaveProtectedSection();
}
