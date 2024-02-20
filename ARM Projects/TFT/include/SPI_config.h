/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#define 	CRC						CRC_DISABLE
#define 	DATA_FRAME				8
#define 	SPI_STATUS				SPI_ENABLE
#define 	SPI_SS_MANAGE			SW_SPI_MANAGMENT	
#define 	DATA_ORDER				MSB		
#define 	BAUD_RATE				CLK_2
#define 	MASTER_SELECT			SPI_MASTER	
#define 	CLK_POLARITY			FALLING_EDGE
#define 	CLK_PHASE				WRITE_READ
#define 	SPI_INTERRUPT_STATUS	INTERRUPT_DISABLE
	
#define 	SLAVE_SELECT_PIN		PORTA,PIN0
	
#endif
