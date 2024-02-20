/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

void EXTI_voidInit(u8 Copy_u8Line, u8 Copy_u8Mode);
void EXTI_voidEnableEXTI(u8 Copy_u8Line);
void EXTI_voidDisableEXTI(u8 Copy_u8Line);
void EXTI_voidSwTrigger(u8 Copy_u8Line);
void EXTI0_voidSetCallBack( void (*ptr) (void) );
void EXTI1_voidSetCallBack( void (*ptr) (void) );
void EXTI2_voidSetCallBack( void (*ptr) (void) );


#define 		LINE0				0
#define 		LINE1				1
#define 		LINE2				2
#define 		LINE3				3
#define 		LINE4				4
#define 		LINE5				5
#define 		LINE6				6
#define 		LINE7				7
#define 		LINE8				8
#define 		LINE9				9
#define 		LINE10				10
#define 		LINE11				11
#define 		LINE12				12
#define 		LINE13				13
#define 		LINE14				14
#define 		LINE15				15

#define 		RISING_EDGE			0
#define			FALLING_EDGE		1
#define			ON_CHANGE			2

#endif
