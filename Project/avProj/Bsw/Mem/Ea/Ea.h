/**
  * @file	Ea.h
  * @author	cosmin.marcu
  * @date	Nov 16, 2022
  * @brief
  */

#ifndef BSW_MEM_EA_EA_H_
#define BSW_MEM_EA_EA_H_

#include "Platform_Types.h"

extern void Ea_Init(void);
extern void Ea_Write(uint16 Block_Id, uint8 *data);
extern void Ea_Read(uint16 Block_Id, uint8 *data);

#endif /* BSW_MEM_EA_EA_H_ */
