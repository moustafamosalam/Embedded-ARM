
/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if(Copy_u8PerId<=31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB  :  SET_BIT(RCC_AHBENR,  Copy_u8PerId);   break;
			case RCC_APB1 :  SET_BIT(RCC_APB1ENR, Copy_u8PerId);   break;
			case RCC_APB2 :  SET_BIT(RCC_APB2ENR, Copy_u8PerId);   break;
			default 	  :	 break;
		}
	}
	else
	{
		/* Return Error  */
	}
}

void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if(Copy_u8PerId<=31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB  :  CLR_BIT(RCC_AHBENR,  Copy_u8PerId);   break;
			case RCC_APB1 :  CLR_BIT(RCC_APB1ENR, Copy_u8PerId);   break;
			case RCC_APB2 :  CLR_BIT(RCC_APB2ENR, Copy_u8PerId);   break;
			default 	  :	 break;
		}
	}
	else
	{
		/* Return Error  */
	}
}

void RCC_voidInitSystemClock(void)
{
/*	RCC HSE Crystal Clock Type		*/	
	#if		RCC_CLOCK_TYPE		== 		RCC_HSE_CRYSTAL
		SET_BIT(RCC_CFGR,0);		/*	HSE Selected as System Clock		*/
		CLR_BIT(RCC_CFGR,1);
		SET_BIT(RCC_CR,16);			/*	HSE Enable with no Bypass			*/
/*	RCC HSE RC Clock Type			*/	
	#elif	RCC_CLOCK_TYPE		==		RCC_HSE_RC
		CLR_BIT(RCC_CR,16);			/*  HSE Disable							*/
		SET_BIT(RCC_CR,18);			/*  Enable Bypass						*/
		SET_BIT(RCC_CFGR,0);		/*	HSE selected as clock system		*/	
		CLR_BIT(RCC_CFGR,1);		
		SET_BIT(RCC_CR,16);			/*  HSE Enable							*/
/*	RCC HSI Clock Type				*/
	#elif	RCC_CLOCK_TYPE		==		RCC_HSI
		CLR_BIT(RCC_CFGR,0);		/*	HSI Selected as System Clock		*/
		CLR_BIT(RCC_CFGR,1);
		SET_BIT(RCC_CR,0);			/*	HSI Enable with 					*/
/*	RCC PLL Clock Type				*/
	#elif	RCC_CLOCK_TYPE		 ==		RCC_PLL
/*	PLL Selected as System Clock	*/		
		CLR_BIT(RCC_CFGR,0);
		SET_BIT(RCC_CFGR,1);
		CLR_BIT(RCC_CR,24);			/*	PLL Disable 						*/
/*	PLL Multiplication factor		*/		
		#if ( RCC_PLL_MULT >= PLL_CLOCK_MULTIPLE_BY_2 ) && ( RCC_PLL_MULT <= PLL_CLOCK_MULTIPLE_BY_16)

			RCC_CFGR &= ~( ( 0b1111 )     << 18 ) ;
			RCC_CFGR |=  ( RCC_PLL_MULT ) << 18   ;

		#elif ( RCC_PLL_MULT > PLL_CLOCK_MULTIPLE_BY_16 ) || ( RCC_PLL_MULT < PLL_CLOCK_MULTIPLE_BY_2 )
			#warning "Wrong Multiplication Factor"
		#endif
	
		#if   RCC_PLL_INPUT	 ==		RCC_PLL_IN_HSI_DIV_2
			RCC_CR 	 ==0x00000081;	/* HSI Enable with Default Trim 			*/
			CLR_BIT(RCC_CFGR,16); 	/* HSI CLOCK Input For PLL Divided by 2		*/
		#elif RCC_PLL_INPUT  ==		RCC_PLL_IN_HSE_DIV_2
			RCC_CR 	 ==0x00010000;	/* HSE Enable 								*/
			SET_BIT(RCC_CFGR,16); 	/* HSE CLOCK INPUT FOR PLL					*/
			SET_BIT(RCC_CFGR,17);	/* HSE CLOCL DIVIDED By 2					*/
		#elif RCC_PLL_INPUT  ==		RCC_PLL_IN_HSE
			SET_BIT(RCC_CFGR,16); 	/* HSE CLOCK INPUT FOR PLL					*/	
			CLR_BIT(RCC_CFGR,17);	/* HSE CLOCL NOT DIVIDED					*/
		#else 
			#error("You Selected Wrong PLL Input")
		#endif
		SET_BIT(RCC_CR,24);			/* PLL Enable 								*/
	#else
		#error("You Selected Wrong Clock Type")
	#endif	
/*	RCC Clock Security System		*/
	#if 	RCC_CLOCK_SEC_SYS	==	ENABLE
		SET_BIT(RCC_CR,19);
	#elif	RCC_CLOCK_SEC_SYS	==	DISABLE
		CLR_BIT(RCC_CR,19);	
	#endif
}

















































/*
#if	  RCC_PLL_MULT	 ==		2
			CLR_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MULT	 ==		3
			SET_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MULT	 ==		4
			CLR_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MULT	 ==		5
			SET_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MULT	 ==		6
			CLR_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MULT	 ==		7
			SET_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MULT	 ==		8
			CLR_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MULT	 ==		9
			SET_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			CLR_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MULT	 ==		10
			CLR_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MULT	 ==		11
			SET_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MULT	 ==		12
			CLR_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MULT	 ==		13
			SET_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			CLR_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MULT	 ==		14
			CLR_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MULT	 ==		15
			SET_BIT(RCC_CFGR,18);
			CLR_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
		#elif RCC_PLL_MULT	 ==		16
			SET_BIT(RCC_CFGR,18);
			SET_BIT(RCC_CFGR,19);
			SET_BIT(RCC_CFGR,20);
			SET_BIT(RCC_CFGR,21);
		#else
			#error("You Selected Wrong Multiplication Factor")
		#endif
		*/
