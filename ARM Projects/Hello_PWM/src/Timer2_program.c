#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Timer2_interface.h"
#include "Timer2_private.h"
#include "Timer2_config.h"

void TIMER2_voidInit(void)
{
	//Auto Reload preload enable
	SET_BIT(TIMER2->CR1,7);
	//Counts Up or Down
	CLR_BIT(TIMER2->CR1,6);
	CLR_BIT(TIMER2->CR1,5);
	//Countes Up
	CLR_BIT(TIMER2->CR1,4);
	//Prescaler
	TIMER2->PSC = PRESCALER;
	
	//SET_BIT(TIMER2->SR,1);
}

void TIMER2_voidSetBusyWait(u16 Copy_u16Time)
{
	//Every Counter = 100 MicroSeconds
	TIMER2->ARR = Copy_u16Time;
	
	//Counter Enable
    SET_BIT(TIMER2->CR1,0);
	
	//Polliing till Counter Finishe
	while( (GET_BIT(TIMER2->SR, 0) ) == 0 );

	//Disable Counter & Clears Auto reload register 
	CLR_BIT(TIMER2->CR1,0);
	TIMER2->ARR = 0;

}	

void TIMER2_voidPWM(u16 Copy_u16ARRValue, u16 Copy_u16CCR1Value, u8 Copy_u8Channel)
{
	switch(Copy_u8Channel)
	{
		case CHANNEL1 :
							//Output Compare 1 preload enable
							SET_BIT(TIMER2->CCMR1, 3);

							//Channel 1 output
							CLR_BIT(TIMER2->CCMR1, 1);
							CLR_BIT(TIMER2->CCMR1, 0);

							//Output Compare mode PWM mode 1
							SET_BIT(TIMER2->CCMR1, 6);
							SET_BIT(TIMER2->CCMR1, 5);
							CLR_BIT(TIMER2->CCMR1, 4);

							//Signal on corresponding pin
							SET_BIT(TIMER2->CCER, 0);

							//Active High
							CLR_BIT(TIMER2->CCER, 1);

							//ARR Value = 1000
							TIMER2->ARR = Copy_u16ARRValue;

							//CCR1 Value = 500
							TIMER2->CCR1 = Copy_u16CCR1Value;

							//Counter enable
							SET_BIT(TIMER2->CR1, 0);
							break;

		case CHANNEL2 :
							//Output Compare 2 preload enable
							SET_BIT(TIMER2->CCMR1, 11);

							//Channel 2 output
							CLR_BIT(TIMER2->CCMR1, 9);
							CLR_BIT(TIMER2->CCMR1, 8);

							//Output Compare mode PWM mode 1
							SET_BIT(TIMER2->CCMR1, 14);
							SET_BIT(TIMER2->CCMR1, 13);
							CLR_BIT(TIMER2->CCMR1, 12);

							//Signal on corresponding pin
							SET_BIT(TIMER2->CCER, 4);

							//Active High
							CLR_BIT(TIMER2->CCER, 5);

							//ARR Value = 1000
							TIMER2->ARR = Copy_u16ARRValue;

							//CCR2 Value = 500
							TIMER2->CCR2 = Copy_u16CCR1Value;
							break;

		case CHANNEL3 :
							//Output Compare 3 preload enable
							SET_BIT(TIMER2->CCMR2, 3);

							//Channel 3 output
							CLR_BIT(TIMER2->CCMR2, 1);
							CLR_BIT(TIMER2->CCMR2, 0);

							//Output Compare mode PWM mode 1
							SET_BIT(TIMER2->CCMR2, 6);
							SET_BIT(TIMER2->CCMR2, 5);
							CLR_BIT(TIMER2->CCMR2, 4);

							//Signal on corresponding pin
							SET_BIT(TIMER2->CCER, 8);

							//Active High
							CLR_BIT(TIMER2->CCER, 9);

							//ARR Value = 1000
							TIMER2->ARR = Copy_u16ARRValue;

							//CCR3 Value = 500
							TIMER2->CCR3 = Copy_u16CCR1Value;
							break;

		case CHANNEL4 :
							//Output Compare 4 preload enable
							SET_BIT(TIMER2->CCMR2, 11);

							//Channel 4 output
							CLR_BIT(TIMER2->CCMR2,9);
							CLR_BIT(TIMER2->CCMR2,8);

							//Output Compare mode PWM mode 1
							SET_BIT(TIMER2->CCMR2,14);
							SET_BIT(TIMER2->CCMR2,13);
							CLR_BIT(TIMER2->CCMR2,12);

							//Signal on corresponding pin
							SET_BIT(TIMER2->CCER, 12);

							//Active High
							CLR_BIT(TIMER2->CCER,13);

							//ARR Value = 1000
							TIMER2->ARR = Copy_u16ARRValue;

							//CCR4 Value = 500
							TIMER2->CCR4 = Copy_u16CCR1Value;
							break;

	}

}

void TIMER2_voidSetCCRVal(u16 Copy_u16Val, u8 Copy_u8Channel)
{
	switch(Copy_u8Channel)
	{
		case CHANNEL1 :
						TIMER2->CCR1 = Copy_u16Val;
						break;
		case CHANNEL2 :
						TIMER2->CCR2 = Copy_u16Val;
						break;
		case CHANNEL3 :
						TIMER2->CCR3 = Copy_u16Val;
						break;
		case CHANNEL4 :
						TIMER2->CCR4 = Copy_u16Val;
						break;

	}
}

void TIMER2_voidSetARRVal(u16 Copy_u16Val)
{
	TIMER2->ARR = Copy_u16Val;
}

void TIMER2_voidPWMCounterEnable(void)
{
	//Counter enable
	SET_BIT(TIMER2->CR1,0);
}
