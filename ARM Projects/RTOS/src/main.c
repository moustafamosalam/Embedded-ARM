/*
 * main.c
 *
 *  Created on: Jul 21, 2022
 *      Author: moust
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "Segment_interface.h"
#include "SYSTICK_interface.h"
#include "RTOS_interface.h"

volatile u8 num = 0;

void TASK2(void)
{
	GPIO_voidSetPinValue(PORTA, PIN7, HIGH);
	RTOS_voidSuspendTask(1);
	num=0;
	RTOS_voidResumeTask(0);
}

void TASK1(void)
{
	GPIO_voidSetPinValue(PORTA, PIN7, LOW);
	Segment_voidDisplayNumber(num);
	num++;
	if(num == 10)
	{
		RTOS_voidSuspendTask(0);
		RTOS_voidResumeTask(1);
	}
}

void LED1(void)
{
	static u8 Local_u8Toggle = 0;
	TOG_BIT(Local_u8Toggle,0);
	GPIO_voidSetPinValue(PORTA, PIN0, Local_u8Toggle);
}

void LED2(void)
{
	static u8 Local_u8Toggle = 0;
	TOG_BIT(Local_u8Toggle,0);
	GPIO_voidSetPinValue(PORTA, PIN1, Local_u8Toggle);
}

void LED3(void)
{
	static u8 Local_u8Toggle = 0;
	TOG_BIT(Local_u8Toggle,0);
	GPIO_voidSetPinValue(PORTA, PIN2, Local_u8Toggle);
}

void main(void)
{
	RCC_voidInitSystemClock(); 				//Initalization
	RCC_voidEnableClock(RCC_APB2, 2); 		//Enable RCC on PORTA

/*			Initizalizing Pins for LED								*/
	GPIO_voidSetPortDirection(PORTA, LOW, OUTPUT_2MHZ_PP);

	RTOS_voidCreateTask(0, 1000,  0, TASK1);
	RTOS_voidCreateTask(1, 1000,  0, TASK2);
	RTOS_voidSuspendTask(1);
	//RTOS_voidCreateTask(2, 3000, 2, LED3);

	RTOS_voidStart();

	while(1)
	{

	}
}

