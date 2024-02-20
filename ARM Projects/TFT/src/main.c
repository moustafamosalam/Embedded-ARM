/*
 * main.c
 *
 *  Created on: Aug 1, 2022
 *      Author: moust
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "SPI_interace.h"
#include "TFT_interface.h"


#include "Image.h"

void main(void)
{
	RCC_voidInitSystemClock();
	RCC_voidEnableClock(RCC_APB2, 2);		//GPIO RCC Enable
	RCC_voidEnableClock(RCC_APB2, 12);		//SPI RCC Enable

	GPIO_voidSetPinDirection(PORTA, PIN1, OUTPUT_10MHZ_PP);
	GPIO_voidSetPinDirection(PORTA, PIN2, OUTPUT_10MHZ_PP);
	GPIO_voidSetPinDirection(PORTA, PIN5, OUTPUT_10MHZ_AFPP);
	GPIO_voidSetPinDirection(PORTA, PIN7, OUTPUT_10MHZ_AFPP);

	STK_voidInit();

	SPI_voidInit();

	TFT_voidInit();

	TFT_voidDisplayImage(image);

	while(1)
	{

	}
}
