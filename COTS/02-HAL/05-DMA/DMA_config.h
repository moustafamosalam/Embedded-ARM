/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef DMA_CONFIG_H
#define DMA_CONFIG_H
/*			Initialization Channel									*/					
#define 	DMA_CHANNEL 				1
/*			Memory to memory or peripheral							*/
#define 	MEM2MEM						ENABLE
/*			Source data size	 									*/
#define 	MSIZE						32
/*			Destination Size										*/
#define 	PSIZE						32
/*			Memory increment Enable or Disable						*/
#define 	MINC						ENABLE
/*			Peripheral increment Enable or Disable					*/
#define 	PINC						ENABLE
/*			Circular mode 											*/
#define 	CIRC						DISABLE
/*			Data Source 											*/
#define 	DATA_SOURCE					MEMORY
/*			Interrupts												*/
#define 	TRANSFER_ERROR_INT			DISABLE
#define 	HALF_TRANSFER_INT			DISABLE
#define 	TRANSFER_COMP_INT			ENABLE


#endif