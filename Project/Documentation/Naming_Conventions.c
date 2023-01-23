/**
  * @file	  Coding_Rules.c
  * @author	  ciprian.farcas
  * @date	  Nov 17, 2022
  * @brief    This document is a template which explain how the code have to be write
  *           At this point is importnat to explain for what is created and used this file.
  * @version  1.0.0v
  */

/* INCLUDES: */

/* Header files which are a part of predefined program libraries shall be included using <>. */

#include <string.h>; 

 /* Header files which are a part of the source code generated in the software project shall be included with "". */

#include "Blinker.h"


/* DEFINES: */

#define COMPONENT_NAME_MACRONAME_TYPEOFVALUE   

#define CODING_RULES_MAX_U8    255u
#define CODING_RULES_MAX_U16   65535ul
#define CODING_RULES_MAX_U32   65535ull   /* AICI NU IS SIGUR */

/**
 * @brief  Get minimal value between `x` and `y`
 * @param  x: First value
 * @param  y: Second value
 * @return Minimal value between `x` and `y`
 */
#define CODING_RULES_MIN(x, y)            ((x) < (y) ? (x) : (y))

/**
 * @brief  This is a macro function for example
 * @param  parameter: Parameter of the mcaro
 * @return The value returned by the function
 */
#define CODING_RULES_MACRO_FUNCTION (parameter)       ComponentName_FunctionName(parameter)

/* TYPES: */

/* Structure */
typedef struct
{
 uint8  Var1Template_u8;  /* first variable used for... */
 uint16 Var2Template_u;   /* irst variable used for... */
 uint8  DummyHole_u8;     /* dummy variable to fill the hole */
}ComponentName_StructureName_st;   /* _st -> means structure type */

/* Enumeration */
typedef enum
{
    ELEMENT_NR0_E,
    ELEMENT_NR1_E,
    ELEMENT_NR2_E,
    ELEMENT_MAX_E    /* always declare _MAX for an enum */
}ComponentName_EnumeartionName_et; /* _et -> means enumeration type */

/* Union */
typedef  union
{
    uint16  Word_u16;      /* comment to explain for what is used */
    uint8   ByteZero_u8;   /* comment to explain for what is used */
    uint8   ByteOne_u8;    /* comment to explain for what is used */
}ComponentName_UnionName_ut; /* _ut -> means union type */


/* Structure and Enum Declaration */
ComponentName_StructureName_st    g_ComponentName_VarName_s;      /* global variable of type ComponentName_StructureName_st */
ComponentName_StructureName_st    g_ComponentName_VarName_as[];   /*global array of type ComponentName_StructureName_st */
ComponentName_StructureName_st*   g_ComponentName_VarName_ps;     /*global pointer to a variable of type ComponentName_StructureName_st */
ComponentName_StructureName_st*   g_ComponentName_VarName_pas[];  /*global pointer to an array of ComponentName_StructureName_st */

ComponentName_EnumeartionName_et g_ComponentName_VarName_e;       /* global variable of type g_ComponentName_VarName_e */

/* Structure and Enum usage */
g_ComponentName_VarName_s.Var1Template_u8 = 2;

g_ComponentName_VarName_e = ELEMENT_NR0_E;


/* VARIABLES: */

/* 
 * Variables can be:
 * globals   -> g_ComponentName_VariableNeme_Type;
 * locals    -> l_ComponentName_VariableNeme_Type;
 * constants -> c_ComponentName_VariableNeme_Type;
*/

boolean g_ComponentName_VarName_b;         /* boolean global variable */
uint8   g_ComponentName_VarName_u8;        /* uint8   global variable */
uint16  g_ComponentName_VarName_u16;       /* uint16  global variable */
uint32  g_ComponentName_VarName_u32;       /* uint32  global variable */
sint8   g_ComponentName_VarName_su8;       /* sint8   global variable */
sint16  g_ComponentName_VarName_su16;      /* sint16  global variable */
sint32  g_ComponentName_VarName_su32;      /* sint32  global variable */
boolean g_ComponentName_VarName_ab[];      /* boolean global array */
uint8   g_ComponentName_VarName_au8[];     /* uint8   global array */
uint16  g_ComponentName_VarName_au16[];    /* uint16  global array */
uint32  g_ComponentName_VarName_au32[];    /* uint32  global array */
sint8   g_ComponentName_VarName_as8[];     /* sint8   global array */
sint16  g_ComponentName_VarName_as16[];    /* sint16  global array */
sint32  g_ComponentName_VarName_as32[];    /* sint32  global array */

/* Pointers to variable, array or pointer */

boolean* g_ComponentName_VarName_pb;         /* global pointer to boolean variable*/
uint8*   g_ComponentName_VarName_pu8;        /* global pointer to uint8  variable */
uint16*  g_ComponentName_VarName_pu16;       /* global pointer to uint16 variable */
uint32*  g_ComponentName_VarName_pu32;       /* global pointer to uint32 variable */
sint8*   g_ComponentName_VarName_ps8;        /* global pointer to sint8  variable */
sint16*  g_ComponentName_VarName_ps16;       /* global pointer to sint16 variable */
sint32*  g_ComponentName_VarName_ps32;       /* global pointer to sint32 variable */
boolean* g_ComponentName_VarName_pab[];      /* global pointer to boolean array */
uint8*   g_ComponentName_VarName_pau8[];     /* global pointer to uint8  array */
uint16*  g_ComponentName_VarName_pau16[];    /* global pointer to uint16 array */
uint32*  g_ComponentName_VarName_pau32[];    /* global pointer to uint32 array */
sint8*   g_ComponentName_VarName_pas8[];     /* global pointer to sint8  array */
sint16*  g_ComponentName_VarName_pas16[];    /* global pointer to sint16 array */
sint32*  g_ComponentName_VarName_pas32[];    /* global pointer to sint32 array */

uint8**  g_ComponentName_VarName_ppu8;        /* global pointer to a pointer which is pointed to an uint8 */

/* FUNCTIONS PROTOTYPES: */

/* Syntax of function prototype and examples */

returnType ComponentName_FunctionName(type1 Argument1_t1, type2 Argument2_t2, ...);
static returnType ComponentName_FunctionName(type1 Argument1_t1, type2 Argument2_t2, ...);

void ComponentName_FunctionName(void);
uint8 CStyle_ChangeRules(uint8 Argument1_u8, ComponentName_StructureName_st Argument2_s );
static uint8 CStyle_ChangeRules(uint8 Argument1_u8, ComponentName_StructureName_st Argument2_s );


/* PUBLIC FUNCTIONS: */

/**
  * @name   CStyle_ChangeRules 
  * @brief	Function which change the rules inside the CStyle module.
  * @param Argument1 Is the first argument which help to chenage the rules in the module
  * @param Argument2 Is the second argument which help to chenage the rules int the module,
  *                  without this is impposible to do it.             
  * @return	uint8
  */
uint8 CStyle_ChangeRules(uint8 Argument1u168, ComponentName_StructureName_st Argument2_s )
{

/* Block of th function */

    /* OK */
    uint16 Idx1;
    uint16 Idx1;
    uint8  l_Var1_u8;
    uint8  l_Var1_u8;

for (Idx1 = 0; Idx < 5; ++Idx1) 
{
  uint8 l_Var1_u8++;
    for (Idx2 = 0; Idx < 5; ++Idx2) 
    {
      uint8 l_Var2_u8++;
    }
}


/* WRONG */
uint16 i;
uint8 var1;
for(i = 0; i < 5; ++i) 
{
    uint8 var1++;
}

}


/* get AND set */

/* 
 * Always use small characters for 'get' and 'set' and use this words
 * at the begining of the function name, like in example bellow
*/
returnType ComponentName_getFunctionName(type1 Argument1_t1, type2 Argument2_t2, ...);
returnType ComponentName_setFunctionName(type1 Argument1_t1, type2 Argument2_t2, ...);


/* END OF FILE */

