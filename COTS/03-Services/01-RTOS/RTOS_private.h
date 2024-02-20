/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef RTOS_PRIVATE_H
#define RTOS_PRIVATE_H

typedef struct
{
	u16 Periodicity;
	void (*Fptr) (void);
	u16  FirstDelay;
	u8  State;
	
}Task;

#define 	TASK_SUSPEND			0
#define 	TASK_READY				1

void RTOS_voidScheduler(void);

#endif