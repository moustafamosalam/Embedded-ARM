/*
 * main.c
 *
 *  Created on: Sep 28, 2022
 *      Author: moust
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "SYSTICK_interface.h"

#include "Timer2_interface.h"
#include "USART1_interface.h"

#include "ESP_interface.h"

struct Configs
{

	u16 StartOn  ;
	u16 StartOff ;
	u16 PwmOn    ;
	u16 PwmOff_0 ;
	u16 PwmOff_1 ;
	u16 Last     ;
	u8  FullPwmVal;
	u8  PwmVal    ;

};

struct Configs Samsung_Config = {4500, 4500, 615, 500, 1600, 615, 20,   10};
struct Configs LG_Config 	  = {9000, 4500, 562, 562, 1687, 610, 204, 102};
struct Configs Ambient_Config = {9000, 4500, 585, 525, 1650, 580, 18,    9};

void Remote_voidCommands(struct Configs Remote_Configs);
void AC_voidControl(u8* AC_Array);

/*************************** Commands to be used*******************************************************/

u8 AC_ON[104] =  {0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,1,1,1,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,
				  0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,1};

u8 AC_OFF[104] = {0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,1,1,1,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,
				  0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1};

u8 AC_UP[104] =  {0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,1,1,1,0,0,1,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,
				  0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1};

u8 AC_DOWN[104]= {0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,1,1,1,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,
				  0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1};


/******************************************************************************************************/

extern s8 Data[200];

void main(void)
{
	RCC_voidInitSystemClock();
	RCC_voidEnableClock(RCC_APB2, 2);
/* Enable Peripheral 0 on APB1 bus (TIM2)	*/
	RCC_voidEnableClock(RCC_APB1, 0);
/* Enable Peripheral 14 on APB1 bus (USART1)					*/
	RCC_voidEnableClock(RCC_APB2, 14);

/* TX Pin Output & RX Pin Input									*/
	GPIO_voidSetPinDirection(PORTA, PIN9, OUTPUT_2MHZ_AFPP);
	GPIO_voidSetPinDirection(PORTA, PIN10, INPUT_FLOATING);
	GPIO_voidSetPinDirection(PORTA, PIN0, OUTPUT_2MHZ_PP);
/* PWM Pin Output												*/
	GPIO_voidSetPinDirection(PORTA, PIN1, OUTPUT_2MHZ_AFPP);

/* Set USARt1 Interrupt Priority & Enable USART1 Interrupt		*/
	NVIC_voidSetPriority(37, 1, 0, NVIC_4BitGroup_0BitSub);
	NVIC_voidEnableInterrupt(37);
/* Initialize Timers and USART									*/
	STK_voidInit();
	TIMER2_voidInit();
	USART1_voidInit();

	TIMER2_voidPWM(1, 0, CHANNEL2);
	TIMER2_voidPWMCounterEnable();

	ESP_voidInit();
	ESP_voidWifiConnect((u8*)"Hello", (u8*)"qzwxecrvtbynum");

	s8 Array[3] = {0};
	s8 local_s8Comp = 1;

	/*				START BIT										*/


	while(1)
	{
		ESP_voidServerConnect((u8*)"185.176.43.104");
		ESP_voidReceiveData((u8*)"mosalam.atwebpages.com", 46, Array);
		GPIO_voidSetPinValue(PORTA, PIN0, HIGH);

/*			Checks if Website is Refreshed							*/
		if( Data[38] == 3 )
		{
			local_s8Comp =1;
		}
/*			To take actions according to the number of clicks		*/
		else if(local_s8Comp <= Array[0])
		{
/*			Checks the Device to Be controlled						*/
			switch(Data[73])
			{
				case 4 : TIMER2_voidPWM(LG_Config.FullPwmVal, 0, CHANNEL2);
						 local_s8Comp++;
						 Remote_voidCommands(LG_Config);
						 break;

				case 5 : TIMER2_voidPWM(Samsung_Config.FullPwmVal, 0, CHANNEL2);
						 local_s8Comp++;
						 Remote_voidCommands(Samsung_Config);
						 break;

				case 6 : TIMER2_voidPWM(Ambient_Config.FullPwmVal, 0, CHANNEL2);
						 local_s8Comp++;
						 Remote_voidCommands(Ambient_Config);
						 break;

				case 7 :   TIMER2_voidPWM(82, 0, CHANNEL2);
						 local_s8Comp++;
						 switch(Data[39])
						 {
							case 1 : AC_voidControl(AC_ON );
									break;
							case 2 : AC_voidControl(AC_OFF );
									break;
							case 3 : AC_voidControl(AC_UP );
									break;
							case 4 : AC_voidControl(AC_DOWN );
									break;
 						}
			}

		}



	}
}



void Remote_voidCommands(struct Configs Remote_Configs)
{
	TIMER2_voidSetCCRVal(Remote_Configs.PwmVal,CHANNEL2);
	STK_voidSetBusyWait(Remote_Configs.StartOn);
	TIMER2_voidSetCCRVal(0,CHANNEL2);
	STK_voidSetBusyWait(Remote_Configs.StartOff);

	for(u8 i=0; i<32; i++)
	{
		if(Data[i+39] == 0)
		{
			TIMER2_voidSetCCRVal(Remote_Configs.PwmVal, CHANNEL2);
			STK_voidSetBusyWait(Remote_Configs.PwmOn);
			TIMER2_voidSetCCRVal(0, CHANNEL2);
			STK_voidSetBusyWait(Remote_Configs.PwmOff_0);
		}
		else
		{
			TIMER2_voidSetCCRVal(Remote_Configs.PwmVal, CHANNEL2);
			STK_voidSetBusyWait(Remote_Configs.PwmOn);
			TIMER2_voidSetCCRVal(0, CHANNEL2);
			STK_voidSetBusyWait(Remote_Configs.PwmOff_1);
		}
	}

	TIMER2_voidSetCCRVal(Remote_Configs.PwmVal, CHANNEL2);
	STK_voidSetBusyWait(Remote_Configs.Last);
	TIMER2_voidSetCCRVal(0, CHANNEL2);
	STK_voidSetBusyWait(20000);
}


void AC_voidControl(u8* AC_Array)
{
	TIMER2_voidSetCCRVal(41,CHANNEL2);
	STK_voidSetBusyWait(3854);
	TIMER2_voidSetCCRVal(0,CHANNEL2);
	STK_voidSetBusyWait(1800);

	for(u8 i=0; i<104; i++)
	{
		if(AC_Array[i] == 0)
		{
			TIMER2_voidSetCCRVal(41, CHANNEL2);
			STK_voidSetBusyWait(574);
			TIMER2_voidSetCCRVal(0, CHANNEL2);
			STK_voidSetBusyWait(380);
		}
		else
		{
			TIMER2_voidSetCCRVal(41, CHANNEL2);
			STK_voidSetBusyWait(574);
			TIMER2_voidSetCCRVal(0, CHANNEL2);
			STK_voidSetBusyWait(1300);
		}
	}

	TIMER2_voidSetCCRVal(41, CHANNEL2);
	STK_voidSetBusyWait(410);
	TIMER2_voidSetCCRVal(0, CHANNEL2);
	STK_voidSetBusyWait(20000);
}
