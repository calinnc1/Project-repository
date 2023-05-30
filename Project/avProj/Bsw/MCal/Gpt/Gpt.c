/*
 * Gpt.c
 *
 *  Created on: Oct 12, 2022
 *      Author: cosmin.marcu
 */

#include "Gpt.h"

static boolean g_Gpt_InitDone_b = FALSE;

void Gpt_Init(void)
{
	g_Gpt_InitDone_b = TRUE;
}
/* END OF FILE */
