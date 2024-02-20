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

void main(void)
{
	RCC_voidInitSystemClock();
	RCC_voidEnableClock(RCC_APB2, 2);

	GPIO_voidSetPinDirection(PORTA, PIN0, OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(PORTA, PIN1, OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(PORTA, PIN2, OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(PORTA, PIN3, OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(PORTA, PIN4, OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(PORTA, PIN5, OUTPUT_2MHZ_PP);


	while(1)
	{
		GPIO_voidSetPinValue(PORTA, PIN0, HIGH);
		GPIO_voidSetPinValue(PORTA, PIN1, HIGH);
		GPIO_voidSetPinValue(PORTA, PIN2, HIGH);
		GPIO_voidSetPinValue(PORTA, PIN3, HIGH);
		GPIO_voidSetPinValue(PORTA, PIN4, HIGH);
		GPIO_voidSetPinValue(PORTA, PIN5, HIGH);

	}

}
