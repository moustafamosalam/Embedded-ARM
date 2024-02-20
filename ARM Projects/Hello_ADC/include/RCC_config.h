
/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*********************************************/
/*	CLock Type can be : RCC_HSE_CRYSTAL		 */
/*						RCC_HSE_RC			 */
/*						RCC_HSI				 */
/*						RCC_PLL				 */
/*********************************************/
#define		RCC_CLOCK_TYPE			RCC_HSE_CRYSTAL

/*********************************************/
/*	PLL Input can be : RCC_PLL_IN_HSI_DIV_2  */
/*					   RCC_PLL_IN_HSE_DIV_2  */
/*					   RCC_PLL_IN_HSE		 */
/*											 */
/*********************************************/
#define		RCC_PLL_INPUT			RCC_PLL_IN_HSE

/*********************************************/
/*                                           */
/*  ClockFactor For PLL  Maybe :   			 */
/*           1-PLL_CLOCK_MULTIPLE_BY_2  	 */
/*           2-PLL_CLOCK_MULTIPLE_BY_3  	 */
/*           3-PLL_CLOCK_MULTIPLE_BY_4  	 */
/*           4-PLL_CLOCK_MULTIPLE_BY_5  	 */
/*           5-PLL_CLOCK_MULTIPLE_BY_6  	 */
/*           6-PLL_CLOCK_MULTIPLE_BY_7  	 */
/*           7-PLL_CLOCK_MULTIPLE_BY_8  	 */
/*           8-PLL_CLOCK_MULTIPLE_BY_9  	 */
/*           9-PLL_CLOCK_MULTIPLE_BY_10 	 */
/*           10-PLL_CLOCK_MULTIPLE_BY_11	 */
/*           11-PLL_CLOCK_MULTIPLE_BY_12	 */
/*           12-PLL_CLOCK_MULTIPLE_BY_13	 */
/*           13-PLL_CLOCK_MULTIPLE_BY_14	 */
/*           14-PLL_CLOCK_MULTIPLE_BY_15	 */
/*           15-PLL_CLOCK_MULTIPLE_BY_16	 */
/*                      	                 */
/*********************************************/
#define 	RCC_PLL_MULT			PLL_CLOCK_MULTIPLE_BY_9

/*********************************************/
/*	RCC Clock Security System can be :		 */
/*			1-Enable						 */
/*			2-Disable						 */
/*											 */
/*********************************************/
#define 	RCC_CLOCK_SEC_SYS		DISABLE

#endif
