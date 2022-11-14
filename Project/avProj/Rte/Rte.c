/*
 * Rte.c
 *
 *  Created on: Oct 19, 2022
 *      Author: cosmin.marcu
 */


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

#include "LED.h"

static volatile uint8 Int_ButtonState = 0;

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

}

void Rte_Task_500ms(void)
{

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
