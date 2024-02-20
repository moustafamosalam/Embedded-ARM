/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef USART1_PRIVATE_H
#define USART1_PRIVATE_H

typedef struct{
	
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
	
}USART1_Type;

#define USART1	((volatile USART1_Type*)(0x40013800))


#define BIT_8	0
#define BIT_9	1

#define DISABLE 0
#define	ENABLE	1

#define EVEN	1
#define ODD		2

#define TXE_INT_ENABLE	1
#define	TCE_INT_ENABLE	2
#define RXNE_INT_ENABLE 3

#define HALF_BIT		0
#define ONE_BIT			1
#define ONE_HALF_BIT	2
#define TWO_BIT			3

#endif
