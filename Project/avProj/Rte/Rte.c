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
#include "NvM.h"
#include "Ea.h"
#include "Cdd_Servo.h"
#include "Cdd_Ultrasonic.h"
#include "Cdd_DCMotor.h"

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
static volatile uint16 Rte_ADC_AN2_Voltage = 0u;
static volatile uint8 Rte_ADC_Switch = 0u;
extern UART_HandleTypeDef huart2;
extern ADC_HandleTypeDef hadc1;
extern const Cdd_Ultrasonic_CfgType_t c_Cdd_Ultrasonic_CfgType_s;
static uint8 g_Rte_CollisionWarning_Status_u8 = 0;
static boolean g_Rte_Autobrakes_Status_b;

/* NvM Blocks */
uint8	Rte_NvM_RAM_Block[RTE_NVM_RAM_BLOCK_ID_MAX_E][NVM_BLOCK_SIZE];

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
void Rte_Task_Master(void)
{
	/* EcuM startup two: MCal drivers init, BswM init */
	EcuM_StartUp_Two();

	/* Bsw stacks init */
	NvM_Init();
	Ea_Init();
	/* Rte init */
	Rte_Init();
	/* Cdd init */
	Cdd_Servo_Init();
	Cdd_Ultrasonic_Init();
	Cdd_DCMotor_Init();
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

	/* Add new ASW init functions here */
}

void Rte_Task_10ms(void)
{
	/* BSW */
	BswM_MainFunction();
	NvM_MainFunction();
	/* CDD */
	Cdd_Servo_MainFunction();
	Cdd_Ultrasonic_MainFunction();
	/* ASW */
	Access_MainFunction();
	Engine_MainFunction();
	Brakes_MainFunction();
	Steering_MainFunction();

}

void Rte_Task_50ms(void)
{
	/* MainFunction of ASW module used for testing purposes. TODO: remove after tests */
	LED_MainFunction();
	Cdd_DCMotor_MainFunction();
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

}

void Rte_Task_Shutdown(void)
{
	/* ASW Shutdown callbacks */
	LED_Shutdown();
	Brakes_Shutdown();

	/* BSW Shutdown callbacks */
}
/* CDD interfaces: Ultrasonic */
/* Cdd_Ultrasonic: Trigger measurement */
void Rte_Call_Cdd_Ultrasonic_TriggerMeasurement(void)
{
	HAL_GPIO_WritePin(c_Cdd_Ultrasonic_CfgType_s.TRIG_GPIO, c_Cdd_Ultrasonic_CfgType_s.TRIG_PIN, (GPIO_PinState)GPIO_PIN_SET);
	__asm("NOP");
	__asm("NOP");
	__asm("NOP");
	__asm("NOP");
	__asm("NOP");
	HAL_GPIO_WritePin(c_Cdd_Ultrasonic_CfgType_s.TRIG_GPIO, c_Cdd_Ultrasonic_CfgType_s.TRIG_PIN, (GPIO_PinState)GPIO_PIN_RESET);
}

/**
 * @brief  Cdd_Ultrasonic: Read ultrasonic distance
 * @param  distance: float32
 * @return None
 */
void Rte_Read_Cdd_Ultrasonic_Distance_f32(float32 *distance)
{
	*distance = Cdd_Ultrasonic_ReadDistance();
}

/**
 * @brief  Toggle PA5 Pin state
 * @param  None
 * @return None
 */
void Rte_Switch_PA5_Pin_State()
{
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
}

/**
 * @brief  Read PC13 pin state- button state
 * @param  state: uint8*
 * @return None
 */
void Rte_Read_PC13_Pin_State(uint8 *state)
{
	*state = Int_ButtonState;
}

/* Save PC13 Pin state (called from IRQ) - TODO: change this */
/**
 * @brief  Write PC13 pin state
 * @param  state: uint8
 * @return None
 */
void Rte_Write_PC13_Pin_State(uint8 state)
{
	Int_ButtonState = state;
}

/**
 * @brief  Read PC6 pin state- joystick switch
 * @param  state: uint8*
 * @return None
 */
void Rte_Read_PC6_Pin_State(uint8 *state)
{
	*state = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6);
}

/**
 * @brief  Read collision status
 * @param  status: uint8*
 * @return None
 */
void Rte_Read_g_CollisionWarning_Status(uint8 *status)
{
	*status = g_Rte_CollisionWarning_Status_u8;
}

/**
 * @brief  Write collision status
 * @param  status: uint8
 * @return None
 */
void Rte_Write_g_CollisionWarning_Status(uint8 status)
{
	g_Rte_CollisionWarning_Status_u8 = status;
}

void Rte_Read_DIO_Autobrakes_State_b(boolean *state)
{
	*state = g_Rte_Autobrakes_Status_b;
}

/**
 * @brief  Write PC2 pin state
 * @param  state: boolean
 * @return None
 */
void Rte_Write_PC_2(boolean state)
{
	if(FALSE == state)
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);
	}
}

/**
 * @brief  Write PC3 pin state
 * @param  state: boolean
 * @return None
 */
void Rte_Write_PC_3(boolean state)
{
	if(FALSE == state)
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
	}
}

/**
 * @brief  Write PC6 pin state
 * @param  state: boolean
 * @return None
 */
void Rte_Write_DIO_Autobrakes_State_b(boolean state)
{
	g_Rte_Autobrakes_Status_b = state;
}

void Rte_Cdd_Servo_RawMove(uint16 pulse)
{
	Cdd_Servo_RawMove(pulse);
}

void Rte_Read_NvM_Block(uint16 blockID, uint8 *data)
{
	/* TODO:	- remove direct read <- should be done by ReadAll
	 * 			- add block update after write
	 */
	NvM_ReadBlock(blockID, Rte_NvM_RAM_Block[blockID]);
	data = &Rte_NvM_RAM_Block[blockID][0u];
}

void Rte_Write_NvM_Block(uint16 blockID, uint8 *data)
{
	NvM_WriteBlock(blockID, data);
}

/**
 * @brief  Write analogic 0 pin
 * @param  voltage: uint16
 * @return None
 */
void Rte_Write_AN0_Voltage_u16(uint16 voltage)
{
	Rte_ADC_AN0_Voltage = voltage;
}

/**
 * @brief  Read analogic 0 pin
 * @param  voltage: uint16*
 * @return None
 */
void Rte_Read_AN0_Voltage_u16(uint16 *voltage)
{
	/* Disable interrupts */
	Rte_Call_EnterProtectedSection();
	/* Read ADC value */
	*voltage = Rte_ADC_AN0_Voltage;
	/* Enable interrupts */
	Rte_Call_LeaveProtectedSection();
}

/**
 * @brief  Write analogic 2 pin
 * @param  voltage: uint16
 * @return None
 */
void Rte_Write_AN2_Voltage_u16(uint16 voltage)
{
	Rte_ADC_AN2_Voltage = voltage;
}

/**
 * @brief  Read analogic 2 pin
 * @param  voltage: uint16*
 * @return None
 */
void Rte_Read_AN2_Voltage_u16(uint16 *voltage)
{
	/* Disable interrupts */
	Rte_Call_EnterProtectedSection();
	/* Read ADC value */
	*voltage = Rte_ADC_AN2_Voltage;
	/* Enable interrupts */
	Rte_Call_LeaveProtectedSection();
}


/**
 * @brief  Read DO pin form remote controller
 * @param  status: uint8*
 * @return None
 */
void Rte_Read_Remote_D0(uint8 *status)
{
	*status = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7);
}

/**
 * @brief  Read D1 pin from remote controller
 * @param  status: uint8*
 * @return None
 */
void Rte_Read_Remote_D1(uint8 *status)
{
	*status = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3);
}

/**
 * @brief  Read D2 pin from remote controller
 * @param  status: uint8*
 * @return None
 */
void Rte_Read_Remote_D2(uint8 *status)
{
	*status = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_9);
}

/**
 * @brief  Read D3 pin from remote controller
 * @param  status: uint8*
 * @return None
 */
void Rte_Read_Remote_D3(uint8 *status)
{
	*status = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4);
}

/**
 * @brief  Write Green pin state, on pin PB13
 * @param  status: uint8*
 * @return None
 */
void Rte_Write_PB_13(boolean state)
{
	if(TRUE == state)
	{
		HAL_GPIO_WritePin(GPIOB, LED_AUTOBRAKES_GREEN, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOB, LED_AUTOBRAKES_GREEN, GPIO_PIN_RESET);
	}
}

/**
 * @brief  Write Yellow pin state, on pin PB14
 * @param  status: uint8*
 * @return None
 */
void Rte_Write_PB_14(boolean state)
{
	if(TRUE == state)
	{
		HAL_GPIO_WritePin(GPIOB, LED_AUTOBRAKES_YELLOW, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOB, LED_AUTOBRAKES_YELLOW, GPIO_PIN_RESET);
	}
}

/**
 * @brief  Write Red pin state, on pin PB15
 * @param  status: uint8*
 * @return None
 */
void Rte_Write_PB_15(boolean state)
{
	if(TRUE == state)
	{
		HAL_GPIO_WritePin(GPIOB, LED_AUTOBRAKES_RED, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOB, LED_AUTOBRAKES_RED, GPIO_PIN_RESET);
	}
}

void Rte_Call_DCMotor_Start(uint8 au8_MOTOR_Instance, uint8 au8_DIR, uint8 au8_SPEED)
{
	DC_MOTOR_Start(au8_MOTOR_Instance, au8_DIR, au8_SPEED);
}

void Rte_Call_DCMotor_Set_Speed(uint8 au8_MOTOR_Instance, uint8 au8_SPEED)
{
	DC_MOTOR_Set_Speed(au8_MOTOR_Instance, au8_SPEED);
}

void Rte_Call_DCMotor_Set_Dir(uint8 au8_MOTOR_Instance, uint8 au8_DIR)
{
	DC_MOTOR_Set_Dir(au8_MOTOR_Instance, au8_DIR);
}

void Rte_Call_DCMotor_Stop(uint8 au8_MOTOR_Instance)
{
	DC_MOTOR_Stop(au8_MOTOR_Instance);
}
