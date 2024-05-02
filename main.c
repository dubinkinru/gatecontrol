/*
 * main.c
 *
 * Created: 02.05.2024 22:09:04
 *  Author: dubinkin.ru
 */ 

#include "main.h"
#include "timer.h"
#include "led.h"

void init(void)
{
	init_timer();
	init_led();
	
	// checking LED blinking, interval is set to 500 ms
	blink_led(500);
	
	// enable interrupts
	sei();
}

int main(void)
{
	init();
	
	while(1)
	{
		// LED indication processing
		handler_led();
	}
}