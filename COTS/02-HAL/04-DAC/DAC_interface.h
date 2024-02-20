/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef DAC_INTERFACE_H
#define DAC_INTERFACE_H

void DAC_voidStart(void (*Copy_DAC_Func)(void));
void DAC_voidPlayVoice(u8 *Copy_u8Array, u16 Copy_u16ArraySize);

#endif