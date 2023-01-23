
# Recommended C coding rules for the NUCLEO project
# C styles are shown in `C_Style.c` and `C_Style.h`


## Table of Contents

  - [General rules](#general-rules)
  - [Comments](#comments)
  - [Functions](#functions)
  - [Variables](#variables)
  - [Structures, enumerations, typedefs](#structures-enumerations-typedefs)
  - [Compound statements](#compound-statements)
  - [Switch statement](#switch-statement)
  - [Macros and preprocessor directives](#macros-and-preprocessor-directives)


## General rules

Here are listed most obvious and important general rules. Please check them carefully before you continue with other chapters.
## THE MOST IMPORTANT RULE IS TO RESPECT THE RULES !!! ##
```c
- The language within source files shall be English throughout.
- Use `C99` standard
- Do not use tabs, use spaces instead
- Use `4` spaces per indent level
- Use `1` space between keyword and opening bracket
- Always curly brakets have to start with one line bellow
- Always when align comments they have to start afther `4` space/ 1 indent level from longest row from a grup
- When a macro is defined as function use `3` indention or `3*4 = 12` space. If are more than one aligne like in example bellow.
- When declare a variable, it have to be initialized
- The interface file shall have the extension ".h" and the body file shall have the extension ".c".
- There should not be more than one declaration on a line. -> Clear implementation
   uint8_t blockIndex, lastBlock; /* violation */
- Brackets shall always be used in complex expressions even if the C priority rules do not necessarily demand this for operators.
  This also applies to expressions evaluated by the preprocessor.
   if ( (counter1 > 0) || (counter2 < 0) )
   ...
   #if (SEC_SECURITY == C) || (SEC_SECURITY_CLASS == CCC)
   ...
   #endif
- Do not insert a "blank" before (or after) the "." and the "->" operators.
  This will harmonise the code style from different vendors, allowing easier reading and tool driven code checks
- Operators "++", "--", "&" (functionAddress) , "*" (FunctionRef) shall be stuck to their operand.
  Common notation for all Autosar source code makes it easier to review and automate for tool checks.
- Unary operators "!" and "~" (operators that only have a right operand) shall be stuck to their operand.
  Avoid confusion with a binary operator.
   if( ! computedBytes ) /* violation */
- Violations of MISRA rules shall be commented and reasoned at the corresponding code line.
- Identifiers shall not contain the '_' character twice in succession.
- Constants defined as a macro shall be written in upper case. Digits and underscores are allowed but not at the start.
- Each header file shall protect itself against multiple inclusion.
  Avoid multiple re-definitions.
   #ifndef FILENAME_H 
   #define FILENAME_H 
   ..... 
   #endif /* FILENAME_H */
- Each module shall include its own header file.
  This is the only way of allowing the compiler to check for consistency between declaration and definition of global variables and functions.
- A ".c" file shall not be included in another file: it shall be compiled and provided as an object module.
- A declaration with storage-class specifier "extern" shall exist for each global function in the header file of the module.
  Allow access to global functions by including the header file of the defining module.
- External declarations of global variables shall be done in header files and NEVER in .c files.
  Provide access to global variables by including the header file of the module that defines the global variables.
- Functions (other than macros) shall not be defined within in a ".h" file.
  Exception:
  Definitions of inline functions in the header file are permitted.
- Variables shall not be defined within in a ".h" file. They shall be defined within the module’s C file.
  Rationale:
  Prevent multiple variables, i.e. linker problem
- Declarations of functions shall always be stated with detailed parameter list, i.e. the type and a practical designation of the relevant parameters.
  Designator names in C and H file shall be identical.
- Declaration and definition of local functions shall have the storage-class specifier “static”.
  Local function means function with internal linkage (only visible inside the module).
- Each self-defined type has to have an explicit type declaration even if there is only one variable of this type.
- Multiple assignments shall not be done.
   x = y = z; /* violation */
- The use of ‘++’ and ‘--‘ should be limited to simple cases. They shall not be used in statements where other operators occur. The prefix use is always forbidden.
  This rule only belongs to ‘++’ and ‘--‘. Statements like ‘+=’ are excluded.
  x -= y++; /* violation */
```c
/* OK */
if (condition)                 /* if condition */
{
    /*...*/
}
while (condition)              /* While loop */
{
    /*...*/
}
for (init; condition; step)    /* for loop (the longest line form a grup)) */
{
    /*...*/
}
do
{
    /*...*/
} while (condition)            /* do while loop*/

/* WRONG */
if(condition)
while(condition)
for(init;condition;step)
do{} while(condition)

#define MARCRO_FUNCTION (x)            foo(param)

/* More than one macro function */
#define MARCRO_FUNCTION      (x)               foo(param)
#define MARCRO_FUNCTION_LONG (x, y)            foo(param)


```

- Do not use space between function name and opening bracket
```c
int32_t a = sum(4, 3);     /* OK */
int32_t a = sum (4, 3);    /* WRONG */
```

- Never use `__` or `_` prefix for variables/functions/macros/types. This is reserved for C language itself
    - Prefer `prv_` name prefix for strictly module-private functions
- Use only lowercase characters for variables/functions/macros/types with optional underscore `_` char
- Opening curly bracket is always one line bellow as keyword (`for`, `while`, `do`, `switch`, `if`, `function`...)
```c
size_t i;
for (i = 0; i < 5; ++i) 
{
    /* OK */
}

for (i = 0; i < 5; ++i){  /* WRONG */
}
```

- Use single space before and after comparison and assignment operators
```c
int32_t a;
a = 3 + 4;                  /* OK */
for (a = 0; a < 5; ++a)     /* OK */

a=3+4;               /* WRONG */
a = 3+4;             /* WRONG */
for (a=0;a<5;++a)    /* WRONG */

```
- Use single space after every comma
```c
func_name(5, 4);    /* OK */
func_name(4,3);     /* WRONG */

```
- Do not initialize `static` and `global` variables to `0` (or `NULL`), let compiler do it for you
```c
static int32_t a;        /* OK */
static int32_t b = 4;    /* OK */
static int32_t a = 0;    /* WRONG */

void MyFunc(void)
{
    static int32_t* ptr;    /* OK */
    static char abc = 0;    /* WRONG */
}
```

- Declare all local variables on the independent line
```c
void MyFunc(void) 
{
    char a;       /* OK */
    char b;       /* WRONG */
    char a, b;    /* WRONG */
}

```
- Declare local variables in order
    1. Custom structures and enumerations
    2. Integer types, wider unsigned type first
    3. Single/Double floating point
- Intialzize all the local variables
- Align all the variables and the comments
```c
int MyFunc(void) 
{
    /* 1 */
    MyStruct_st      my = {0};      /* First custom structures */
    MyStruct_st*     p = {NULL};    /* Pointers too */
    /* 2 */
    uint32_t a = 0;
    int32_t  b = 0;
    uint16_t c = 0;
    int16_t  g = 0;
    char     h = 0;
    /* ... */
    /* 3 */
    double   d = 0;
    float    f = 0;
}

```
- Always declare local variables at the beginning of the block, before first executable statement
- DO NOT declare counter variables in `for` loop
- All counter variables have to be `uint16`
```c

/* OK */
uint16_t Idx;
for (Idx = 0; Idx < 10; ++Idx)
{
    if (...) 
    {
        break;
    }
}
if (Idx == 10)
{

}

/* WRONG */
for (size_t i = 0; i < 10; ++i)
```

- Avoid variable assignment with function call in declaration, except for single variables
```c
void MyFunc(void)
{
    /* Avoid function calls when declaring variable */
    int32_t a, b = sum(1, 2);

    /* Use this */
    int32_t a = 0;
    int32_t b = 0;
    b = sum(1, 2);

    /* This is NOT ok */
    uint8_t a = 3, b = 4;
}

```
- Except `char`, `float` or `double`, always use types declared in `stdint.h` library, eg. `uint8_t` for `unsigned 8-bit`, etc.
- Do not use `stdbool.h` library. Use `1` or `0` for `true` or `false` respectively
```c
/* OK */
uint8_t status = 0;
status = 5;

/* WRONG */
#include <stdbool.h>
bool status = true;

```
- Never compare against `true`, eg. `if (check_func() == TRUE)`, use `if (check_func() != FALSE) { ... }`
- Always compare pointers against `NULL` value
```c
/* OK */
if (check_func() != FALSE)
{
    /*  */
}

/* WRONG */
if (check_func() == TRUE)
{
    /*  */
}

void* ptr;
/* OK, compare against NULL */
if (ptr == NULL || ptr != NULL)
{
    /* ... */
}

/* WRONG */
if (ptr || !ptr)
{
    /* ... */
}

```
- Always use `size_t` for length or size variables
- Always use `const` for pointer if function should not modify memory pointed to by `pointer`
- Always use `const` for function parameter or variable, if it should not be modified
```c

/* When d could be modified, data pointed to by d could not be modified */
void MyFunc(const void* d)
{
    /* ... */
}

/* When d and data pointed to by d both could not be modified */
void MyFunc(const void* const d)
{
    /* ... */
}

/* Not required, it is advised */
void MyFunc(const size_t len)
{
    /* ... */
}

/* When d should not be modified inside function, only data pointed to by d could be modified */
void MyFunc(void* const d)
{
    /* ... */
}

```
- When function may accept pointer of any type, always use `void *`, do not use `uint8_t *`
- Function must take care of proper casting in implementation
```c
/*
 * To send data, function should not modify memory pointed to by `data` variable
 * thus `const` keyword is important
 *
 * To send generic data (or to write them to file)
 * any type may be passed for data,
 * thus use `void *`
 */

/* OK example */
void SendData(const void* data, size_t len)
{ /* OK */
    /* Do not cast `void *` or `const void *` */
    const uint8_t* d = data;/* Function handles proper type for internal usage */
}

/* WRONG, not not use int */
void SendData(const void* data, int len)
{
    /* ... */
}
```
- Always compare variable against zero, except if it is treated as `boolean` type
- Never compare `boolean-treated` variables against zero or one. Use NOT (`!`) instead
```c
size_t length = 5;  /* Counter variable */
uint8_t is_ok = 0;  /* Boolean-treated variable */
if (length)         /* WRONG, length is not treated as boolean */
if (length > 0)     /* OK, length is treated as counter variable containing multi values, not only 0 or 1 */
if (length == 0)    /* OK, length is treated as counter variable containing multi values, not only 0 or 1 */

if (is_ok)          /* OK, variable is treated as boolean */
if (is_not_ok)      /* OK, -||- */
if (is_ok == 1)     /* WRONG, never compare boolean variable against 1! */
if (is_ok == 0)     /* WRONG, use ! for negative check */

```
- Always use `/* comment */` for comments, even for *single-line* comment
- Every function must include *doxygen-enabled* comment, even if function is `static`
- Use English names/text for functions, variables, comments
- Use first characters Uppercase for variables
- Use first character Uppercase for each word if variable contains multiple names, OK eg. `ForceRedraw` NOT OK `forceRedraw`
- Never cast function returning `void *`, eg. `uint8_t* ptr = (uint8_t *)func_returning_void_ptr();` as `void *` is safely promoted to any other pointer type
    - Use `uint8_t* ptr = func_returning_void_ptr();` instead
- Always use `<` and `>` for C Standard Library include files, eg. `#include <stdlib.h>`
- When casting to pointer type, always align asterisk to type, eg. `uint8_t* t = (uint8_t*)var_width_diff_type`
- Always respect code style already used in project or library

## Comments

- Comments starting with `//` are not allowed. Always use `/* comment */`, even for single-line comment
```c
//This is comment (wrong)
/* This is comment (ok) */
```

- For multi-line comments use `space+asterisk` for every line
```c
/*
 * This is multi-line comments,
 * written in 2 lines (ok)
 */

/**
 * WRONG, use double-asterisk only for doxygen documentation
 */

/*
* Single line comment without space before asterisk (wrong)
*/

/*
 * Single line comment in multi-line configuration (wrong)
 */

/* Single line comment (ok) */

```
## Functions

- Every function which may have access from outside its module, must include function *prototype* (or *declaration*)
- Function name must be :
 ```c
 returnType ComponentName_FunctionName(type1 Argument1, type2 Argument2, ...);

/* Ok */
void MyFunc(void);

/* WRONG */
void MyFunc(void);
void myfunc(void);



```
- When function returns pointer, align asterisk to return type
```c
/* OK */
const char* MyFunc(void);
MyStruct_st* MyFunc(int32_t a, int32_t b);

/* WRONG */
const char *MyFunc(void);
MyStruct_st * MyFunc(void);

```
- Align all function prototypes (with the same/similar functionality) for better readability
- When function is setter or getter function use always `set` or `get` with *lowercase* in function name
```c
/* OK, function names aligned */
void        ComponentName_setFunctionName(int32_t a);
MyType_t    ComponentName_getFunctionName(void);
MyPtr_t*    ComponentName_getFunctionName(void);

/* WRONG */
void set(int32_t a);
const char * get(void);

```
- Function implementation must include return type and optional other keywords in separate line
```c
/* OK */
int32_t foo(void) 
{
    
    return 0;
}

/* OK */
static const char* getString(void) 
{
    return "Hello world!\r\n";
}

/* WRONG */
int32_t foo(void) {
    return 0;
}

```
- When new typedef is introduced for function handles, use `_fn` suffix
```c
/* Function accepts 2 parameters and returns uint8_t */
/* Name of typedef has `_fn` suffix */
typedef uint8_t (*MyFunc_typedef_fn)(uint8_t p1, const char* p2);

```
## Variables

- Group local variables together by `type`
- Initialize all the variables
- Do not declare more than one variable on single line
- Aligne all of them 
- Start first with special types definded by project
- use indent of `4- spaces`
```c
/* OK */
void foo(void)
{
    MyStruct_t  a  = {0};
    MyStruct_t* pa = {NULL};
    MyStruct_t* pb = {NULL};
    int32_t     a  = 0; 
    int8_t      a  = 0;
    char        b  = 0;
}
  /* WRONG */
void foo(void)
{
    MyStruct_t* pa;
 MyStruct_t * pb;
  int32_t a; 
    char   a,c,d;
    char        b=0;
    MyStruct_t  a;
}

```
- Do not declare variable after first executable statement
```c
void foo(void)
{
   int32_t a = 0;
    a = bar();
    int32_t b = 0;      /* WRONG, there is already executable statement */
}
```
- You may declare new variables inside next indent level
```c
int32_t a;
a = foo();
if (a)
{
    int32_t c = 0; 
    int16_t d = 0;   /* OK, c and d are in if-statement scope */
    c = foo();
    int32_t e = 0;   /* WRONG, there was already executable statement inside block */
}

```
- Declare pointer variables with asterisk aligned to type
```c
/* OK */
char* a;
char* b;

/* WRONG */
char *a;
char * b;

```
## Structures, enumerations, typedefs

- The nave of the structure, enumeration or unions have to be:
    `ComponentName_StructureName_st`
    `ComponentName_EnumeartionName_et`
    `ComponentName_UnionName_et`
- Structure or enumeration may contain `typedef` keyword
- All enumeration members must be uppercase with termination `_E`
- Structure/enumeration must follow doxygen documentation syntax
- When structure is declared  it *must* contain `_st` suffix after its name.
```c

typedef struct
{
 uint8_t  Var1Template_u8; /* first variable used for... */
 uint16_t Var2Template_u16; /* irst variable used for... */
 uint8_t  DummyHole_u8;    /* dummy variable to fill the hole */
}ComponentName_StructureName_st;   /* _st -> means structure type */

typedef enum
{
    ELEMENT_NR0_E,
    ELEMENT_NR1_E,
    ELEMENT_NR2_E,
    ELEMENT_MAX_E  /* always declare _MAX for an enum */
}ComponentName_EnumeartionName_et; /* _et -> means enumeration type */


typedef  union
{
    uint16_t  Word_u;     /* comment to explain for what is used */
    uint8_t   ByteZero_c; /* comment to explain for what is used */
    uint8_t   ByteOne_c;  /* comment to explain for what is used */
}ComponentName_UnionName_ut; /* _ut -> means union type */

```
- When initializing structure on declaration, use `C99` initialization style
```c
/* OK */
a_t a = {  .a = 4,
           .b = 5,
           .c = 10,
        };

/* WRONG */
a_t a = {1, 2};

```
## Compound statements

- Every compound statement must include opening and closing curly bracket, even if it includes only `1` nested statement
- Every compound statement must include single indent; when nesting statements, include `1` indent size for each nest
```c
/* OK */
if (c)
{
    do_a();
}
else 
{
    do_b();
}

/* WRONG */
if (c)
    do_a();
else
    do_b();

/* WRONG */
if (c){
    do_a();}
else{
    do_b();
}

/* WRONG */
if (c) do_a();
else do_b();

```
- In case of `if` or `if-else-if` statement, `else` must be in the same line as closing bracket of first statement
```c
/* OK */
if (a)
{
/* ... */
}
else if (b)
{
/* ... */
}
else
{
/* ... */
}

/* WRONG */
if (a) {

}
else {

}

/* WRONG */
if (a) {

}
else
{

}

```
- In case of `do-while` statement, `while` part must be in the same line as closing bracket of `do` part
```c
/* OK */
do
{
    int32_t a;
    a = do_a();
    do_b(a);
} while (check());

/* WRONG */
do{
/* ... */
} while (check());

/* WRONG */
do {
/* ... */
}
while (check());

```
- Indentation is required for every opening bracket
```c

if (a)
{
    do_a();
} 
else
{
    do_b();
    if (c)
    {
        do_c();
    }
}

```
- Never do compound statement without curly bracket, even in case of single statement. Examples below show bad practices
```c
/* Never */
if (a) do_b();
else do_c();
/* Never */
if (a) do_a(); else do_b();

```
- Empty `while`, `do-while` or `for` loops must include brackets
```c
/* OK */
while (is_register_bit_set()) 
{
    /*... */
}

/* WRONG */
while (is_register_bit_set());
while (is_register_bit_set()) { }
while (is_register_bit_set()) {
}
```

- If `while` (or `for`, `do-while`, etc) is empty (it can be the case in embedded programming), use empty single-line brackets
```c
/*
 * Wait for bit to be set in embedded hardware unit
 * uint32_t* addr = HW_PERIPH_REGISTER_ADDR;
*/
while (*addr & (1 << 13))
{
/* Wait bit 13 to be ready */
} /* OK, empty loop contains comment inside */

while (*addr & (1 << 13)) { }       /* WRONG */
while (*addr & (1 << 13)) {         /* WRONG */

}
while (*addr & (1 << 13));          /* WRONG, curly brackets are missing. Can lead to compiler warnings or unintentional bugs */
```
- Always prefer using loops in this order: `for`, `do-while`, `while`
- Avoid incrementing variables inside loop block if possible, see examples
- Always declare index as `uint16` with the *name* `Idx` or `Idx1, Idx2... Idxn`
```c
/* Not recommended */
int16_t  Idx = 0;
while (Idx < 10) {
    .
    ..
    ...
    ++Idx;
}

/* Better */
for ( Idx = 0; Idx < 10; ++Idx) 
{

}

/* Better, if inc may not happen in every cycle */
for ( Idx = 0; Idx < 10; )
{
    if (...)
    {
        ++Idx;
    }
}

```
## Switch statement

- Add *single indent* for every `case` statement
- Use additional *single indent* for `break` statement in each `case` or `default`
```c
/* OK, every case has single indent */
/* OK, every break has additional indent */
switch (check())
{
    case 0:
        do_a();
        break;
    case 1:
        do_b();
        break;
    default:
        break;
}

/* WRONG, case indent missing */
switch (check()) {
case 0:
    do_a();
    break;
case 1:
    do_b();
    break;
default:
    break;
}

/* WRONG */
switch (check()) {
    case 0:
        do_a();
    break;      /* WRONG, break must have indent as it is under case */
    case 1:
    do_b();     /* WRONG, indent under case is missing */
    break;
    default:
        break;
}

```
- Always include `default` statement
```c
/* OK */
switch (var)
{
    case 0:
        do_job();
        break;
    default:
        break;
}

/* WRONG, default is missing */
switch (var) {
    case 0:
        do_job();
        break;
}

```
- If local variables are required, use curly brackets and put `break` statement inside.
- Put opening curly bracket with a line bellow as `case` statement
```c
switch (a)
{
    /* OK */
    case 0: 
    {
        int32_t a, b;
        char c;
        a = 5;
        /* ... */
        break;
    }

    /* WRONG */
    case 1:{
        int32_t a;
        break;
    }

    /* WRONG, break shall be inside */
    case 2: {
        int32_t a;
    }
    break;
}

```
## Macros and preprocessor directives

- Always use macros instead of literal constants, specially for numbers
- All macros must be fully uppercase, with optional underscore `_` character, except if they are clearly marked as function which may be in the future replaced with regular function syntax
```c
/* OK */
#define MY_MACRO(x)         ((x) * (x))

/* WRONG */
#define square(x)           ((x) * (x))

```
- Always protect input parameters with parentheses
```c
/* OK */
#define MIN(x, y)           ((x) < (y) ? (x) : (y))

/* WRONG */
#define MIN(x, y)           x < y ? x : y

```
- Always protect final macro evaluation with parenthesis
```c
/* WRONG */
#define MIN(x, y)           (x) < (y) ? (x) : (y)
#define SUM(x, y)           (x) + (y)


/* Imagine result of this equation using wrong SUM implementation */
int32_t x = 5 * SUM(3, 4);  /* Expected result is 5 * 7 = 35 */
int32_t x = 5 * (3) + (4);  /* It is evaluated to this, final result = 19 which is not what we expect */

/* Correct implementation */
#define MIN(x, y)           ((x) < (y) ? (x) : (y))
#define SUM(x, y)           ((x) + (y))

```
- When macro uses multiple statements, protect it using `do-while (0)` statement
```c
typedef struct
{
    int32_t px;
    int32_t py;
}point_t;
point_t p;                  /* Define new point */

/* WRONG implementation */

/* Define macro to set point */
#define SET_POINT(p, x, y)  (p)->px = (x); (p)->py = (y)    /* 2 statements. Last one should not implement semicolon */

SET_POINT(&p, 3, 4);        /* Set point to position 3, 4. This evaluates to... */
(&p)->px = (3); (&p)->py = (4); /* ... to this. In this example this is not a problem. */

/* Consider this ugly code, however it is valid by C standard (not recommended) */
if (a)                      /* If a is true */
    if (b)                  /* If b is true */
        SET_POINT(&p, 3, 4);/* Set point to x = 3, y = 4 */
    else
        SET_POINT(&p, 5, 6);/* Set point to x = 5, y = 6 */

/* Evaluates to code below. Do you see the problem? */
if (a)
    if (b)
        (&p)->px = (3); (&p)->py = (4);
    else
        (&p)->px = (5); (&p)->py = (6);
        
/* Or if we rewrite it a little */
if (a)
    if (b)
    {
        (&p)->px = (3); 
        (&p)->py = (4);
    }
    else
    {
        (&p)->px = (5); 
        (&p)->py = (6);
    }




/*
 * Ask yourself a question: To which `if` statement `else` keyword belongs?
 *
 * Based on first part of code, answer is straight-forward. To inner `if` statement when we check `b` condition
 * Actual answer: Compilation error as `else` belongs nowhere
 */

/* Better and correct implementation of macro */
#define SET_POINT(p, x, y)  do { (p)->px = (x); (p)->py = (y); } while (0)    /* 2 statements. No semicolon after while loop */
/* Or even better */
#define SET_POINT(p, x, y)  do {                     \   /* Backslash indicates statement continues in new line */
                                   (p)->px = (x);    \
                                   (p)->py = (y);    \
                               } while (0)  /* 2 statements. No semicolon after while loop */

/* Now original code evaluates to */
if (a)
    if (b)
        do { (&p)->px = (3); (&p)->py = (4); } while (0);
    else
        do { (&p)->px = (5); (&p)->py = (6); } while (0);

/* Every part of `if` or `else` contains only `1` inner statement (do-while), hence this is valid evaluation */

/* To make code perfect, use brackets for every if-ifelse-else statements */
if (a)                       /* If a is true */
{
    if (b)                   /* If b is true */
    {
        SET_POINT(&p, 3, 4); /* Set point to x = 3, y = 4 */
    } else
    {
        SET_POINT(&p, 5, 6); /* Set point to x = 5, y = 6 */
    }
}

```
- Avoid using `#ifdef` or `#ifndef`. Use `defined()` or `!defined()` instead
```c
#ifdef XYZ
/* do something */
#endif /* XYZ */
```

- Always document `if/elif/else/endif` statements
```c
/* OK */
#if defined(XYZ)
/* Do if XYZ defined */
#else /* defined(XYZ) */
/* Do if XYZ not defined */
#endif /* !defined(XYZ) */

/* WRONG */
#if defined(XYZ)
/* Do if XYZ defined */
#else
/* Do if XYZ not defined */
#endif
```

- Do not indent sub statements inside `#if` statement
```c
/* OK */
#if defined(XYZ)
#if defined(ABC)
/* do when ABC defined */
#endif /* defined(ABC) */
#else /* defined(XYZ) */
/* Do when XYZ not defined */
#endif /* !defined(XYZ) */

/* WRONG */
#if defined(XYZ)
    #if defined(ABC)
        /* do when ABC defined */
    #endif /* defined(ABC) */
#else /* defined(XYZ) */
    /* Do when XYZ not defined */
#endif /* !defined(XYZ) */