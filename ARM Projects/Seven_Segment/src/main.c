/*
 * main.c
 *
 *  Created on: Jul 8, 2022
 *      Author: moust
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "Segment_interface.h"


void main (void)
{
	RCC_voidInitSystemClock();
	RCC_voidEnableClock(RCC_APB2, 2);

	GPIO_voidSetPortDirection(PORTA, LOW, OUTPUT_2MHZ_PP);

	Segment_voidDisplayNumber(2);

	while(1)
	{

	}

}

