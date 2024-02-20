/*
 * main.c
 *
 *  Created on: Jul 19, 2022
 *      Author: moust
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "LEDMTRX_interface.h"

u8 Local_u8Array[30] = {0, 0, 96, 130, 130, 126, 2, 2, 0, 252, 34, 34, 34, 252, 0, 254, 6, 8, 16, 32, 192, 254, 0, 252, 34, 34, 34, 252, 0, 0};

void main(void)
{
	RCC_voidInitSystemClock();
	RCC_voidEnableClock(RCC_APB2, 2); //Enable RCC on PORTA
	RCC_voidEnableClock(RCC_APB2, 3); //Enable RCC on PORTB

	STK_voidInit();

	LEDMTRX_voidInit();
	while (1)
	{
		LEDMTRX_voidDisplayString(Local_u8Array, 30);
	}
}
