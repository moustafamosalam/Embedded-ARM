/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void GPIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
	switch(Copy_u8Port)
	{
		case PORTA :
					if(Copy_u8Pin <=7)
					{
						GPIOA_CRL &= ~((0b1111)<<( Copy_u8Pin*4));
						GPIOA_CRL |=  ((Copy_u8Mode)<<( Copy_u8Pin*4));
					}
					else if(Copy_u8Pin <=15)
					{
						Copy_u8Pin = Copy_u8Pin - 8;
						GPIOA_CRH &= ~((0b1111)<<( Copy_u8Pin*4));
						GPIOA_CRH |=  ((Copy_u8Mode)<<( Copy_u8Pin*4));
					}
					break;
		case PORTB :
					if(Copy_u8Pin <=7)
					{
						GPIOB_CRL &= ~((0b1111)<<( Copy_u8Pin*4));
						GPIOB_CRL |=  ((Copy_u8Mode)<<( Copy_u8Pin*4));
					}
					else if(Copy_u8Pin <=15)
					{
						Copy_u8Pin = Copy_u8Pin - 8;
						GPIOB_CRH &= ~((0b1111)<<( Copy_u8Pin*4));
						GPIOB_CRH |=  ((Copy_u8Mode)<<( Copy_u8Pin*4));
					}
					break;
		case PORTC :
					if(Copy_u8Pin <=7)
					{
						GPIOC_CRL &= ~((0b1111)<<( Copy_u8Pin*4));
						GPIOC_CRL |=  ((Copy_u8Mode)<<( Copy_u8Pin*4));
					}
					else if(Copy_u8Pin <=15)
					{
						Copy_u8Pin = Copy_u8Pin - 8;
						GPIOC_CRH &= ~((0b1111)<<( Copy_u8Pin*4));
						GPIOC_CRH |=  ((Copy_u8Mode)<<( Copy_u8Pin*4));
					}
					break;
		default :   break;			
	}
	
}

void GPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		case PORTA :
					if(Copy_u8Value == HIGH)
					{
						SET_BIT(GPIOA_ODR,Copy_u8Pin);
					}
					else if(Copy_u8Value == LOW)
					{
						CLR_BIT(GPIOA_ODR,Copy_u8Pin);
					}
					break;
		case PORTB :
					if(Copy_u8Value == HIGH)
					{
						SET_BIT(GPIOB_ODR,Copy_u8Pin);
					}
					else if(Copy_u8Value == LOW)
					{
						CLR_BIT(GPIOB_ODR,Copy_u8Pin);
					}
					break;
		case PORTC :
					if(Copy_u8Value == HIGH)
					{
						SET_BIT(GPIOC_ODR,Copy_u8Pin);
					}
					else if(Copy_u8Value == LOW)
					{
						CLR_BIT(GPIOC_ODR,Copy_u8Pin);
					}
					break;
		default :   break;	
	}	
}
u8 GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 LOC_u8Result = 0;
	switch(Copy_u8Port)
	{
		case PORTA : LOC_u8Result = GET_BIT(GPIOA_IDR,Copy_u8Pin);
					 break;
		case PORTB : LOC_u8Result = GET_BIT(GPIOB_IDR,Copy_u8Pin);
					 break;
		case PORTC : LOC_u8Result = GET_BIT(GPIOC_IDR,Copy_u8Pin);
					 break;
		default :    break;			 
	}
	return LOC_u8Result ;	
}

void GPIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Position, u8 Copy_u8Mode)
{
	switch(Copy_u8Port)
	{
		case PORTA :
					if (Copy_u8Position == LOW)
					{
						GPIOA_CRL =  (0x11111111 * Copy_u8Mode);
					}
					else if(Copy_u8Position == HIGH)
					{
						GPIOA_CRH =  (0x11111111 * Copy_u8Mode);
					}
					break;
		case PORTB :
					if (Copy_u8Position == LOW)
					{
						GPIOB_CRL =  (0x11111111 * Copy_u8Mode);
					}
					else if(Copy_u8Position == HIGH)
					{
						GPIOB_CRH =  (0x11111111 * Copy_u8Mode);
					}
					break;
		case PORTC :
					if (Copy_u8Position == LOW)
					{
						GPIOC_CRL =  (0x11111111 * Copy_u8Mode);
					}
					else if(Copy_u8Position == HIGH)
					{
						GPIOC_CRH =  (0x11111111 * Copy_u8Mode);
					}
					break;
		
	}	
}

void GPIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Position, u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		case PORTA :
					if(Copy_u8Position == LOW )
					{
						GPIOA_ODR = (GPIOA_ODR & 0xFF00) | Copy_u8Value ;		
					}
					else if (Copy_u8Position == HIGH)
					{
						GPIOA_ODR = (GPIOA_ODR & 0x00FF) | (Copy_u8Value<<8) ;
					}		
					break;
		case PORTB :
					if(Copy_u8Position == LOW )
					{
						GPIOB_ODR = (GPIOB_ODR & 0xFF00) | Copy_u8Value ;		
					}
					else if (Copy_u8Position == HIGH)
					{
						GPIOB_ODR = (GPIOB_ODR & 0x00FF) | (Copy_u8Value<<8) ;
					}		
					break;
		case PORTC :
					if(Copy_u8Position == LOW )
					{
						GPIOC_ODR = (GPIOC_ODR & 0xFF00) | Copy_u8Value ;		
					}
					else if (Copy_u8Position == HIGH)
					{
						GPIOC_ODR = (GPIOC_ODR & 0x00FF) | (Copy_u8Value<<8) ;
					}		
					break;
	}
}

/*void GPIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Position, u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		case PORTA :
					if(Copy_u8Position == LOW )
					{
						if(Copy_u8Value == HIGH)
						{
							GPIOA_BSRR = HIGH_PORTL;
						}
						else if(Copy_u8Value == LOW)
						{
							GPIOA_BRR = HIGH_PORTL; 
						}		
					}
					else if (Copy_u8Position == HIGH)
					{
						if(Copy_u8Value == HIGH)
						{
							GPIOA_BSRR = HIGH_PORTH;
						}
						else if(Copy_u8Value == LOW)
						{
							GPIOA_BRR = HIGH_PORTH; 
						}	
					}		
					break;
		case PORTB :
					if(Copy_u8Position == LOW )
					{
						if(Copy_u8Value == HIGH)
						{
							GPIOB_BSRR = HIGH_PORTL;
						}
						else if(Copy_u8Value == LOW)
						{
							GPIOB_BRR = HIGH_PORTL; 
						}		
					}
					else if (Copy_u8Position == HIGH)
					{
						if(Copy_u8Value == HIGH)
						{
							GPIOB_BSRR = HIGH_PORTH;
						}
						else if(Copy_u8Value == LOW)
						{
							GPIOB_BRR = HIGH_PORTH; 
						}	
					}		
					break;
		case PORTC :
					if(Copy_u8Position == LOW )
					{
						if(Copy_u8Value == HIGH)
						{
							GPIOC_BSRR = HIGH_PORTL;
						}
						else if(Copy_u8Value == LOW)
						{
							GPIOC_BRR = HIGH_PORTL; 
						}		
					}
					else if (Copy_u8Position == HIGH)
					{
						if(Copy_u8Value == HIGH)
						{
							GPIOC_BSRR = HIGH_PORTH;
						}
						else if(Copy_u8Value == LOW)
						{
							GPIOC_BRR = HIGH_PORTH; 
						}	
					}		
					break;
	}
}*/