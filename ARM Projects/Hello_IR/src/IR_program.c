/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "IR_interface.h"
#include "IR_config.h"

volatile u8 Local_u8Flag = 0;
volatile u32 DataFrame[300] = {0};
volatile u8 u8Counter = 0;
volatile u32 Data=0;	       // u8 Data[106] = {0};

void (*IR_CallBack)(void);

void IR_u8TakeAction(void)
{
	u8 i;
	if( (DataFrame[0]>10000) && (DataFrame[0]<15000) )  //3000 to 10000
	{
		for(i=0;i<32;i++) //104
		{
			if( (DataFrame[i+1]>1000) && (DataFrame[i+1]<1500) ) //600 to 1000 , 1000 to 1500
			{
				CLR_BIT(Data,i); 			//Data[i] = '0';
			}
			else
			{
				SET_BIT(Data,i);			//Data[i] = '1';
			}			
		}
		IR_CallBack();
	}
	DataFrame[0]=0;
	Local_u8Flag = 0;
	u8Counter = 0;
	i=0;
} 

void IR_voidGetDataFrame(void (* Copy_u8Timer )(void))
{

	if(Local_u8Flag == 0)
	{
		STK_voidSetInterval(1000000, IR_u8TakeAction, SINGLE_INTERVAL);
		Local_u8Flag = 1;
	}
	else
	{
		DataFrame[u8Counter] = STK_voidGetElapsedTime();
		STK_voidSetInterval(1000000, IR_u8TakeAction, SINGLE_INTERVAL);
		u8Counter++;
	}
	IR_CallBack=Copy_u8Timer;

}
