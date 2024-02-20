/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#define NVIC_BASE_ADD	0xE000E100
#define	SCB_BASE_ADD	0xE000ED00 

#define NVIC_ISER0		*((u32*)(NVIC_BASE_ADD + 0x000)) 		  /* Enable External Interrupts From 0 to 31   	  */
#define NVIC_ISER1		*((u32*)(NVIC_BASE_ADD + 0x004)) 		  /* Enable External Interrupts From 32 to 63  	  */
																  
#define NVIC_ICER0		*((u32*)(NVIC_BASE_ADD + 0x080)) 		  /* Disable External Interrupts From 0 to 31  	  */
#define NVIC_ICER1		*((u32*)(NVIC_BASE_ADD + 0x084)) 		  /* Disable External Interrupts From 32 to 63 	  */
																  
#define NVIC_ISPR0		*((u32*)(NVIC_BASE_ADD + 0x100)) 		  /* Set Pending Flag from 0 to 31 			      */
#define NVIC_ISPR1		*((u32*)(NVIC_BASE_ADD + 0x104)) 		  /* Set Pending Flag From 32 to 63 			  */

#define NVIC_ICPR0		*((u32*)(NVIC_BASE_ADD + 0x180)) 		  /* Clear Pending Flag From 32 to 63 		  	  */
#define NVIC_ICPR1		*((u32*)(NVIC_BASE_ADD + 0x184)) 		  /* Clear Pending Flag From 32 to 63 		 	  */

#define NVIC_IABR0		*((volatile u32*)(NVIC_BASE_ADD + 0x200)) /* Check Active Flag From 0 to 31 			  */
#define NVIC_IABR1		*((volatile u32*)(NVIC_BASE_ADD + 0x204)) /* Check Active Flag From 32 to 59 		 	  */

#define NVIC_IPR		((u8*)(NVIC_BASE_ADD + 0x300))			  /* Priority Register							  */

#define	SCB_AIRCR		*((u32*)(SCB_BASE_ADD + 0x0C))			  /* Controls the Priority of the Interrupts	  */

#endif