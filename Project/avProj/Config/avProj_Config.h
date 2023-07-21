/*
 * avProj_Config.h
 *
 *  Created on: Oct 10, 2022
 *      Author: cosmin.marcu
 */

#ifndef CONFIG_AVPROJ_CONFIG_H_
#define CONFIG_AVPROJ_CONFIG_H_

#define BUTTON_Pin GPIO_PIN_13
#define BUTTON_GPIO_Port GPIOC
#define BUTTON_EXTI_IRQn EXTI15_10_IRQn
#define LED_Pin GPIO_PIN_5
#define LED_GPIO_Port GPIOA

#define LED_AUTOBRAKES_GREEN GPIO_PIN_13
#define LED_AUTOBRAKES_YELLOW GPIO_PIN_14
#define LED_AUTOBRAKES_RED GPIO_PIN_15

/* DC motors Config */
#define DC_MOTOR_DIR_CW    0
#define DC_MOTOR_DIR_CCW   1

#define DC_MOTOR_ID_0    0
#define DC_MOTOR_ID_1    1

#endif /* CONFIG_AVPROJ_CONFIG_H_ */
