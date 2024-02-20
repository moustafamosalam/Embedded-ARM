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
	if(Data[38] == '3')
	{
		Data[38] = Data[38] - 48;
	}
	else
	{
		Array2Integer(Data);
		Copy_u8RcvData[0] = Data[76];
	}

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
	s8 NumOfTimes=0;

	for(u8 i=38; i<78; i++ )
	{
		if( (Copy_u8Array[i]>47) && (Copy_u8Array[i]<58) )
		{
			Copy_u8Array[i] = Copy_u8Array[i] - 48;
		}
	}

	if(Copy_u8Array[77] == 32)
	{
		return ;
	}
	else
	{
		NumOfTimes = ( (Copy_u8Array[76] * 10) + Copy_u8Array[77] );
		Copy_u8Array[76] = NumOfTimes;
	}
}
