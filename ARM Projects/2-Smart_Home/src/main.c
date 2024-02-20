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
#include "Timer2_interface.h"

#include "SYSTICK_interface.h"

u8 Delay =102;

void main(void)
{
	RCC_voidInitSystemClock();
	RCC_voidEnableClock(RCC_APB2, 2);
/* Enable Peripheral 0 on APB1 bus (TIM2)	*/
	RCC_voidEnableClock(RCC_APB1, 0);

	GPIO_voidSetPinDirection(PORTA, PIN1, OUTPUT_2MHZ_AFPP);

	STK_voidInit();
	TIMER2_voidInit();

	u8 Array[33] = {0,0,1,0,0,0,0,0,1,1,0,1,1,1,1,1,0,1,0,0,0,0,0,0,1,0,1,1,1,1,1,1};

	/*				START BIT										*/

//		for(u8 j=0; j<2; j++)
//		{
//
//		}

	while(1)
	{
		TIMER2_voidPWM(Delay*2, 0, CHANNEL2);
			TIMER2_voidPWMCounterEnable();
		TIMER2_voidSetCCRVal(Delay,CHANNEL2);
					//IR_voidGetDataFrame( voidPlay );
					STK_voidSetBusyWait(9000);
					TIMER2_voidSetCCRVal(0,CHANNEL2);
					STK_voidSetBusyWait(4500);

					for(u8 i=0; i<32; i++)
					{
						if(Array[i] == 0)
						{
							//IR_voidGetDataFrame( voidPlay );
							TIMER2_voidSetCCRVal(Delay, CHANNEL2);
							STK_voidSetBusyWait(562);
							TIMER2_voidSetCCRVal(0, CHANNEL2);
							STK_voidSetBusyWait(562);
						}
						else
						{
							//IR_voidGetDataFrame( voidPlay );
							TIMER2_voidSetCCRVal(Delay, CHANNEL2);
							STK_voidSetBusyWait(562);
							TIMER2_voidSetCCRVal(0, CHANNEL2);
							STK_voidSetBusyWait(1687);
						}
					}

					//IR_voidGetDataFrame( voidPlay );
					TIMER2_voidSetCCRVal(Delay, CHANNEL2);
					STK_voidSetBusyWait(610);
					TIMER2_voidSetCCRVal(0, CHANNEL2);
					STK_voidSetBusyWait(1000000);
					//Delay++;
	}
}
