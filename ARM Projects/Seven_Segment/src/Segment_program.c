/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "Segment_interface.h"


void Segment_voidDisplayNumber(u8 Number)
{
	if(Number == 1)
	{
		GPIO_voidSetPinValue(PORTA, b, HIGH);
		GPIO_voidSetPinValue(PORTA, c, HIGH);
	}
	else if (Number == 2)
	{
		GPIO_voidSetPinValue(PORTA, a, HIGH);
		GPIO_voidSetPinValue(PORTA, b, HIGH);
		GPIO_voidSetPinValue(PORTA, g, HIGH);
		GPIO_voidSetPinValue(PORTA, e, HIGH);
		GPIO_voidSetPinValue(PORTA, d, HIGH);
	}
	else if (Number == 3)
	{
		GPIO_voidSetPinValue(PORTA, a, HIGH);
		GPIO_voidSetPinValue(PORTA, b, HIGH);
		GPIO_voidSetPinValue(PORTA, g, HIGH);
		GPIO_voidSetPinValue(PORTA, c, HIGH);
		GPIO_voidSetPinValue(PORTA, d, HIGH);
	}
	else if (Number == 4)
	{
		GPIO_voidSetPinValue(PORTA, f, HIGH);
		GPIO_voidSetPinValue(PORTA, b, HIGH);
		GPIO_voidSetPinValue(PORTA, g, HIGH);
		GPIO_voidSetPinValue(PORTA, c, HIGH);
	}
	else if (Number == 5)
	{
		GPIO_voidSetPinValue(PORTA, a, HIGH);
		GPIO_voidSetPinValue(PORTA, f, HIGH);
		GPIO_voidSetPinValue(PORTA, g, HIGH);
		GPIO_voidSetPinValue(PORTA, c, HIGH);
		GPIO_voidSetPinValue(PORTA, d, HIGH);
	}
	else if (Number == 6)
	{
		GPIO_voidSetPinValue(PORTA, a, HIGH);
		GPIO_voidSetPinValue(PORTA, f, HIGH);
		GPIO_voidSetPinValue(PORTA, g, HIGH);
		GPIO_voidSetPinValue(PORTA, c, HIGH);
		GPIO_voidSetPinValue(PORTA, d, HIGH);
		GPIO_voidSetPinValue(PORTA, e, HIGH);
	}
	else if (Number == 7)
	{
		GPIO_voidSetPinValue(PORTA, a, HIGH);
		GPIO_voidSetPinValue(PORTA, b, HIGH);
		GPIO_voidSetPinValue(PORTA, c, HIGH);
	}
	else if (Number == 8)
	{
		GPIO_voidSetPinValue(PORTA, a, HIGH);
		GPIO_voidSetPinValue(PORTA, b, HIGH);
		GPIO_voidSetPinValue(PORTA, c, HIGH);
		GPIO_voidSetPinValue(PORTA, d, HIGH);
		GPIO_voidSetPinValue(PORTA, e, HIGH);
		GPIO_voidSetPinValue(PORTA, f, HIGH);
		GPIO_voidSetPinValue(PORTA, g, HIGH);
	}
	else if (Number == 9)
	{
		GPIO_voidSetPinValue(PORTA, a, HIGH);
		GPIO_voidSetPinValue(PORTA, b, HIGH);
		GPIO_voidSetPinValue(PORTA, c, HIGH);
		GPIO_voidSetPinValue(PORTA, d, HIGH);
		GPIO_voidSetPinValue(PORTA, f, HIGH);
		GPIO_voidSetPinValue(PORTA, g, HIGH);
	}
	else if (Number == 0)
	{
		GPIO_voidSetPinValue(PORTA, a, HIGH);
		GPIO_voidSetPinValue(PORTA, b, HIGH);
		GPIO_voidSetPinValue(PORTA, c, HIGH);
		GPIO_voidSetPinValue(PORTA, d, HIGH);
		GPIO_voidSetPinValue(PORTA, e, HIGH);
		GPIO_voidSetPinValue(PORTA, f, HIGH);
	}
} 