/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef RTOS_INTERFACE_H
#define RTOS_INTERFACE_H

void RTOS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u16Periodicity, u16 Copy_u16FirstDelay, void(*ptr)(void));
void RTOS_voidStart(void);

void RTOS_voidResumeTask(u8 Copy_u8ID);
void RTOS_voidSuspendTask(u8 Copy_u8ID);
void RTOS_voidKillTask(u8 Copy_u8ID);

#endif
