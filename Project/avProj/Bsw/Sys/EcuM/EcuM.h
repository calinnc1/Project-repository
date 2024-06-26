/*
 * EcuM.h
 *
 *  Created on: Oct 10, 2022
 *      Author: cosmin.marcu
 */

#ifndef BSW_SYS_ECUM_ECUM_H_
#define BSW_SYS_ECUM_ECUM_H_
#include "stm32f3xx_hal.h"
#include "avProj_Config.h"
#include "Os.h"

extern int EcuM_Init(void);
extern void EcuM_StartUp_One(void);
extern void EcuM_StartUp_Two(void);

#endif /* BSW_SYS_ECUM_ECUM_H_ */
