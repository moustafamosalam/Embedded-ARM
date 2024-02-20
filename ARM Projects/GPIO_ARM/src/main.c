/*
 * main.c
 *
 *  Created on: Jun 28, 2022
 *      Author: moust
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"



void main (void)
{
/* Initialize clock system					*/
	RCC_voidInitSystemClock();
/* Enable Peripheral 2 on APB2 bus (GPIOA)	*/
	RCC_voidEnableClock(RCC_APB2, 2);
/* Enable Peripheral 3 on APB2 bus (GPIOB)	*/
	RCC_voidEnableClock(RCC_APB2, 3);
/* Enable Peripheral 4 on APB2 bus (GPIOC)	*/
	RCC_voidEnableClock(RCC_APB2, 4);
/* PINA0 output push pull 10MHZ				*/
	GPIO_voidSetPinDirection(PORTA, PIN0, OUTPUT_10MHZ_PP);
	GPIO_voidSetPinDirection(PORTA, PIN1, OUTPUT_10MHZ_PP);
u16 w=500;
	while(1)
	{
		GPIO_voidSetPinValue(PORTA, PIN0, HIGH);
		for(u16 i=0;i<w;i++)
		{
			for(u16 j=0;j<w;j++)
			{
				asm("NOP");
			}
		}
		GPIO_voidSetPinValue(PORTA, PIN0, LOW);
		for(u16 i=0;i<w;i++)
				{
					for(u16 j=0;j<w;j++)
					{
						asm("NOP");
					}
				}
	}

}

