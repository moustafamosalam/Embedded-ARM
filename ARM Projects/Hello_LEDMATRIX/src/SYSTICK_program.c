/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"

//////////////////////////////// Call Back Function ////////////////////////////////////////////////
/*////////////////////////////////////////////////////////////////////////////////////////////////*/
void (*STK_CallBack) (void);
/*///////////////////////////////////////////////////////////////////////////////////////////////*/
///////////////////////////////////////////////////////////////////////////////////////////////////

u8 Global_u8ModeofInterval = 0 ;

void STK_voidInit(void)
{
//Counter Disable 
	CLR_BIT(STK->CTRL , 0); 
//Clock Source
	#if 	CLK_SOURCE == CLK_AHB
		SET_BIT(STK->CTRL , 2);
	#elif	CLK_SOURCE == CLK_AHB_8
		CLR_BIT(STK->CTRL , 2);
	#endif
//Disable Interrupt
	CLR_BIT(STK->CTRL , 1);
	
}

void STK_voidSetBusyWait(u32 Copy_u32Ticks)
{
//Reload Value 	
	STK->LOAD = Copy_u32Ticks;
//Counter Enable 
	SET_BIT(STK->CTRL , 0);	
//Polling till counter finish	
while((GET_BIT(STK->CTRL, 16)) == 0);
//Clear LOAD & VAL Register	
	CLR_BIT(STK->CTRL, 0);
	STK->LOAD = 0 ;
	STK->VAL  = 0 ; 
}

void STK_voidSetInterval(u32 Copy_u32Ticks, void (*Copy_ptr) (void), u8 Copy_u8IntervalMode)
{
//Reload Value 	
	STK->LOAD = Copy_u32Ticks;
//Interrupt & Counter Enable 
	SET_BIT(STK->CTRL , 1);
	SET_BIT(STK->CTRL , 0);	
//Send CallBack Function
	STK_CallBack = Copy_ptr;
//Set Interval Mode	
	Global_u8ModeofInterval = Copy_u8IntervalMode;
}

void STK_voidStopCounts(void)
{
//Disable Interrupt
	CLR_BIT(STK->CTRL, 1);
//Stop Timer
	CLR_BIT(STK->CTRL, 0);
	STK->LOAD = 0;
	STK->VAL = 0;
}
u32  STK_voidGetElapsedTime(void)
{
	u32 Local_u8ElapsedTime = 0;
	Local_u8ElapsedTime = STK->VAL ;
	return Local_u8ElapsedTime;
}
u32	 STK_voidGetRemainingTime(void)
{
	u32 Local_u8RemainingTime = 0;
	Local_u8RemainingTime = (STK->LOAD)-(STK->VAL);
	return Local_u8RemainingTime;	
}

void SysTick_Handler(void)
{
	u8 Local_u8Flag = 0;
	
	if (Global_u8ModeofInterval == SINGLE_INTERVAL)
	{
	//Disable Interrupt
		CLR_BIT(STK->CTRL, 1);
	//Stop Timer
		CLR_BIT(STK->CTRL, 0);
		STK->LOAD = 0;
		STK->VAL  = 0;
	}
	
	STK_CallBack();
	Local_u8Flag = GET_BIT(STK->CTRL, 16);
}
