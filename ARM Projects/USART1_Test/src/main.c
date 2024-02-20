/*
 * main.c
 *
 *  Created on: Aug 23, 2022
 *      Author: moust
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

#include "USART1_interface.h"


void main(void)
{
	RCC_voidInitSystemClock();
	RCC_voidEnableClock(RCC_APB2, 2);
	RCC_voidEnableClock(RCC_APB2, 14);

	GPIO_voidSetPinDirection(PORTA, PIN9, OUTPUT_50MHZ_AFPP);
	GPIO_voidSetPinDirection(PORTA, PIN10, INPUT_FLOATING);
	GPIO_voidSetPinDirection(PORTA, PIN0, OUTPUT_2MHZ_PP);

	STK_voidInit();
	USART1_voidInit();

	u8 x = 0;

	while(1)
	{
		USART1_voidSendChar('7');
		STK_voidSetBusyWait(100000);
		x = USART1_voidRcvChar();
		if(x == '5')
		{
			GPIO_voidSetPinValue(PORTA, PIN0, HIGH);
		}
		else if(x == '6')
		{
			GPIO_voidSetPinValue(PORTA, PIN0, LOW);
		}
		USART1_voidSendChar(x);

	}
}
