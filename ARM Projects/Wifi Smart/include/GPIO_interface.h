/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef 	GPIO_INTERFACE_H
#define 	GPIO_INTERFACE_H
/*		u8 Copy_u8PORT can be one of these 		*/
#define	PORTA				0
#define	PORTB				1
#define	PORTC				2
/*		u8 Copy_u8Pin can be one of these 		*/
#define PIN0				0		
#define PIN1				1
#define PIN2				2
#define PIN3				3
#define PIN4				4
#define PIN5				5
#define PIN6				6
#define PIN7				7
#define PIN8				8
#define PIN9				9
#define PIN10				10
#define PIN11				11
#define PIN12				12
#define PIN13				13
#define PIN14				14
#define PIN15				15
/*		u8 Copy_u8Value can be one of these (for Pin)		*/
#define	LOW					0
#define	HIGH				1
/*		u8 Copy_u8Value can be one of these (for Port)		*/
#define HIGH_PORTL			0x00FF
#define	HIGH_PORTH			0xFF00
/*		u8 Copy_u8Mode can be one of these (2MHZ)	*/
#define	OUTPUT_2MHZ_PP		0b0010
#define	OUTPUT_2MHZ_OD		0b0110
#define	OUTPUT_2MHZ_AFPP	0b1010
#define	OUTPUT_2MHZ_AFOD	0b1110
/*		u8 Copy_u8Mode can be one of these	(10MHZ)	*/
#define	OUTPUT_10MHZ_PP		0b0001
#define	OUTPUT_10MHZ_OD		0b0101
#define	OUTPUT_10MHZ_AFPP	0b1001
#define	OUTPUT_10MHZ_AFOD	0b1101
/*		u8 Copy_u8Mode can be one of these	(50MHZ)	*/
#define	OUTPUT_50MHZ_PP		0b0011
#define	OUTPUT_50MHZ_OD		0b0111
#define	OUTPUT_50MHZ_AFPP	0b1011
#define	OUTPUT_50MHZ_AFOD	0b1111
/*		u8 Copy_u8Mode can be one of these (INPUT)	*/
#define	INPUT_FLOATING		0b0100
#define	INPUT_ANALOG		0b0000
#define	INPUT_PULLUP_DOWN	0b1000

void GPIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);
void GPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

u8 GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);

void GPIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Position, u8 Copy_u8Mode);
void GPIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Position, u8 Copy_u8Value);

#endif
