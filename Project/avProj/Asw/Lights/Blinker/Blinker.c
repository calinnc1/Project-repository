/**
  * @file	Blinker.c
  * @author	cosmin.marcu
  * @date	Nov 15, 2022
  * @brief
  */

/* INCLUDES: */
#include "Blinker.h"
#include "Rte_Blinker.h"

/* DEFINES: */

/* TYPES: */

/* VARIABLES: */
static boolean g_Blinker_InitDone_b = FALSE;							///< Module initialization flag
static boolean g_Bliker_Autobrakes_Status = FALSE;                      ///< Blinker State
static boolean g_Bliker_Autobrakes_Previous_Status = FALSE;             ///< Blinker Previous State

static uint16 g_Blinker_Counter_u16 = 0;                                ///< Counter for Blinkers
static boolean g_Left_Blinker_Status_b = FALSE;                         ///< Left Blinker Status
static boolean g_Right_Blinker_Status_b = FALSE;                        ///< Right Blinker Status

/* CONSTANTS: */

/* FUNCTIONS PROTOTYPES: */

/* STATIC FUNCTIONS: */

/* PUBLIC FUNCTIONS: */
/**
  * @brief	Blinker module initialization function
  * @return	None
  */
void Blinker_Init(void)
{
	g_Left_Blinker_Status_b = FALSE;
	g_Right_Blinker_Status_b = FALSE;
	Rte_Write_Left_Blinker_Autobrakes_Status(g_Left_Blinker_Status_b);
	Rte_Write_Right_Blinker_Autobrakes_Status(g_Right_Blinker_Status_b);
	/* Set initialization flag to done */
	g_Blinker_InitDone_b = TRUE;
}

/**
  * @brief	Blinker module main function (runs in task)
  * @return	None
  */
void Blinker_MainFunction(void)
{

	/* Check if initialization is done */
	if(TRUE == g_Blinker_InitDone_b)
	{
		Rte_Read_Blinker_Autobrakes_Status(&g_Bliker_Autobrakes_Status);

		if(TRUE == g_Bliker_Autobrakes_Status && FALSE == g_Bliker_Autobrakes_Previous_Status)
		{
			g_Left_Blinker_Status_b = TRUE;
			g_Right_Blinker_Status_b = TRUE;
			g_Bliker_Autobrakes_Previous_Status = TRUE;
		}
		else if(TRUE == g_Bliker_Autobrakes_Status && TRUE == g_Bliker_Autobrakes_Previous_Status)
		{
			if(g_Blinker_Counter_u16 < 45)
			{
				g_Blinker_Counter_u16++;
				if(0 == g_Blinker_Counter_u16 % 5)
				{
					g_Left_Blinker_Status_b = !g_Left_Blinker_Status_b;
					g_Right_Blinker_Status_b = !g_Right_Blinker_Status_b;
				}

			}
			else
			{
				g_Left_Blinker_Status_b = FALSE;
				g_Right_Blinker_Status_b = FALSE;
			}
		}
		else
		{
			g_Bliker_Autobrakes_Previous_Status = FALSE;
			g_Blinker_Counter_u16 = 0;
			g_Left_Blinker_Status_b = FALSE;
			g_Right_Blinker_Status_b = FALSE;
		}

		Rte_Write_Left_Blinker_Autobrakes_Status(g_Left_Blinker_Status_b);
		Rte_Write_Right_Blinker_Autobrakes_Status(g_Right_Blinker_Status_b);
	}
}
/* END OF FILE */
