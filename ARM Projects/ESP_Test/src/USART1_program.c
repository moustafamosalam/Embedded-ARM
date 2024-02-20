/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART1_interface.h"
#include "USART1_private.h"
#include "USART1_config.h"

void (*USART1_CallBack)(void);

void USART1_voidInit(void)
{
	#if 	USART1_BAUD_RATE 	==		9600
		USART1->BRR = 0x341;
	#elif	USART1_BAUD_RATE 	==		115200
		USART1->BRR = 0x45;
	#endif
	
	#if		USART1_WORD_LENGTH	== 		BIT_8
		CLR_BIT(USART1->CR1, 12);
	#elif	USART1_WORD_LENGTH	==		BIT_9
		SET_BIT(USART1->CR1, 12);
	#endif
	
	#if		USART1_PARITY_MODE	==		EVEN
		SET_BIT(USART1->CR1, 10);
		CLR_BIT(USART1->CR1, 9);
	#elif	USART1_PARITY_MODE	==		ODD
		SET_BIT(USART1->CR1, 10);	
		SET_BIT(USART1->CR1, 9);
	#elif	USART1_PARITY_MODE	==		DISABLE
		CLR_BIT(USART1->CR1, 10);
	#endif
	
	#if		USART1_INTERRUPT	==	DISABLE
		CLR_BIT(USART1->CR1, 5);
		CLR_BIT(USART1->CR1, 6);
		CLR_BIT(USART1->CR1, 7);
	#elif	USART1_INTERRUPT	==	TXE_INT_ENABLE
		SET_BIT(USART1->CR1, 7);	
	#elif	USART1_INTERRUPT	==	TCE_INT_ENABLE
		SET_BIT(USART1->CR1, 6);	
	#elif	USART1_INTERRUPT	==	RXNE_INT_ENABLE
		SET_BIT(USART1->CR1, 5);		
	#endif
	
	#if		USART1_TRANSMITTER	==		ENABLE
		SET_BIT(USART1->CR1, 3);
	#elif	USART1_TRANSMITTER	==		DISABLE
		CLR_BIT(USART1->CR1, 3);
	#endif
	
	#if		USART1_RECEIVER		==		ENABLE
		SET_BIT(USART1->CR1, 2);	
	#elif	USART1_RECEIVER		==		DISABLE
		CLR_BIT(USART1->CR1, 2);
	#endif
	
	#if			USART1_STOP_BITS	==		HALF_BIT
		CLR_BIT(USART1->CR2, 13);
		SET_BIT(USART1->CR2, 12);
	#elif		USART1_STOP_BITS	==		ONE_BIT
		CLR_BIT(USART1->CR2, 13);
		CLR_BIT(USART1->CR2, 12);
	#elif		USART1_STOP_BITS	==		ONE_HALF_BIT
		SET_BIT(USART1->CR2, 13);
		SET_BIT(USART1->CR2, 12);
	#elif		USART1_STOP_BITS	==		TWO_BIT
		SET_BIT(USART1->CR2, 13);
		CLR_BIT(USART1->CR2, 12);
	#endif

	
	//USART1 Enable
	SET_BIT(USART1->CR1, 13);
	//Clearing Status Register
	USART1->SR = 0;
}

void USART1_voidSendChar(u8 Copy_u8Char)
{
	USART1->DR = Copy_u8Char;
	while(GET_BIT(USART1->SR,6) == 0);
	CLR_BIT(USART1->SR , 6);
}

void USART1_voidSendString(u8* Copy_u8String)
{
	u8 i=0;
	while(Copy_u8String[i] != '\0' )
	{
		USART1_voidSendChar(Copy_u8String[i]);
		i++;
	}
}

u8 	 USART1_voidReceive(u8* Copy_u8Data)
{
	u8 Local_u8Result = 1;

		if ( (GET_BIT((USART1 -> SR), 5)) == 1 )
		{
			*Copy_u8Data = USART1 -> DR;
		}
		else
		{
			Local_u8Result = 0;
		}

		return (Local_u8Result);
}

u8 USART1_u8ReadDataReg ( void ){

	return ( USART1 -> DR );

}

void USART1_voidClrAllFlags(void)
{
	//Clear All Flags
	USART1 -> SR = 0;
}

void USART1_voidSetCallBack( void (*ptr) (void) ){

	USART1_CallBack = ptr ;

}

void USART1_IRQHandler(void){

	USART1_CallBack();

}
