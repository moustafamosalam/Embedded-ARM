/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "SPI_interface.h"

#include "TFT_interface.h"
#include "TFT_config.h"
#include "TFT_private.h"

void TFT_voidInit(void)
{
/*				Reset Pulse						*/
	GPIO_voidSetPinValue(TFT_RST_PIN, HIGH);
	STK_voidSetBusyWait(100);
	GPIO_voidSetPinValue(TFT_RST_PIN, LOW);
	STK_voidSetBusyWait(1);
	GPIO_voidSetPinValue(TFT_RST_PIN, HIGH);
	STK_voidSetBusyWait(100);
	GPIO_voidSetPinValue(TFT_RST_PIN, LOW);
	STK_voidSetBusyWait(100);
	GPIO_voidSetPinValue(TFT_RST_PIN, HIGH);
	STK_voidSetBusyWait(120000);

/* 				Sleep Out Command 				*/
	TFT_voidWriteCommand(0x11);
	
/* 				Wait 150 ms 					*/
	STK_voidSetBusyWait(150000);
	
/* 				Color Mode Command 				*/
	TFT_voidWriteCommand(0x3A);
	TFT_voidWriteData(0x05);
	
/* 				Display On Command 				*/
	TFT_voidWriteCommand(0x29);	
	
}

void TFT_voidDisplayImage(const u16 *Copy_u16Image)
{
	u16 counter;
	u8 Data;
	
/*				Inizialize Start and End point	*/

	/* Set X Address */
	TFT_voidWriteCommand(0x2A);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(127);
	
	/* Set Y Address */
	TFT_voidWriteCommand(0x2B);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(159);	
	
/*			 	RAM Write 							*/
	TFT_voidWriteCommand(0x2C);

	for(counter = 0; counter< 20480;counter++)
	{
		Data = Copy_u16Image[counter] >> 8;

		/* Write the high byte */
		TFT_voidWriteData(Data);
		/* Write the low byte */
		Data = Copy_u16Image[counter] & 0x00ff;
		TFT_voidWriteData(Data);
	}


}

void TFT_voidFillColor(u16 Copy_u16Color)
{
	u16 counter;
	u8 Data;
	
/*				Inizialize Start and End point	*/

	/* Set X Address */
	TFT_voidWriteCommand(0x2A);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(127);
	
	/* Set Y Address */
	TFT_voidWriteCommand(0x2B);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(159);		
	
/*			 	RAM Write 							*/
	TFT_voidWriteCommand(0x2C);

	for(counter = 0; counter< 20480;counter++)
	{
		Data = Copy_u16Color >> 8;

		/* Write the high byte */
		TFT_voidWriteData(Data);
		/* Write the low byte */
		Data = Copy_u16Color & 0x00ff;
		TFT_voidWriteData(Data);
	}


}

void TFT_voidDrawRect(u8 x1, u8 x2, u8 y1, u8 y2, u16 Copy_u16Color)
{
	u16 counter;
	u8 Data;
	u16 size = (x2-x1)*(y2-y1);

/*				Inizialize Start and End point	*/

	/* Set X Address */
	TFT_voidWriteCommand(0x2A);
	TFT_voidWriteData(0);
	TFT_voidWriteData(x1);
	TFT_voidWriteData(0);
	TFT_voidWriteData(x2);
	
	/* Set Y Address */
	TFT_voidWriteCommand(0x2B);
	TFT_voidWriteData(0);
	TFT_voidWriteData(y1);
	TFT_voidWriteData(0);
	TFT_voidWriteData(y2);		
	
/*			 	RAM Write 							*/
	TFT_voidWriteCommand(0x2C);

	for(counter = 0; counter< size;counter++)
	{
		Data = Copy_u16Color >> 8;

		/* Write the high byte */
		TFT_voidWriteData(Data);
		/* Write the low byte */
		Data = Copy_u16Color & 0x00ff;
		TFT_voidWriteData(Data);
	}


}

void TFT_voidWriteChar(u8 *Copy_u8Char, u8 Xaxis, u8 Yaxis, u8 Copy_u8Color)
{
	u8 Local_u8Compare = 0x01;
	u8 Local_u8Data;
	u8 Local_u8Pixel;
	for(u8 Counter1=0; Counter1<5; Counter1++)
	{
		for(u8 Counter2=0; Counter2<7; Counter2++)
		{
			/* Set X Address */
			TFT_voidWriteCommand(0x2A);
			TFT_voidWriteData(0);
			TFT_voidWriteData(Xaxis+Counter1);
			TFT_voidWriteData(0);
			TFT_voidWriteData(Xaxis+Counter1);
			/* Set Y Address */
			TFT_voidWriteCommand(0x2B);
			TFT_voidWriteData(0);
			TFT_voidWriteData(Yaxis+Counter2);
			TFT_voidWriteData(0);
			TFT_voidWriteData(Yaxis+Counter2);
/*			 	RAM Write 								*/
			TFT_voidWriteCommand(0x2C);			
			
			Local_u8Data = (Copy_u8Char[Counter1] & Local_u8Compare);
			if(Local_u8Data == 0)	{  Local_u8Pixel = 0x0000;		  }
			else 					{  Local_u8Pixel = Copy_u16Color; }	
			
			TFT_voidWriteData(Local_u8Pixel >> 8);
			TFT_voidWriteData(Local_u8Pixel & 0x00ff);
			
			Local_u8Compare <<= 1;
		}
		Local_u8Compare = 0x01;
	}
	
}

static void TFT_voidWriteCommand(u8 Copy_u8Command)
{
/*				Set TFT A0 Pin Low for Command  */	
	GPIO_voidSetPinValue(TFT_A0_PIN, LOW);
	
/*				Send command over SPI		   	*/	
	(void) SPI_u8SendReceiveSynch(Copy_u8Command);
}

static void TFT_voidWriteData(u8 Copy_u8Data)
{
/*				Set TFT A0 Pin HIGH for Command */	
	GPIO_voidSetPinValue(TFT_A0_PIN, HIGH);
	
/*				Send Data over SPI			   	*/	
	(void) SPI_u8SendReceiveSynch(Copy_u8Data);
}