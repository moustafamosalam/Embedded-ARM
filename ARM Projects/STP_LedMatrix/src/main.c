/*
 * main.c
 *
 *  Created on: Jul 27, 2022
 *      Author: moust
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

#include "STP_interface.h"
#include "LEDMTRX_interface.h"

u8 Array[24] = {0, 0, 126, 4, 8, 4, 126, 0, 62, 64, 64, 62, 0, 68, 74, 82, 34, 0, 124, 18, 18, 124, 0, 0};

void main(void)
{
	RCC_voidInitSystemClock();
	RCC_voidEnableClock(RCC_APB2, 2);

	STK_voidInit();

	STP_voidInit();

	while(1)
	{
		LEDMTRX_voidSerialDisplay(Array, 24);
	}
}

