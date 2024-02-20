/*
 * main.c
 *
 *  Created on: Jul 22, 2022
 *      Author: moust
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "file.h"

#include "GPIO_private.h"

volatile u16 i=0;

void SetDac(void)
{
	GPIO_voidSetPortValue(PORTA, LOW, habayb_raw[i]);
	i++;
	if(i==35016)
	{
		i=0;
	}

}

void main(void)
{
	RCC_voidInitSystemClock();
	RCC_voidEnableClock(RCC_APB2, 2);

	GPIO_voidSetPortDirection(PORTA, LOW, OUTPUT_2MHZ_PP);

	STK_voidInit();
	STK_voidSetInterval(125, SetDac, PERIODIC_INTERVAL);

	while(1)
	{


	}
}
