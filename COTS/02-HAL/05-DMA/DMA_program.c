/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_


void DMA_voidInit(void)
{
/*		Clears the global interrupt of the configured channel		*/
	CLR_BIT(DMA->IFCR , ((DMA_CHANNEL-1)*4));
	
/*		Configuration of the channel								*/
			//Memory to memory config	
	#if MEM2MEM	== ENABLE
		SET_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 14);
	#elif MEM2MEM == DISABLE 
		CLR_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 14);
	#endif	
	
			//Memory Size config	
	#if	MSIZE == 8
		CLR_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 10);
		CLR_BIT(DMA->Channel[DMA_CHANNEL-1.CCR], 11);
	#elif MSIZE == 16
		SET_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 10);
		CLR_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 11);
	#elif MSIZE == 32
		CLR_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 10);
		SET_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 11);

			//Peripheral Size config	
	#if	PSIZE == 8
		CLR_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 8);
		CLR_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 9);
	#elif PSIZE == 16
		SET_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 8);
		CLR_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 9);
	#elif PSIZE == 32
		CLR_BIT(DMA->Channel[DMA_CHANNEL-1.CCR], 8);
		SET_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 9);
	#endif
	
		//Memory increment mode
	#if MINC == ENABLE
		SET_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 7);
	#elif MINC == DISABLE
		CLR_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 7);
	#endif
	
		//Peripheral increment mode
	#if PINC == ENABLE
		SET_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 6);
	#elif PINC == DISABLE
		CLR_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 6);
	#endif
	
		//Circular mode
	#if CIRC == ENABLE
		SET_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 5);
	#elif CIRC == DISABLE
		CLR_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 5);
	#endif
	
		//Data Transfer Direction
	#if DATA_SOURCE	==	MEMORY
		SET_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 4);
	#elif DATA_SOURCE	==	PERIPHERAL
		CLR_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 4);
	#endif
	
		//Transfer Error Interrupt
	#if	TRANSFER_ERROR_INT == ENABLE
		SET_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 3);
	#elif	TRANSFER_ERROR_INT == DISABLE
		CLR_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 3);
	#endif
	
		//Half Transfer Interrupt
	#if	HALF_TRANSFER_INT == ENABLE
		SET_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 2);
	#elif	HALF_TRANSFER_INT == DISABLE
		CLR_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 2);
	#endif
	
		//Transfer Complete Interrupt
	#if	TRANSFER_COMP_INT == ENABLE
		SET_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 1);
	#elif	TRANSFER_COMP_INT == DISABLE
		CLR_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 1);
	#endif
	
}

void DMA_voidStart(u32 *Copy_u32SourceAdd, u32 *Copy_u32DestinationAdd, u16 Copy_u16BlockSize)
{
		//Disable Channel 
	CLR_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 0);

		//Set Source address register 
	DMA->Channel[DMA_CHANNEL-1].CPAR = Copy_u32SourceAdd;

		//Set Destination Address
	DMA->Channel[DMA_CHANNEL-1].CPAR = Copy_u32DestinationAdd;
	
		//Set Number of Data register
	DMA->Channel[DMA_CHANNEL-1].CPAR = Copy_u16BlockSize;

		//Enable Channel
	SET_BIT(DMA->Channel[DMA_CHANNEL-1].CCR, 0);	

}