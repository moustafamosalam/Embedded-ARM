/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void NVIC_voidEnableInterrupt (u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <=31 )
	{
		NVIC_ISER0 = (1 << Copy_u8IntNumber);
	}	
	
		
	else if(Copy_u8IntNumber>=32 && Copy_u8IntNumber<=59)
	{
		Copy_u8IntNumber -=32;
		NVIC_ISER1 = (1 << Copy_u8IntNumber);
	}
	
	else 
	{
		/*	Return error	*/
	}
}

void NVIC_voidDisableInterrupt (u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <=31 )
	{
		NVIC_ICER0 = (1 << Copy_u8IntNumber);
	}	
	
		
	else if(Copy_u8IntNumber>=32 && Copy_u8IntNumber<=59)
	{
		Copy_u8IntNumber -=32;
		NVIC_ICER1 = (1 << Copy_u8IntNumber);
	}
	
	else 
	{
		/*	Return error	*/
	}
}


void NVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <=31 )
	{
		NVIC_ISPR0 = (1 << Copy_u8IntNumber);
	}	
	
		
	else if(Copy_u8IntNumber>=32 && Copy_u8IntNumber<=59)
	{
		Copy_u8IntNumber -=32;
		NVIC_ISPR1 = (1 << Copy_u8IntNumber);
	}
	
	else 
	{
		/*	Return error	*/
	}
}


void NVIC_voidClearPendingFlag (u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <=31 )
	{
		NVIC_ICPR0 = (1 << Copy_u8IntNumber);
	}	
	
		
	else if(Copy_u8IntNumber>=32 && Copy_u8IntNumber<=59)
	{
		Copy_u8IntNumber -=32;
		NVIC_ICPR1 = (1 << Copy_u8IntNumber);
	}
	
	else 
	{
		/*	Return error	*/
	}
}

u8 NVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8Result=0;
	if(Copy_u8IntNumber <=31 )
	{
		Local_u8Result = GET_BIT(NVIC_IABR0 , Copy_u8IntNumber);
	}	
	
		
	else if(Copy_u8IntNumber>=32 && Copy_u8IntNumber<=59)
	{
		Copy_u8IntNumber -=32;
		Local_u8Result = GET_BIT(NVIC_IABR1 , Copy_u8IntNumber);
	}
	
	else 
	{
		/*	Return error	*/
	}
	return Local_u8Result;
}


void NVIC_voidSetPriority(u8 Copy_u8IntID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority, u32 Copy_u32GP_SUB_Priority)
{
	u8 Local_u8Priority = Copy_u8SubPriority|(Copy_u8GroupPriority<<((Copy_u32GP_SUB_Priority - 0x05FA0300)/(0x100)));
	//External Peripheral
	if(Copy_u8IntID >= 0)
	{
		NVIC_IPR[Copy_u8IntID]= Local_u8Priority << 4 ;
	}	
	SCB_AIRCR = Copy_u32GP_SUB_Priority;
}
