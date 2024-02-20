/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef USART1_CONFIG_H
#define USART1_CONFIG_H

#define USART1_BAUD_RATE	115200
#define	USART1_WORD_LENGTH	BIT_8
#define USART1_PARITY_MODE	DISABLE
#define USART1_INTERRUPT	RXNE_INT_ENABLE
#define USART1_TRANSMITTER	ENABLE
#define	USART1_RECEIVER		ENABLE
#define USART1_STOP_BITS	ONE_BIT

#endif
