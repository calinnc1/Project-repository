/*
 * Platform_Types.h
 *
 *  Created on: Oct 21, 2022
 *      Author: cosmin.marcu
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#define E_OK        0x00
#define E_NOT_OK    0x01

#define NVM_REQ_PENDING 1
#define NVM_REQ_E_OK    0
#define NULL_PTR (void *)0


/**
* @brief The standard AUTOSAR type boolean shall be implemented on basis of an eight bits long unsigned integer.
* @implements boolean_type
*/
typedef unsigned char boolean;

/**
* @brief Unsigned 8 bit integer with range of 0 ..+255 (0x00..0xFF) - 8 bit
* @implements uint8_type
*/
typedef unsigned char uint8;

/**
* @brief Unsigned 16 bit integer with range of 0 ..+65535 (0x0000..0xFFFF) - 16 bit
* @implements uint16_type
*/
typedef unsigned short uint16;

/**
* @brief Unsigned 32 bit integer with range of 0 ..+4294967295 (0x00000000..0xFFFFFFFF) - 32 bit
* @implements uint32_type
*/
typedef unsigned long uint32;

/**
* @brief Signed 8 bit integer with range of -128 ..+127 (0x80..0x7F) - 7 bit + 1 sign bit
* @implements sint8_type
*/
typedef signed char sint8;

/**
* @brief Signed 16 bit integer with range of -32768 ..+32767 (0x8000..0x7FFF) - 15 bit + 1 sign bit
* @implements sint16_type
*/
typedef signed short sint16;

/**
* @brief Signed 32 bit integer with range of -2147483648.. +2147483647 (0x80000000..0x7FFFFFFF) - 31 bit + 1 sign bit
* @implements sint32_type
*/
typedef signed long sint32;

/**
* @brief Unsigned integer at least 8 bit long. Range of at least 0 ..+255 (0x00..0xFF) - 8 bit
* @implements uint8_least_type
*/
typedef unsigned long uint8_least;

/**
* @brief  Unsigned integer at least 16 bit long. Range of at least 0 ..+65535 (0x0000..0xFFFF) - 16 bit
* @implements uint16_least_type
*/
typedef unsigned long uint16_least;

/**
* @brief Unsigned integer at least 32 bit long. Range of at least 0 ..+4294967295 (0x00000000..0xFFFFFFFF) - 32 bit
* @implements uint32_least_type
*/
typedef unsigned long uint32_least;

/**
* @brief Signed integer at least 8 bit long. Range - at least -128 ..+127. At least 7 bit + 1 bit sign
* @implements sint8_least_type
*/
typedef signed long sint8_least;

/**
* @brief Signed integer at least 16 bit long. Range - at least -32768 ..+32767. At least 15 bit + 1 bit sign
* @implements sint16_least_type
*/
typedef signed long sint16_least;

/**
* @brief Signed integer at least 32 bit long. Range - at least -2147483648.. +2147483647. At least 31 bit + 1 bit sign
* @implements sint32_least_type
*/
typedef signed long sint32_least;

/**
* @brief 32bit long floating point data type
* @implements float32_type
*/
typedef float float32;

/**
* @brief 64bit long floating point data type
* @implements float64_type
*/
typedef double float64;


#endif /* #ifndef PLATFORM_TYPES_H_ */

