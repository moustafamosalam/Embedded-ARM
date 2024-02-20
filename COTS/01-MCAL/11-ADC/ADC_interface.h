/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

void ADC_voidInit(void);
u16 ADC_u16ReadSingleConversion(u8 Copy_u8Channel);

void ADC_voidStartConversion(u8 Copy_u8Channel);
u16 ADC_voidReadContinuous(void);

#endif
