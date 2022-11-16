/**
  * @file	NvM.h
  * @author	cosmin.marcu
  * @date	Nov 16, 2022
  * @brief
  */

#ifndef BSW_MEM_NVM_NVM_H_
#define BSW_MEM_NVM_NVM_H_

#include "Platform_Types.h"

extern void NvM_Init(void);
extern void NvM_MainFunction(void);
extern void NvM_WriteBlock(uint16 BlockId, uint8 *NvM_SrcPtr);
extern void NvM_ReadBlock(uint16 BlockId, uint8 *NvM_SrcPtr);
#endif /* BSW_MEM_NVM_NVM_H_ */
