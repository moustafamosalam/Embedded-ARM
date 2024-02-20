/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

void (*EXTI0_CallBack) (void);

void EXTI_voidInit(u8 Copy_u8Line, u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
		case RISING_EDGE  :	SET_BIT(EXTI->RTSR, Copy_u8Line); break;
		case FALLING_EDGE :	SET_BIT(EXTI->FTSR, Copy_u8Line); break;
		case ON_CHANGE    :	SET_BIT(EXTI->RTSR, Copy_u8Line);
							SET_BIT(EXTI->FTSR, Copy_u8Line); break;	
	}                       
	SET_BIT(EXTI->IMR, Copy_u8Line);	
	
}

void EXTI_voidEnableEXTI(u8 Copy_u8Line)
{
	SET_BIT(EXTI->IMR, Copy_u8Line);
}

void EXTI_voidDisableEXTI(u8 Copy_u8Line)
{
	CLR_BIT(EXTI->IMR, Copy_u8Line);
}

void EXTI_voidSwTrigger(u8 Copy_u8Line)
{
	SET_BIT(EXTI->SWIER, Copy_u8Line);
}

//////////////////////////////////////////////////// ISR 0 ///////////////////////////////////////////////////////////
void EXTI0_voidSetCallBack( void (*ptr) (void) ){

	EXTI0_CallBack = ptr;

}
void EXTI0_IRQHandler(void){

	EXTI0_CallBack();
	SET_BIT( EXTI->PR , 0 );

}