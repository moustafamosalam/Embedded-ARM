#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "DAC_interface.h"
#include "DAC_config.h"
#include "SYSTICK_interface.h"

volatile u16 i=0; 

void DAC_voidStart(void (*Copy_DAC_Func)(void))
{
	STK_voidSetInterval(125, Copy_DAC_Func, PERIODIC_INTERVAL);
	i=0;
}

void DAC_voidPlayVoice(u8 *Copy_u8Array, u16 Copy_u16ArraySize)
{
	GPIO_voidSetPortValue(DAC_PORT, LOW, Copy_u8Array[i]);
	i++;
	if(i==Copy_u16ArraySize)
	{
		i=0;
	}
	
}	 