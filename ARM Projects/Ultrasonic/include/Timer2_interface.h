/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef TIMER2_INTERFACE_H
#define TIMER2_INTERFACE_H

void TIMER2_voidSetBusyWait(u16 Copy_u16Time);
void TIMER2_voidInit(void);
void TIMER2_voidPWM(u16 Copy_u16ARRValue, u16 Copy_u16CCR1Value, u8 Copy_u8Channel);
void TIMER2_voidSetCCRVal(u16 Copy_u16Val, u8 Copy_u8Channel);
void TIMER2_voidSetARRVal(u16 Copy_u16Val);

void TIMER2_voidStartCounter(void);
void TIMER2_voidStopCounter(void);
u16 TIMER2_voidGetElapsedTime(void);

#define CHANNEL1	0	
#define CHANNEL2	1
#define CHANNEL3	2
#define CHANNEL4	3

#endif
