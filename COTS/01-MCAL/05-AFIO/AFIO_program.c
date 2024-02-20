/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_private.h"	
#include "AFIO_interface.h"
#include "AFIO_config.h"
#include "AFIO_private.h"



void AFIO_voidSetEXTIConfiguration(u8 Copy_u8Line, u8 Copy_u8Port)
{
	u8 Local_u8RegIndex = 0;
	Local_u8RegIndex = Copy_u8Line / 4;
	Copy_u8Line = Copy_u8Line % 4; 
	AFIO->EXTICR[Local_u8RegIndex] &= ~((0b1111)<<(Copy_u8Line * 4));
	AFIO->EXTICR[Local_u8RegIndex]  |= ((Copy_u8Port)<<(Copy_u8Line * 4));	
}