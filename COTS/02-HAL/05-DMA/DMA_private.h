/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

typedef struct {
	
	u32 CCR;
	u32 CNDTR;
	u32 CPAR;
	u32 CMAR;
	u32 reserved;
	
}DMA_type;

typedef struct{
	
	u32 ISR;
	u32 IFCR;
	DMA_type Channel[7];
}DMA_Channel;

#define 	DMA 	((volatile DMA_Channel * )(0x40020000))

#define 	DISABLE 		0
#define 	ENABLE			1

#define 	MEMORY			1
#define 	PERIPHERAL		0

#endif