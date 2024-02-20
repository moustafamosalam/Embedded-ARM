/*
 * main.c
 *
 *  Created on: Sep 28, 2022
 *      Author: moust
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "SYSTICK_interface.h"


u8 Delay =	41;


void main(void)
	{
	RCC_voidInitSystemClock();
	RCC_voidEnableClock(RCC_APB2, 2);

	GPIO_voidSetPinDirection(PORTA, PIN1, OUTPUT_2MHZ_PP);

/*			NVIC Enable						*/
	//NVIC_voidSetPriority(6, 0, 0, NVIC_2BitGroup_2BitSub);

	//NVIC_voidEnableInterrupt(6);

/*			EXTI Enable 					*/
	//EXTI_voidSetCallBack(EXTI0_Function);
	//EXTI_voidInit(LINE0, FALLING_EDGE);


	STK_voidInit();

	u8 u8Temp = 0;
	u16 x = 0;
	u16 Array[212] = {3800, 1800, 560, 380, 560, 1300, 560, 380, 560, 1300, 560, 360, 560, 1300, 560, 380, 560, 1300, 560, 380, 560, 1300, 560, 380,
					 560, 1300, 560, 1300, 560, 380, 560, 1300, 560, 380, 560, 1300, 560, 1300, 560, 1300, 560, 1300, 560, 380, 560, 380, 560, 1300,
					 560, 1300, 560, 380, 560, 380, 560, 380, 560, 380, 560, 1300, 560, 380, 560, 380, 560, 380, 560, 1300, 560, 380, 560, 380, 560,
					 1300, 560, 380, 560, 380, 560, 380, 560, 380, 560, 1300, 560, 380, 560, 380, 560, 380, 560, 380, 560, 380, 560, 380, 560, 1300,
					 560, 380, 560, 1300, 560, 380, 560, 380, 560, 1300, 560, 380, 560, 1300, 560, 380, 560, 380, 560, 380, 560, 380, 560, 380, 560,
					 380, 560, 380, 560, 380, 560, 380, 560, 380, 560, 380, 560, 380, 560, 1300, 560, 380, 560, 380, 560, 380, 560, 380, 560, 380,
					 560, 380, 560, 380, 560, 380, 560, 380, 560, 380, 560, 380, 560, 1300, 560, 380, 560, 380, 560, 380, 560, 380, 560, 380, 560,
					 380, 560, 380, 560, 380, 560, 380, 560, 380, 560, 380, 560, 380, 560, 1300, 560, 1300, 560, 1300, 560, 1300, 560, 1300, 560, 380,
					 560, 380, 560, 380, 560, 380, 560, 380, 560, 1300, 560, 380, 380};

	/*				START BIT										*/



	while(1)
	{
		for(u8 i=0; i<211; i++)
			{
				if(u8Temp == 0)
				{

					x = 0;

					while(u8Temp == 0)
					{
						GPIO_voidSetPinValue(PORTA, PIN1, HIGH);
						STK_voidSetBusyWait(Delay);
						GPIO_voidSetPinValue(PORTA, PIN1, LOW);
						STK_voidSetBusyWait(Delay);

						x = (x + (2*Delay));
						if(x > Array[i])
							{
								u8Temp = 1;
							}
					}
				}
				else
				{
					u8Temp = 0;
					STK_voidSetBusyWait(Array[i]);
				}
			}
		STK_voidSetBusyWait(1000000);
		//Delay++;

	}
}

