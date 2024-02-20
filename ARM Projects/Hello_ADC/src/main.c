/*
 * main.c
 *
 *  Created on: Sep 12, 2022
 *      Author: moust
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "ADC_interface.h"

void main(void)
{
	RCC_voidInitSystemClock();
	RCC_voidEnableClock(RCC_APB2, 2);
	RCC_voidEnableClock(RCC_APB2, 9);

	GPIO_voidSetPinDirection(PORTA, PIN5, INPUT_ANALOG);

	ADC_voidInit();

	ADC_voidStartConversion(5);

	volatile u32 AnalogData = 0;

	while(1)
	{
		AnalogData = ADC_voidReadContinuous();
	}
}

