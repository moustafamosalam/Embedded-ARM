/*
 * main.c
 *
 *  Created on: Jul 22, 2022
 *      Author: moust
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"
#include "SYSTICK_interface.h"
#include "DAC_interface.h"
#include "IR_interface.h"

#include "hello.h"
#include "water.h"
#include "help.h"
#include "hungry.h"

extern u8 Data;
//extern Data;


void TakeAction(void)
{
	switch(Data)
	{
		case(12):
				DAC_voidPlayVoice(helol_raw, 4875);
				break;
		case(24):
				DAC_voidPlayVoice(help_raw, 4060);
				break;
		case(94):
				DAC_voidPlayVoice(hungry_raw, 6275);
				break;
		case(8):
				DAC_voidPlayVoice(water_raw, 4985);
				break;
	}
}
void Play(void)
{
	DAC_voidStart(TakeAction);
}

void EXTI0_CallBackFunc(void)
{
	IR_voidGetDataFrame(Play);
}

void main(void)
{
	RCC_voidInitSystemClock();
	RCC_voidEnableClock(RCC_APB2, 2);

	GPIO_voidSetPortDirection(PORTA, LOW, OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(PORTA, PIN8, INPUT_FLOATING);

	AFIO_voidSetEXTIConfiguration(LINE8, AFIO_PORTA);
	NVIC_voidEnableInterrupt(23);

	EXTI0_voidSetCallBack(EXTI0_CallBackFunc);
	EXTI_voidInit(LINE8, FALLING_EDGE);

	STK_voidInit();

	while(1)
	{

	}
}

