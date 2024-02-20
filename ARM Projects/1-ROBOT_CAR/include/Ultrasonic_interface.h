/******************************************************************************/
/*	Author : Moustafa Mosalam												  */
/*	Date   : 22 JUNE 2022													  */
/*	Version: V01															  */
/******************************************************************************/

#ifndef ULTRASONIC_INTERFACE_H
#define ULTRASONIC_INTERFACE_H

f32 Ultrasonic_u8Distance(void);

#define TRIG_PORT	PORTA
#define TRIG_PIN	PIN11
#define ECHO_PORT	PORTA
#define ECHO_PIN	PIN12

#endif
