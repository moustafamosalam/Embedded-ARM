/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"

void (*SPI_CallBack) (u8);

void SPI_voidInit(void)
{
//SPI Disable for Initialization
	CLR_BIT(SPI->CR1, 6);
	
//Initialization
	#if		CRC	==	DISABLE
		CLR_BIT(SPI->CR1, 13);
	#elif	CRC	==	ENABLE	
		SET_BIT(SPI->CR1, 13);
	#endif
		
	#if		DATA_FRAME	==	8
		CLR_BIT(SPI->CR1, 11);
	#elif	DATA_FRAME	==	16
		SET_BIT(SPI->CR1, 11);
	#endif
	
	#if		DATA_ORDER	==	MSB
		CLR_BIT(SPI->CR1, 7);
	#elif	DATA_ORDER	==	LSB
		SET_BIT(SPI->CR1, 7);
	#endif

	#if		MASTER_SELECT	==	SPI_MASTER	
		SET_BIT(SPI->CR1, 2);
		SET_BIT(SPI->CR1, 9);
		SET_BIT(SPI->CR1, 8);
	#elif	MASTER_SELECT	==	SPI_SLAVE
		CLR_BIT(SPI->CR1, 2);
		CLR_BIT(SPI->CR1, 9);
	#endif

	#if		CLK_POLARITY	==	RISING_EDGE
		CLR_BIT(SPI->CR1, 1);
	#elif	CLK_POLARITY	==	FALLING_EDGE
		SET_BIT(SPI->CR1, 1);
	#endif	
	
	#if		CLK_PHASE	==	WRITE_READ
		SET_BIT(SPI->CR1, 0);
	#elif	CLK_PHASE	==	READ_WRITE
		CLR_BIT(SPI->CR1, 0);	
	#endif	
	
	#if 	BAUD_RATE	==	CLK_2
		CLR_BIT(SPI->CR1, 3);
		CLR_BIT(SPI->CR1, 3);
		CLR_BIT(SPI->CR1, 3);
	#elif 	BAUD_RATE	==	CLK_4
		SET_BIT(SPI->CR1, 3);
		CLR_BIT(SPI->CR1, 3);
		CLR_BIT(SPI->CR1, 3);	
	#elif 	BAUD_RATE	==	CLK_8
		CLR_BIT(SPI->CR1, 3);
		SET_BIT(SPI->CR1, 3);
		CLR_BIT(SPI->CR1, 3);	
	#elif 	BAUD_RATE	==	CLK_16
		SET_BIT(SPI->CR1, 3);
		SET_BIT(SPI->CR1, 3);
		CLR_BIT(SPI->CR1, 3);	
	#elif 	BAUD_RATE	==	CLK_32
		CLR_BIT(SPI->CR1, 3);
		CLR_BIT(SPI->CR1, 3);
		SET_BIT(SPI->CR1, 3);	
	#elif 	BAUD_RATE	==	CLK_64
		SET_BIT(SPI->CR1, 3);
		CLR_BIT(SPI->CR1, 3);
		SET_BIT(SPI->CR1, 3);	
	#elif 	BAUD_RATE	==	CLK_128
		CLR_BIT(SPI->CR1, 3);
		SET_BIT(SPI->CR1, 3);
		SET_BIT(SPI->CR1, 3);		
	#endif
	
	#if 	SPI_INTERRUPT_STATUS	==	INTERRUPT_DISABLE
		CLR_BIT(SPI->CR2, 6);
		CLR_BIT(SPI->CR2, 7);
	#elif 	SPI_INTERRUPT_STATUS	==	TRANSFER_INTERRUPT
		CLR_BIT(SPI->CR2, 6);
		SET_BIT(SPI->CR2, 7);	
	#elif 	SPI_INTERRUPT_STATUS	==	RECEIVE_INTERRUPT
		SET_BIT(SPI->CR2, 6);
		CLR_BIT(SPI->CR2, 7);
	#endif	
	
//SPI Enable
	SET_BIT(SPI->CR1, 6);			
}

u16  SPI_u16SendReceiveSynch(u16 Copy_u16SentData)
{
	u16 Local_u16RcvData;
	GPIO_voidSetPinValue(SLAVE_SELECT_PIN, LOW);
	SPI->DR = Copy_u16SentData;
	while (GET_BIT(SPI->SR, 7) == 1);
	GPIO_voidSetPinValue(SLAVE_SELECT_PIN, HIGH);
	Local_u16RcvData = SPI->DR;
	return Local_u16RcvData;
}

u8  SPI_u8SendReceiveSynch(u8 Copy_u8SentData)
{
	u8 Local_u8RcvData;
	GPIO_voidSetPinValue(SLAVE_SELECT_PIN, LOW);
	SPI->DR = Copy_u8SentData;
	while (GET_BIT(SPI->SR, 7) == 1);
	GPIO_voidSetPinValue(SLAVE_SELECT_PIN, HIGH);
	Local_u8RcvData = SPI->DR;
	return Local_u8RcvData;
}

void SPI_voidSendReceiveAsynch(u8 Copy_u8SentData, void (CallBack)(u8))
{
	GPIO_voidSetPinValue(SLAVE_SELECT_PIN, LOW);
	SPI->DR = Copy_u8SentData;
	while (GET_BIT(SPI->SR, 7) == 1);
	GPIO_voidSetPinValue(SLAVE_SELECT_PIN, HIGH);
	SPI_CallBack = CallBack;
}

void SPI1_IRQHandler(void)
{
	SPI_CallBack(SPI->DR);
}

