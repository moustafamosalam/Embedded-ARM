/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 CRCPR;
	volatile u32 RXCRCR;
	volatile u32 TXCRCR;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR;
	
}SPI_Type;

#define		SPI		((volatile SPI_Type *)(0x40013000))


#define 	CRC_DISABLE			0
#define 	CRC_ENABLE			1

#define 	SPI_DISABLE			0
#define 	SPI_ENABLE			1

#define 	HW_SPI_MANAGMENT	0
#define 	SW_SPI_MANAGMENT	1

#define 	MSB					1
#define 	LSB					0

#define 	CLK_2				0
#define 	CLK_4				1
#define 	CLK_8				2
#define 	CLK_16				3
#define 	CLK_32				4
#define 	CLK_64				5
#define 	CLK_128				6

#define 	SPI_SLAVE			0
#define 	SPI_MASTER			1	

#define 	FALLING_EDGE		0
#define 	RISING_EDGE			1

#define 	WRITE_READ			0
#define 	READ_WRITE			1

#define 	INTERRUPT_DISABLE	0
#define 	TRANSFER_INTERRUPT	1
#define 	RECEIVE_INTERRUPT	2

#endif
