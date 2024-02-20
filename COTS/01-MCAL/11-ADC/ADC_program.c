#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


void ADC_voidInit(void)
{
	//Enable ADC
	SET_BIT(ADC->CR2, 0);
	
	//Right Alignment
	CLR_BIT(ADC->CR2, 11);
	
	#if 	ADC_MODE == SINGLE
		//Single Conversion
		CLR_BIT(ADC->CR2, 1);
	#elif	ADC_MODE == CONTINUOUS
		//Continuous Mode
		SET_BIT(ADC->CR2, 1);
	#endif
	
	//Number of Conversion = 1
	CLR_BIT(ADC->SQR1, 20);
	CLR_BIT(ADC->SQR1, 21);
	CLR_BIT(ADC->SQR1, 22);
	CLR_BIT(ADC->SQR1, 23);

	//External event (start bit)
	SET_BIT(ADC->CR2, 20);
	SET_BIT(ADC->CR2, 17);
	SET_BIT(ADC->CR2, 18);
	SET_BIT(ADC->CR2, 19);

	//Enable Calibration
	SET_BIT(ADC->CR2, 2);
}

u32 ADC_u16ReadSingleConversion(u8 Copy_u8Channel)
{
	volatile u32 Data = 0;
	
	//Channel 5 
	ADC->SQR3 = Copy_u8Channel;
	
	//Start Conversion
	SET_BIT(ADC->CR2, 22);

	CLR_BIT(ADC->SR, 1);	//Clear Flag
	//Wait Till End of Conversion
	while(( GET_BIT(ADC->SR, 1) ) == 0); 
	
	//Read Data 
	Data = ADC->DR;	
	
	return Data;
}

void ADC_voidStartConversion(u8 Copy_u8Channel)
{
	ADC->SQR3 = Copy_u8Channel;
	SET_BIT(ADC->CR2, 22);	
}

u16 ADC_voidReadContinuous(void)
{
	u16 Data =0;
	Data = ADC->DR;
	return Data;
}
