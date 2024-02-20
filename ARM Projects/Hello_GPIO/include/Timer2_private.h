/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef TIMER2_PRIVATE_H
#define TIMER2_PRIVATE_H

typedef struct{
	
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMCR;
	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;
	volatile u32 CCMR1;
	volatile u32 CCMR2;
	volatile u32 CCER;
	volatile u32 CNT;
	volatile u32 PSC;
	volatile u32 ARR;
	volatile u32 RESERVED1;
	volatile u32 CCR1;
	volatile u32 CCR2;
	volatile u32 CCR3;
	volatile u32 CCR4;
	volatile u32 RESERVED2;
	volatile u32 DCR;
	volatile u32 DMAR;
	
}Timer_Type;

#define 	TIMER2		((volatile Timer_Type *)(0x40000000))
#define 	TIMER3		((volatile Timer_Type *)(0x40000400))
#define 	TIMER4		((volatile Timer_Type *)(0x40000800))
#define 	TIMER5		((volatile Timer_Type *)(0x40000C00))



#define CLK_2		2
#define CLK_4		4
#define CLK_8		8
#define CLK_80		80
#define CLK_160		160


#endif
