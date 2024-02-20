/*
 * main.c
 *
 *  Created on: Jul 7, 2022
 *      Author: moust
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"

u8 volatile Flag = 0;

void EXT0_CALLBACK(){

	if( Flag == 0 ){

		GPIO_voidSetPinValue( PORTB , PIN0 , HIGH );
		Flag = 1 ;

	}

}

void EXT1_CALLBACK(){

	if( Flag == 1 ){

		GPIO_voidSetPinValue( PORTB , PIN1 , HIGH );
		Flag = 0 ;

	}

}

void EXT2_CALLBACK(){

	if( Flag == 0 ){

		GPIO_voidSetPinValue( PORTA , PIN4 , HIGH );
		Flag = 1 ;

	}

}

void main(void)
{
	RCC_voidInitSystemClock();
	RCC_voidEnableClock(RCC_APB2, 2);	//Enable RCC on PORTA
	RCC_voidEnableClock(RCC_APB2, 3);	//Enable RCC on PORTB
	RCC_voidEnableClock(RCC_APB2, 0);	//Enable RCC on AFIO

	GPIO_voidSetPinDirection(PORTB, PIN0, OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(PORTB, PIN1, OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(PORTA, PIN4, OUTPUT_2MHZ_PP);

	GPIO_voidSetPinDirection(PORTA, PIN0, INPUT_PULLUP_DOWN);
	GPIO_voidSetPinDirection(PORTA, PIN1, INPUT_PULLUP_DOWN);
	GPIO_voidSetPinDirection(PORTA, PIN2, INPUT_PULLUP_DOWN);
	GPIO_voidSetPinValue(PORTA, PIN0, HIGH);
	GPIO_voidSetPinValue(PORTA, PIN1, HIGH);
	GPIO_voidSetPinValue(PORTA, PIN2, HIGH);

	NVIC_voidSetPriority(6, 1, 0, NVIC_4BitGroup_0BitSub);
	NVIC_voidSetPriority(7, 2, 0, NVIC_4BitGroup_0BitSub);
	NVIC_voidSetPriority(8, 3, 0, NVIC_4BitGroup_0BitSub);
	NVIC_voidEnableInterrupt(6);
	NVIC_voidEnableInterrupt(7);
	NVIC_voidEnableInterrupt(8);

	AFIO_voidSetEXTIConfiguration(LINE0, AFIO_PORTA);
	AFIO_voidSetEXTIConfiguration(LINE1, AFIO_PORTA);
	AFIO_voidSetEXTIConfiguration(LINE2, AFIO_PORTA);

	EXTI0_voidSetCallBack( EXT0_CALLBACK );
	EXTI1_voidSetCallBack( EXT1_CALLBACK );
	EXTI2_voidSetCallBack( EXT2_CALLBACK );

	EXTI_voidInit(LINE0, FALLING_EDGE);
	EXTI_voidInit(LINE1, FALLING_EDGE);
	EXTI_voidInit(LINE2, FALLING_EDGE);

	while(1)
	{


	}

}
