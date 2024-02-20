#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "USART_interface.h"
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
	
	SCB_VTOR = 0x08001000;
	
	addr_to_call = *(Function_t*)(0x08001004);
	addr_to_call();
}

int main(void)
{	
	RCC_voidInit();
	RCC_voidEnableClock(RCC_, ); 		//PORTA
	RCC_voidEnableClock(RCC_, );		//USART1
	RCC_voidEnableClock(RCC_, );		//FPEC
	
	GPIO_voidSetPinDirection();
	GPIO_voidSetPinDirection();
	
	USART1_voidInit();
	
	STK_voidInit();
	STK_voidSetInterval(15000000, SINGLE, func);
	
	while(1)
	{
		Local_u8Check = USART_u8Receive( &(u8DataArray[Local_u8Counter]) );
		
		if(Local_u8Check == 1)
		{
			STK_voidStopInterval();
			if(DataArray[Local_u8Counter] == '\n')
			{
				if(u8Temp == 1)
				{
					FPEC_voidEraseAppArea();
					u8Temp=0;
				}
				
				Parser_voidParseRecord();
				USART_voidTransmit("ok");
				Local_u8Counter = 0;
				
			}
			else
			{
				Local_u8Counter++;
			}
			
		STK_voidSetInterval(15000000, SINGLE, func);
		}
		else
		{
			
		}
	}
}