/*
 * main.c
 *
 *  Created on: Sep 4, 2020
 *      Author: H
 */
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Timers.h"
#include "GPIO.h"
#include "LCD.h"
int main()
{	LCD_init();
LCD_sendCommand(0x01);
uint8_t duty;
Str_TimerConfiguration_t timer={0,64,FastPWM,POLLING};
DIO_Init_PORT(PINB,Output);
Timer_Init(&timer);
Timer_Start( 0,5 );
TIMER0_void_COMM();
 TIMER0_void_OCR0(200 );
 uint8_t buffer[20];
		 duty=(TIMER0_OCR0*100/255);

		    itoa(duty,buffer,10);
		    LCD_displayString (buffer);

return 0;




	/*while(1)
	{

	}*/
}

