#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "USART1_interface.h"
#include "FPEC_interface.h"

u8 Local_u8Check = 0;
u8 u8DataArray[50];
u8 u8Temp = 1;
u8 Local_u8Counter = 0;

void Parser_voidParseRecord(u8* Copy_u8BufData);

typedef void (*Function_t)(void);
Function_t addr_to_call = 0;

void func (void)
{
	#define SCB_VTOR	*((volatile u32*)0xE000ED08)
	
	SCB_VTOR = 0x08001800;
	
	addr_to_call = *(Function_t*)(0x08001804);
	addr_to_call();
}

int main(void)
{	
	RCC_voidInitSystemClock();
	RCC_voidEnableClock(RCC_APB2, 2); 		//PORTA
	RCC_voidEnableClock(RCC_APB2, 14 );		//USART1
	RCC_voidEnableClock(RCC_AHB, 4);		//FPEC
	
	GPIO_voidSetPinDirection(PORTA, PIN9, OUTPUT_2MHZ_AFPP);
	GPIO_voidSetPinDirection(PORTA, PIN10, INPUT_FLOATING);
	
	USART1_voidInit();
	
	STK_voidInit();
	STK_voidSetInterval(8000000, func, SINGLE_INTERVAL);
	
	while(1)
	{
		Local_u8Check = USART1_voidReceive( &(u8DataArray[Local_u8Counter]) );
		
		if(Local_u8Check == 1)
		{
			STK_voidStopCounts();
			if(u8DataArray[Local_u8Counter] == '\n')
			{
				if(u8Temp == 1)
				{
					FPEC_voidEraseAppArea();
					u8Temp=0;
				}
				
				Parser_voidParseRecord(u8DataArray);
				USART1_voidSendString("ok");
				Local_u8Counter = 0;
				
			}
			else
			{
				Local_u8Counter++;
			}
			
			STK_voidSetInterval(8000000, func, SINGLE_INTERVAL);
		}
		else
		{
			
		}
	}
}
