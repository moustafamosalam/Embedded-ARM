/*
 * main.c
 *
 *  Created on: Sep 13, 2022
 *      Author: moust
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

#define TRIG_PORT	PORTA
#define TRIG_PIN	PIN11
#define ECHO_PORT	PORTA
#define ECHO_PIN	PIN12

u32 TimeElapsed_1 = 0;
u32 TimeElapsed_2 = 0;
u32 Duration = 0;
volatile f32 Distance = 0;
u8 Local_u8Temp;

void func (void)
{
	Distance = 200;
	GPIO_voidSetPinValue(TRIG_PORT, ECHO_PIN, LOW);
	Local_u8Temp = 1;
}

void main(void)
{
	RCC_voidInitSystemClock();
	RCC_voidEnableClock(RCC_APB2, 2);
	//RCC_voidEnableClock(RCC_APB1, 0);

	GPIO_voidSetPinDirection(TRIG_PORT, TRIG_PIN, OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(ECHO_PORT, ECHO_PIN, INPUT_FLOATING);

	STK_voidInit();

	while(1)
	{
		Local_u8Temp =0;
		GPIO_voidSetPinValue(TRIG_PORT, TRIG_PIN, HIGH);
		STK_voidSetBusyWait(10);
		GPIO_voidSetPinValue(TRIG_PORT, TRIG_PIN, LOW);

		STK_voidSetInterval(20000, func, SINGLE_INTERVAL);
		while( GPIO_u8GetPinValue(ECHO_PORT, ECHO_PIN) == 0  );
		TimeElapsed_1 = STK_voidGetElapsedTime();

		while( GPIO_u8GetPinValue(ECHO_PORT, ECHO_PIN) == 1  );
		TimeElapsed_2 = STK_voidGetElapsedTime();

		if(Local_u8Temp == 0)
		{
			STK_voidStopCounts();
			Duration = TimeElapsed_2 - TimeElapsed_1;
			Distance = ( (Duration/2)*(0.034) );

		}
		STK_voidSetBusyWait(50);

	}

}

