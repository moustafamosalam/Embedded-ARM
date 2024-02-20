/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

void AFIO_voidSetEXTIConfiguration(u8 Copy_u8Line, u8 Copy_u8Port);

/*	Copy_u8Port can be PORTA or PORTB or PORTC					 */
#define 	AFIO_PORTA		0b0000
#define 	AFIO_PORTB		0b0001
#define 	AFIO_PORTC		0b0010

#endif
