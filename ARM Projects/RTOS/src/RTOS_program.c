/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "RTOS_interface.h"
#include "RTOS_private.h"
#include "RTOS_config.h"

#define NULL (void*)0

static Task TaskData[NUMBER_OF_TASKS] = { NULL };

void RTOS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u16Periodicity, u16 Copy_u16FirstDelay, void(*ptr)(void))
{
	if(TaskData[Copy_u8ID].Fptr == NULL)
	{
		TaskData[Copy_u8ID].Periodicity = Copy_u16Periodicity;
		TaskData[Copy_u8ID].FirstDelay  = Copy_u16FirstDelay;
		TaskData[Copy_u8ID].Fptr        = ptr;
		TaskData[Copy_u8ID].State		= TASK_READY;
	}

}

void RTOS_voidScheduler(void)
{
	for(u8 i=0;i<NUMBER_OF_TASKS;i++)
	{
		if((TaskData[i].Fptr != NULL) && (TaskData[i].State == TASK_READY ) )
		{
			if(TaskData[i].FirstDelay == 0)
			{
				TaskData[i].FirstDelay = TaskData[i].Periodicity - 1;
				TaskData[i].Fptr();
			}
			else
			{
				TaskData[i].FirstDelay--;
			}
		}
	}
	
}

void RTOS_voidStart(void)
{
	STK_voidInit();
	STK_voidSetInterval(1000, RTOS_voidScheduler, PERIODIC_INTERVAL);
}

void RTOS_voidResumeTask(u8 Copy_u8ID)
{
	TaskData[Copy_u8ID].State = TASK_READY ;
}
void RTOS_voidSuspendTask(u8 Copy_u8ID)
{
	TaskData[Copy_u8ID].State = TASK_SUSPEND ;
}
void RTOS_voidKillTask(u8 Copy_u8ID)
{
	TaskData[Copy_u8ID].Fptr = NULL ;
	
}
