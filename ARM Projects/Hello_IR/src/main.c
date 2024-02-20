/*
 * main.c
 *
 *  Created on: Jul 20, 2022
 *      Author: moust
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "SYSTICK_interface.h"
#include "LEDMTRX_interface.h"
#include "IR_interface.h"

extern u32 Data;
u8 Local_u8Ball1[8] = {144, 74, 125, 74, 144, 64, 160, 64};
u8 Local_u8Ball2[8] = {144, 74, 125, 74, 144, 16, 40, 16};
u8 Local_u8Ball3[8] = {144, 74, 125, 74, 144, 4, 10, 4};
u8 Local_u8Name[34]  = {0, 126, 4, 8, 4, 126, 0, 124, 18, 18, 124, 0, 124, 18, 42, 68, 0, 2, 4, 120, 4, 2, 0, 124, 18, 18, 124, 0, 126, 4, 8, 4, 126, 0};

void voidPlay(void)
{
	switch(Data)
	{
	case 69 : LEDMTRX_voidDisplayString(Local_u8Ball1, 8);
			  LEDMTRX_voidDisplayString(Local_u8Ball2, 8);
			  LEDMTRX_voidDisplayString(Local_u8Ball3, 8);
			  break;
	case 70 : LEDMTRX_voidDisplayString(Local_u8Name, 34);
			  break;
	}

}

void EXTI0_Function(void)
{

	IR_voidGetDataFrame( voidPlay );
}

void main(void)
{
/*			RCC initialization				*/
	RCC_voidInitSystemClock();
	RCC_voidEnableClock(RCC_APB2, 2);		//Enable RCC on PORTA
	RCC_voidEnableClock(RCC_APB2, 3); 		//Enable RCC on PORTB

/*			GPIO initialization				*/
	//GPIO_voidSetPinDirection(PORTA, PIN13, OUTPUT_2MHZ_PP);
	//GPIO_voidSetPinDirection(PORTA, PIN14, OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(PORTA, PIN4, OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(PORTA, PIN0,  INPUT_FLOATING);

/*			NVIC Enable						*/
	NVIC_voidSetPriority(6, 0, 0, NVIC_2BitGroup_2BitSub);

	NVIC_voidEnableInterrupt(6);

/*			EXTI Enable 					*/
	EXTI_voidSetCallBack(EXTI0_Function);
	EXTI_voidInit(LINE0, ON_CHANGE);
/*			Systick timer initialization	*/
	STK_voidInit();


	while(1)
	{

	}
}

