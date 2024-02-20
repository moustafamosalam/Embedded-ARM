/*
 * main.c
 *
 *  Created on: Aug 24, 2022
 *      Author: moust
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "SYSTICK_interface.h"

#include "ESP_interface.h"
#include "USART1_interface.h"


void main(void)
{
	s8 RcvData[2] = {0};
	RCC_voidInitSystemClock();
	RCC_voidEnableClock(RCC_APB2, 2);
	RCC_voidEnableClock(RCC_APB2, 14);

	GPIO_voidSetPinDirection(PORTA, PIN9, OUTPUT_50MHZ_AFPP);
	GPIO_voidSetPinDirection(PORTA, PIN10, INPUT_FLOATING);
	GPIO_voidSetPinDirection(PORTA, PIN0, OUTPUT_2MHZ_PP);
	NVIC_voidSetPriority(37, 1, 0, NVIC_4BitGroup_0BitSub);
	NVIC_voidEnableInterrupt(37);

	//STK_voidInit();
	USART1_voidInit();
	ESP_voidInit();
	ESP_voidWifiConnect((u8*)"Hello", (u8*)"qzwxecrvtbynum");


	while(1)
	{
		ESP_voidServerConnect((u8*)"162.253.155.226");
		ESP_voidReceiveData((u8*)"mosalam.freevar.com", 43, RcvData);
		if(RcvData[0] == 48)
		{
			GPIO_voidSetPinValue(PORTA, PIN0, LOW);
		}
		else if(RcvData[1] == 49)
		{
			GPIO_voidSetPinValue(PORTA, PIN0, HIGH);
		}

	}
}
