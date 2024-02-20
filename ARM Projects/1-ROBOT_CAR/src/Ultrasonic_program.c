#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "Ultrasonic_interface.h"

u32 TimeElapsed_1 = 0;
u32 TimeElapsed_2 = 0;
u32 Duration = 0;
volatile f32 Distance = 0;
u8 Local_u8Temp;

void func (void)
{
	Distance = 200;
	GPIO_voidSetPinValue(TRIG_PORT, ECHO_PIN, LOW);
	Local_u8Temp = 1;
}

f32 Ultrasonic_u8Distance(void)
{
		Local_u8Temp = 0;
		GPIO_voidSetPinValue(TRIG_PORT, TRIG_PIN, HIGH);
		STK_voidSetBusyWait(10);
		GPIO_voidSetPinValue(TRIG_PORT, TRIG_PIN, LOW);

		STK_voidSetInterval(20000, func, SINGLE_INTERVAL);
		while( GPIO_u8GetPinValue(ECHO_PORT, ECHO_PIN) == 0  );
		TimeElapsed_1 = STK_voidGetElapsedTime();

		while( GPIO_u8GetPinValue(ECHO_PORT, ECHO_PIN) == 1  );
		TimeElapsed_2 = STK_voidGetElapsedTime();

		if(Local_u8Temp == 0)
		{
			STK_voidStopCounts();
			Duration = TimeElapsed_2 - TimeElapsed_1;
			Distance = ( (Duration/2)*(0.034) );

		}
		return Distance;
} 
