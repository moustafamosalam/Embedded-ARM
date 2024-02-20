/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef USART1_INTERFACE_H
#define USART1_INTERFACE_H

void USART1_voidInit(void);

void USART1_voidSendChar(u8 Copy_u8Char);
void USART1_voidSendString(u8* Copy_u8String);

u8 USART1_u8ReadDataReg ( void );

u8 	 USART1_voidReceive(u8* Copy_u8Data);

void USART1_voidSetCallBack( void (*ptr) (void) );
void USART1_voidClrAllFlags(void);

#endif
