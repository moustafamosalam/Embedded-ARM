/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef LEDMTRX_INTERFACE_H
#define LEDMTRX_INTERFACE_H

void LEDMTRX_voidInit			(void);
void LEDMTRX_voidDisplay		(u8 *Copy_u8Data);
void LEDMTRX_voidDisplayString	(u8 * Copy_u8String, u8 Size);
void LEDMTRX_voidSerialDisplay(u8 * Copy_u8String, u8 Size);

#endif
