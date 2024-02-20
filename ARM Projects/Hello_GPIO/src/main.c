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
#include "Timer2_interface.h"
//#include "SYSTICK_interface.h"

#define  PORTA_CRL	*((u32*)0x40010800)
#define  PORTA_ODR	*((u32*)0x4001080C)

void main(void)
{

/* Initialize clock system					*/
	RCC_voidInitSystemClock();
/* Enable Peripheral 2 on APB2 bus (GPIOA)	*/
	RCC_voidEnableClock(RCC_APB2, 2);
/* Enable Peripheral 0 on APB1 bus (TIM2)	*/
	RCC_voidEnableClock(RCC_APB1, 0);
/* A0 is output push pull					*/
	PORTA_CRL=0x00000002;

	TIMER2_voidInit();
	while(1)
	{
		/* Set A0 output high						*/
		PORTA_ODR=0x00000001;
		TIMER2_voidSetBusyWait(50000);
		PORTA_ODR=0x00000000;
		TIMER2_voidSetBusyWait(50000);
	}




}

