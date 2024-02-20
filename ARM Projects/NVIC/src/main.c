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

void EXTI0_IRQHandler(void){

	GPIO_voidSetPinValue( PORTA , PIN1 , HIGH );

}

void EXTI1_IRQHandler(void){

	GPIO_voidSetPinValue( PORTA , PIN1 , LOW );

}


void main(void)
{
	RCC_voidInitSystemClock();
	RCC_voidEnableClock(RCC_APB2, 2);

	GPIO_voidSetPinDirection(PORTA, PIN1, OUTPUT_10MHZ_PP);

	NVIC_voidSetPriority(6, 1, 0, NVIC_4BitGroup_0BitSub);
	NVIC_voidSetPriority(7, 2, 0, NVIC_4BitGroup_0BitSub);

	NVIC_voidEnableInterrupt(6);
	NVIC_voidEnableInterrupt(7);
	u16 w=1000;
	while(1)
	{
		NVIC_voidSetPendingFlag(6);
		for(u16 i=0;i<w;i++)
				{
					for(u16 j=0;j<w;j++)
					{
						asm("NOP");
					}
				}
		NVIC_voidSetPendingFlag(7);
		for(u16 i=0;i<w;i++)
						{
							for(u16 j=0;j<w;j++)
							{
								asm("NOP");
							}
						}

	}
}
