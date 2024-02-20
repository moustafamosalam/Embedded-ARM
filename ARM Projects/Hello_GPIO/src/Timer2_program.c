#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER2_interface.h"
#include "TIMER2_private.h"
#include "TIMER2_config.h"

void TIMER2_voidInit(void)
{
	SET_BIT(TIMER2->CR1,7);
	CLR_BIT(TIMER2->CR1,6);
	CLR_BIT(TIMER2->CR1,5);
	CLR_BIT(TIMER2->CR1,4);
	
	//SET_BIT(TIMER2->SR,1);
	
	CLR_BIT(TIMER2->CCMR1,4);
	SET_BIT(TIMER2->CCMR1,5);
	SET_BIT(TIMER2->CCMR1,6);
	SET_BIT(TIMER2->CCMR1,3);
	CLR_BIT(TIMER2->CCMR1,0);
	CLR_BIT(TIMER2->CCMR1,1);
	
	CLR_BIT(TIMER2->CCER,1);
	SET_BIT(TIMER2->CCER,0);
	
	TIMER2->PSC = PRESCALER;
	
}

void TIMER2_voidSetBusyWait(u16 Copy_u16Time)
{
	//Every Counter = 20 MicroSeconds
	TIMER2->ARR = Copy_u16Time;
	
	//Counter Enable
    SET_BIT(TIMER2->CR1,0);
	
	//Polliing till Counter Finishe
	while( (GET_BIT(TIMER2->SR, 0) ) == 0 );

	//Disable Counter & Clears Auto reload register 
	SET_BIT(TIMER2->CR1,0);
	TIMER2->ARR = 0;

}	

void TIMER2_voidPWM(u16 Copy_u16ARRValue, u16 Copy_u16CCR1Value)
{
	//Output Compare 1 preload enable
	SET_BIT(TIMER2->CCMR1, 3);

	//Channel 1 output
	CLR_BIT(TIMER2->CCMR1,1);
	CLR_BIT(TIMER2->CCMR1,0);

	//Signal on corresponding pin
	SET_BIT(TIMER2->CCMR1, 0);

	//Output Compare mode PWM mode 1 Active high
	SET_BIT(TIMER2->CCMR1,6);
	SET_BIT(TIMER2->CCMR1,5);
	CLR_BIT(TIMER2->CCMR1,4);

	//ARR Value = 1000
	TIMER2->ARR = Copy_u16ARRValue;

	//CCR1 Value = 500
	TIMER2->CCR1 = Copy_u16CCR1Value;

	//Counter enable
	SET_BIT(TIMER2->CR1,0);


}

