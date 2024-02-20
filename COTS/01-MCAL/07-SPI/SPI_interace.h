/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void SPI_voidInit(void);
u16  SPI_u16SendReceive(u16 Copy_u16Data);	
u8   SPI_u8SendReceiveSynch(u8 Copy_u8SentData);
void SPI_voidSendReceiveAsynch(u8 Copy_u8SentData, void (CallBack)(u8));

#endif