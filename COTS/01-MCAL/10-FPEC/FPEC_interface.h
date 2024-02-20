/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef FPEC_INTERFACE_H
#define FPEC_INTERFACE_H

void FPEC_voidErasePage(u8 Copy_u8PageNumber);
void FPEC_voidFlashWrite(u32 Copy_u32Address, u16* Copy_u16Data, u8 Copy_u8Length);
void FPEC_voidEraseAppArea(void);

#endif