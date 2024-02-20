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
	switch(Number)
	{
	case(1):GPIO_voidSetPinValue(PORTA, a, LOW);
			GPIO_voidSetPinValue(PORTA, b, HIGH);
			GPIO_voidSetPinValue(PORTA, c, HIGH);
			GPIO_voidSetPinValue(PORTA, d, LOW);
			GPIO_voidSetPinValue(PORTA, e, LOW);
			GPIO_voidSetPinValue(PORTA, f, LOW);
			GPIO_voidSetPinValue(PORTA, g, LOW);
			break;
	case(2):
			GPIO_voidSetPinValue(PORTA, a, HIGH);
			GPIO_voidSetPinValue(PORTA, b, HIGH);
			GPIO_voidSetPinValue(PORTA, c, LOW);
			GPIO_voidSetPinValue(PORTA, g, HIGH);
			GPIO_voidSetPinValue(PORTA, e, HIGH);
			GPIO_voidSetPinValue(PORTA, f, LOW);
			GPIO_voidSetPinValue(PORTA, d, HIGH);
			break;
	case(3):
			GPIO_voidSetPinValue(PORTA, a, HIGH);
			GPIO_voidSetPinValue(PORTA, b, HIGH);
			GPIO_voidSetPinValue(PORTA, g, HIGH);
			GPIO_voidSetPinValue(PORTA, c, HIGH);
			GPIO_voidSetPinValue(PORTA, d, HIGH);
			GPIO_voidSetPinValue(PORTA, e, LOW);
			GPIO_voidSetPinValue(PORTA, f, LOW);
			break;
	case(4):
			GPIO_voidSetPinValue(PORTA, a, LOW);
			GPIO_voidSetPinValue(PORTA, d, LOW);
			GPIO_voidSetPinValue(PORTA, e, LOW);
			GPIO_voidSetPinValue(PORTA, f, HIGH);
			GPIO_voidSetPinValue(PORTA, b, HIGH);
			GPIO_voidSetPinValue(PORTA, g, HIGH);
			GPIO_voidSetPinValue(PORTA, c, HIGH);
			break;
	case(5):
			GPIO_voidSetPinValue(PORTA, a, HIGH);
			GPIO_voidSetPinValue(PORTA, b, LOW);
			GPIO_voidSetPinValue(PORTA, e, LOW);
			GPIO_voidSetPinValue(PORTA, f, HIGH);
			GPIO_voidSetPinValue(PORTA, g, HIGH);
			GPIO_voidSetPinValue(PORTA, c, HIGH);
			GPIO_voidSetPinValue(PORTA, d, HIGH);
			break;
	case(6):
			GPIO_voidSetPinValue(PORTA, a, HIGH);
			GPIO_voidSetPinValue(PORTA, b, LOW);
			GPIO_voidSetPinValue(PORTA, f, HIGH);
			GPIO_voidSetPinValue(PORTA, g, HIGH);
			GPIO_voidSetPinValue(PORTA, c, HIGH);
			GPIO_voidSetPinValue(PORTA, d, HIGH);
			GPIO_voidSetPinValue(PORTA, e, HIGH);
			break;
	case(7):
			GPIO_voidSetPinValue(PORTA, a, HIGH);
			GPIO_voidSetPinValue(PORTA, b, HIGH);
			GPIO_voidSetPinValue(PORTA, c, HIGH);
			GPIO_voidSetPinValue(PORTA, d, LOW);
			GPIO_voidSetPinValue(PORTA, e, LOW);
			GPIO_voidSetPinValue(PORTA, f, LOW);
			GPIO_voidSetPinValue(PORTA, g, LOW);
			break;
	case(8):
			GPIO_voidSetPinValue(PORTA, a, HIGH);
			GPIO_voidSetPinValue(PORTA, b, HIGH);
			GPIO_voidSetPinValue(PORTA, c, HIGH);
			GPIO_voidSetPinValue(PORTA, d, HIGH);
			GPIO_voidSetPinValue(PORTA, e, HIGH);
			GPIO_voidSetPinValue(PORTA, f, HIGH);
			GPIO_voidSetPinValue(PORTA, g, HIGH);
			break;
	case(9):
			GPIO_voidSetPinValue(PORTA, a, HIGH);
			GPIO_voidSetPinValue(PORTA, b, HIGH);
			GPIO_voidSetPinValue(PORTA, c, HIGH);
			GPIO_voidSetPinValue(PORTA, d, HIGH);
			GPIO_voidSetPinValue(PORTA, e, LOW);
			GPIO_voidSetPinValue(PORTA, f, HIGH);
			GPIO_voidSetPinValue(PORTA, g, HIGH);
			break;
	case(0):
			GPIO_voidSetPinValue(PORTA, a, HIGH);
			GPIO_voidSetPinValue(PORTA, b, HIGH);
			GPIO_voidSetPinValue(PORTA, c, HIGH);
			GPIO_voidSetPinValue(PORTA, d, HIGH);
			GPIO_voidSetPinValue(PORTA, e, HIGH);
			GPIO_voidSetPinValue(PORTA, f, HIGH);
			GPIO_voidSetPinValue(PORTA, g, LOW);
			break;
	}
} 
