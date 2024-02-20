/*
 * main.c
 *
 *  Created on: Jun 27, 2022
 *      Author: moust
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "GPIO_interface.h"
#include "Timer2_interface.h"
#include "Timer2_private.h"
#include "SYSTICK_interface.h"


void main(void)
{

/* Initialize clock system					*/
	RCC_voidInitSystemClock();
/* Enable Peripheral 2 on APB2 bus (GPIOA)	*/
	RCC_voidEnableClock(RCC_APB2, 2);
/* Enable Peripheral 0 on APB1 bus (TIM2)	*/
	RCC_voidEnableClock(RCC_APB1, 0);
/* A0 & A1 are output AFPP						*/
	GPIO_voidSetPinDirection(PORTA, PIN0, OUTPUT_2MHZ_AFPP);
	GPIO_voidSetPinDirection(PORTA, PIN1, OUTPUT_2MHZ_AFPP);
/* A2 is output PP						*/
	GPIO_voidSetPinDirection(PORTA, PIN2, OUTPUT_2MHZ_PP);


	STK_voidInit();

	TIMER2_voidInit();
	TIMER2_voidSetBusyWait(9000);
	TIMER2_voidPWM(1000, 1, CHANNEL1);
	TIMER2_voidPWM(1000, 1, CHANNEL2);
	TIMER2_voidPWMCounterEnable();

u16 i=0;
	while(1)
	{

		for( i=0; i<1000; i++)
		{
			TIMER2_voidSetCCRVal(i,CHANNEL1);
			TIMER2_voidSetCCRVal(i,CHANNEL2);
			STK_voidSetBusyWait(10000);
		}

		GPIO_voidSetPinValue(PORTA, PIN2, HIGH);

		for( i=999; i>0; i--)
		{
			TIMER2_voidSetCCRVal(i,CHANNEL1);
			TIMER2_voidSetCCRVal(i,CHANNEL2);
			STK_voidSetBusyWait(10000);
		}

		GPIO_voidSetPinValue(PORTA, PIN2, LOW);
	}




}


