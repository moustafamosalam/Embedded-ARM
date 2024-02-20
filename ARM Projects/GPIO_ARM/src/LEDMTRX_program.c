/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"
#include "LEDMTRX_interface.h"


void LEDMTRX_voidInit		(void)
{
	GPIO_voidSetPinDirection(LEDMTRX_ROW0_PIN,OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMTRX_ROW1_PIN,OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMTRX_ROW2_PIN,OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMTRX_ROW3_PIN,OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMTRX_ROW4_PIN,OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMTRX_ROW5_PIN,OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMTRX_ROW6_PIN,OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMTRX_ROW7_PIN,OUTPUT_2MHZ_PP);
	
	GPIO_voidSetPinDirection(LEDMTRX_COL0_PIN,OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMTRX_COL1_PIN,OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMTRX_COL2_PIN,OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMTRX_COL3_PIN,OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMTRX_COL4_PIN,OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMTRX_COL5_PIN,OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMTRX_COL6_PIN,OUTPUT_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMTRX_COL7_PIN,OUTPUT_2MHZ_PP);
}

void LEDMTRX_voidDisplay	(u8 *Copy_u8Data)
{
	/*	Enable Column 0						*/
	LEDMTRX_voidDisableCols(void); 							//Disable All Columns
	LEDMTRX_voidSetRowValues(Copy_u8Data[0]);				//Set Rows Values
	GPIO_voidSetPinValue(LEDMTRX_COL0_PIN,HIGH); 		    //Enable Column 0

	/*	Enable Column 1						*/
	LEDMTRX_voidDisableCols(void); 							//Disable All Columns
	LEDMTRX_voidSetRowValues(Copy_u8Data[1]);				//Set Rows Values
	GPIO_voidSetPinValue(LEDMTRX_COL1_PIN,HIGH); 		    //Enable Column 1
	
	/*	Enable Column 2						*/
	LEDMTRX_voidDisableCols(void); 							//Disable All Columns
	LEDMTRX_voidSetRowValues(Copy_u8Data[2]);				//Set Rows Values
	GPIO_voidSetPinValue(LEDMTRX_COL2_PIN,HIGH); 		    //Enable Column 2
	
	/*	Enable Column 3						*/
	LEDMTRX_voidDisableCols(void); 							//Disable All Columns
	LEDMTRX_voidSetRowValues(Copy_u8Data[3]);				//Set Rows Values
	GPIO_voidSetPinValue(LEDMTRX_COL3_PIN,HIGH); 		    //Enable Column 3
	
	/*	Enable Column 4						*/
	LEDMTRX_voidDisableCols(void); 							//Disable All Columns
	LEDMTRX_voidSetRowValues(Copy_u8Data[4]);				//Set Rows Values
	GPIO_voidSetPinValue(LEDMTRX_COL4_PIN,HIGH); 		    //Enable Column 4
	
	/*	Enable Column 5						*/
	LEDMTRX_voidDisableCols(void); 							//Disable All Columns
	LEDMTRX_voidSetRowValues(Copy_u8Data[5]);				//Set Rows Values
	GPIO_voidSetPinValue(LEDMTRX_COL5_PIN,HIGH); 		    //Enable Column 5
	
	/*	Enable Column 6						*/
	LEDMTRX_voidDisableCols(void); 							//Disable All Columns
	LEDMTRX_voidSetRowValues(Copy_u8Data[6]);				//Set Rows Values
	GPIO_voidSetPinValue(LEDMTRX_COL6_PIN,HIGH); 		    //Enable Column 6
	
	/*	Enable Column 7						*/
	LEDMTRX_voidDisableCols(void); 							//Disable All Columns
	LEDMTRX_voidSetRowValues(Copy_u8Data[7]);				//Set Rows Values
	GPIO_voidSetPinValue(LEDMTRX_COL7_PIN,HIGH); 		    //Enable Column 7
}

static void LEDMTRX_voidDisableCols(void)
{
	GPIO_voidSetPinValue(LEDMTRX_COL0_PIN,LOW);
	GPIO_voidSetPinValue(LEDMTRX_COL1_PIN,LOW);
	GPIO_voidSetPinValue(LEDMTRX_COL2_PIN,LOW);
	GPIO_voidSetPinValue(LEDMTRX_COL3_PIN,LOW);
	GPIO_voidSetPinValue(LEDMTRX_COL4_PIN,LOW);
	GPIO_voidSetPinValue(LEDMTRX_COL5_PIN,LOW);
	GPIO_voidSetPinValue(LEDMTRX_COL6_PIN,LOW);
	GPIO_voidSetPinValue(LEDMTRX_COL7_PIN,LOW);
}

static void LEDMTRX_voidSetRowValues (u8 * Copy_u8Value)
{
	u8 Local_u8Temp = 0;
	
	Local_u8Temp = GET_BIT(Copy_u8Value,0);
	GPIO_voidSetPinValue(LEDMTRX_ROW0_PIN,Local_u8Temp);
	
	Local_u8Temp = GET_BIT(Copy_u8Value,1);
	GPIO_voidSetPinValue(LEDMTRX_ROW1_PIN,Local_u8Temp);
	
	Local_u8Temp = GET_BIT(Copy_u8Value,2);
	GPIO_voidSetPinValue(LEDMTRX_ROW2_PIN,Local_u8Temp);
	
	Local_u8Temp = GET_BIT(Copy_u8Value,3);
	GPIO_voidSetPinValue(LEDMTRX_ROW3_PIN,Local_u8Temp);
	
	Local_u8Temp = GET_BIT(Copy_u8Value,4);
	GPIO_voidSetPinValue(LEDMTRX_ROW4_PIN,Local_u8Temp);
	
	Local_u8Temp = GET_BIT(Copy_u8Value,5);
	GPIO_voidSetPinValue(LEDMTRX_ROW0_PIN,Local_u8Temp);
	
	Local_u8Temp = GET_BIT(Copy_u8Value,6);
	GPIO_voidSetPinValue(LEDMTRX_ROW6_PIN,Local_u8Temp);
	
	Local_u8Temp = GET_BIT(Copy_u8Value,7);
	GPIO_voidSetPinValue(LEDMTRX_ROW7_PIN,Local_u8Temp);
	
	Local_u8Temp = GET_BIT(Copy_u8Value,8);
	GPIO_voidSetPinValue(LEDMTRX_ROW8_PIN,Local_u8Temp);
	
}