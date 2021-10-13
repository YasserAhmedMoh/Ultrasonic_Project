/*
 * main.c
 *
 *  Created on: Oct 12, 2021
 *      Author: yasser ahmed
 */
#include "gpio.h"
#include "icu.h"
#include "lcd.h"
#include "ultrasonic.h"
#include <avr/io.h> /* To use the SREG register */
#include <util/delay.h>
int main(){
	uint16 dis;


	LCD_init();
	Ultrasonic_init();
	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);

	while(1)
	{
		dis = (uint16)(Ultrasonic_readDistance())/(57.5);
		LCD_moveCursor(0, 1);
		LCD_displayString("Distance= ");
		if(dis>100)
		{
			LCD_intgerToString(dis);
		}
		else
		{
			LCD_intgerToString(dis);
			LCD_displayCharacter(' ');
		}
		LCD_displayString("cm");
		_delay_ms(100);


	}



}

