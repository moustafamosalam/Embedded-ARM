/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef TIMER2_INTERFACE_H
#define TIMER2_INTERFACE_H

void TIMER2_voidSetBusyWait(u16 Copy_u16Time);
void TIMER2_voidInit(void);
void TIMER2_voidPWM(u16 Copy_u16ARRValue, u16 Copy_u16CCR1Value);

#endif
