/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef ESP_INTERFACE_H
#define ESP_INTERFACE_H

void ESP_voidInit(void);
void ESP_voidWifiConnect(u8* Copy_u8Name, u8* Copy_u8Password);
void ESP_voidServerConnect(u8* Copy_u8IP);
void ESP_voidReceiveData(u8* Copy_u8Website, u8 Copy_u8Length, s8* Copy_u8RcvData);

void ESP_voidClearBuffer ( void );

void Array2Integer(s8* Copy_u8Array);

#endif
