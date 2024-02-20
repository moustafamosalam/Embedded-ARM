/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

void DMA_voidStart(u32 *Copy_u32SourceAdd, u32 *Copy_u32DestinationAdd, u16 Copy_u16BlockSize);
void DMA_voidInit(void);


#endif