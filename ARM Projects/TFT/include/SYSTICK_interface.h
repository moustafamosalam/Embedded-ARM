/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

void STK_voidInit(void);
void STK_voidSetBusyWait(u32 Copy_u32Ticks);
void STK_voidSetInterval(u32 Copy_u32Ticks, void (*Copy_ptr) (void), u8 Copy_u8IntervalMode);
void STK_voidStopCounts(void);
u32  STK_voidGetElapsedTime(void);
u32	 STK_voidGetRemainingTime(void);

//Copy_u8IntervalMode can be :
#define SINGLE_INTERVAL		1
#define PERIODIC_INTERVAL	2

#endif