/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/*	Copy_u32GP_SUB_Priority Can be one of these								  */
#define NVIC_4BitGroup_0BitSub	   0x05FA0300		
#define NVIC_3BitGroup_1BitSub	   0x05FA0400
#define NVIC_2BitGroup_2BitSub	   0x05FA0500
#define NVIC_1BitGroup_3BitSub	   0x05FA0600
#define NVIC_0BitGroup_4BitSub	   0x05FA0700

/*	Copy_u8IntNumber from 0 to 59											  */
void NVIC_voidEnableInterrupt  (u8 Copy_u8IntNumber);
void NVIC_voidDisableInterrupt (u8 Copy_u8IntNumber);

void NVIC_voidSetPendingFlag   (u8 Copy_u8IntNumber);
void NVIC_voidClearPendingFlag (u8 Copy_u8IntNumber);

u8 	 NVIC_u8GetActiveFlag	   (u8 Copy_u8IntNumber);

void NVIC_voidSetPriority(u8 Copy_u8IntID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority, u32 Copy_u32GP_SUB_Priority);

#endif