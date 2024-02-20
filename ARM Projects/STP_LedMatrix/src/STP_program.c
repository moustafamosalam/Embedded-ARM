/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

#include "STP_interface.h"
#include "STP_config.h"
#include "STP_private.h"

void STP_voidInit(void)
{
	GPIO_voidSetPinDirection(STP_DATA_SERIAL,   OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(STP_STORAGE_CLOCK, OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(STP_SHIFT_CLOCK,   OUTPUT_2MHZ_PP);
}

void STP_voidSendData(u8 Copy_NumOfIC, u16 Copy_u16Data)
{
	s8 i;
	u8 Local_u8Temp=0;
	if (Copy_NumOfIC == 1)
	{
		for(i=7;i>=0;i--)
		{
			Local_u8Temp = GET_BIT(Copy_u16Data, i);
			GPIO_voidSetPinValue(STP_DATA_SERIAL, Local_u8Temp);
			
	/*			Send Pulse to Shift Clock				*/	
			GPIO_voidSetPinValue(STP_SHIFT_CLOCK, HIGH);
			STK_voidSetBusyWait(1);
			GPIO_voidSetPinValue(STP_SHIFT_CLOCK, LOW);
		}
	/*			Send Pulse to Storage Clock				*/
		GPIO_voidSetPinValue(STP_STORAGE_CLOCK, HIGH);
		STK_voidSetBusyWait(1);
		GPIO_voidSetPinValue(STP_STORAGE_CLOCK, LOW);
	}
	else if(Copy_NumOfIC == 2)
	{
		for(i=15;i>=0;i--)
		{
			Local_u8Temp = GET_BIT(Copy_u16Data, i);
			GPIO_voidSetPinValue(STP_DATA_SERIAL, Local_u8Temp);
			
	/*			Send Pulse to Shift Clock				*/	
			GPIO_voidSetPinValue(STP_SHIFT_CLOCK, HIGH);
			STK_voidSetBusyWait(5);
			GPIO_voidSetPinValue(STP_SHIFT_CLOCK, LOW);
		}
	/*			Send Pulse to Storage Clock				*/
		GPIO_voidSetPinValue(STP_STORAGE_CLOCK, HIGH);
		STK_voidSetBusyWait(5);
		GPIO_voidSetPinValue(STP_STORAGE_CLOCK, LOW);
	}
}
