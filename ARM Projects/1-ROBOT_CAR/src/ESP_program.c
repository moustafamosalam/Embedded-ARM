#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "USART1_interface.h"

#include "ESP_interface.h"
#include "ESP_config.h"
#include "ESP_private.h"

u8 volatile i=0;
s8 volatile Data[200];

void USART_CallBackFunc(void)
{
	Data[i] = USART1_u8ReadDataReg();
	i++;
	USART1_voidClrAllFlags();
}

void ESP_voidInit(void)
{
	USART1_voidSetCallBack(USART_CallBackFunc);

	USART1_voidSendString((u8*)"AT+RST\r\n");
	STK_voidSetBusyWait(3000000);

	USART1_voidSendString((u8*)"ATE0\r\n");
	STK_voidSetBusyWait(3000000);
	ESP_voidClearBuffer();

	USART1_voidSendString((u8*)"AT+CWMODE=1\r\n");
	STK_voidSetBusyWait(3000000);
	
}

void ESP_voidWifiConnect(u8* Copy_u8Name, u8* Copy_u8Password)
{
	ESP_voidClearBuffer();
	USART1_voidSendString((u8*)"AT+CWJAP_CUR=\"");
	USART1_voidSendString((u8*)Copy_u8Name);
	USART1_voidSendString((u8*)"\",\"");
	USART1_voidSendString((u8*)Copy_u8Password);
	USART1_voidSendString((u8*)"\"\r\n");
	STK_voidSetBusyWait(12000000);
}

void ESP_voidServerConnect(u8* Copy_u8IP)
{
	ESP_voidClearBuffer();
	USART1_voidSendString((u8*)"AT+CIPSTART=\"TCP\",\"");
	USART1_voidSendString((u8*)Copy_u8IP);
	USART1_voidSendString((u8*)"\",80\r\n");
	STK_voidSetBusyWait(500000);
}

void ESP_voidReceiveData(u8* Copy_u8Website, u8 Copy_u8Length, s8* Copy_u8RcvData)
{
	ESP_voidClearBuffer();
	USART1_voidSendString((u8*)"AT+CIPSEND=");
	//USART1_voidSendString('43');
	USART1_voidSendString((u8*)"46\r\n");
	STK_voidSetBusyWait(30000);
	ESP_voidClearBuffer();
	
	USART1_voidSendString((u8*)"GET http://");
	USART1_voidSendString((u8*)Copy_u8Website);
	USART1_voidSendString((u8*)"/status.txt\r\n");
	STK_voidSetBusyWait(300000);
	Array2Integer(Data);
	
	Copy_u8RcvData[0] = Data[0];
	Copy_u8RcvData[1] = Data[1];
}

void ESP_voidClearBuffer ( void ){

	u8 LOC_u8Iterator1 = 0 ;
	i = 0 ;

	for( LOC_u8Iterator1 = 0 ; LOC_u8Iterator1 < 150 ; LOC_u8Iterator1++ ){

		Data[ LOC_u8Iterator1 ] = 0 ;

	}

}


void Array2Integer(s8* Copy_u8Array)
{
	u8 x_axis =0;
	u8 y_axis =0;
	for(u8 z=50;z<54;z++)
	{
		if(Copy_u8Array[z]>47 && Copy_u8Array[z]<58)
		{
			Copy_u8Array[z] = Copy_u8Array[z] - 48;
			x_axis= x_axis*10 + Copy_u8Array[z];
		}
	}

	for(u8 z=65;z<71;z++)
	{
		if(Copy_u8Array[z]>47 && Copy_u8Array[z]<58)
			{
			Copy_u8Array[z] = Copy_u8Array[z] - 48;
				y_axis= y_axis*10 + Copy_u8Array[z];
			}
	}

	if (Copy_u8Array[50]== 45)
	{
		x_axis=-x_axis;
	}

	if (Copy_u8Array[67]== 45 || Copy_u8Array[66]== 45 || Copy_u8Array[65]== 45)
	{
		y_axis=-y_axis;
	}

	ESP_voidClearBuffer();
	Copy_u8Array[0] = x_axis;
	Copy_u8Array[1] = y_axis;
}
