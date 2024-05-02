/*
 * main.c
 *
 * Created: 02.05.2024 22:09:04
 *  Author: dubinkin.ru
 */ 

#include "main.h"
#include "timer.h"
#include "led.h"

uint8_t input_trigger = 0;
uint32_t sbs_start_time = 0;

void init(void)
{
	init_timer();
	init_led();
	
	// configuration I/O ports
	DDRB |= (1 << OUTPUT) | (0 << INPUT);
	
	// INT0 falling edge interrupt configuration
	MCUCR |= (1 << ISC01) | (0 << ISC00);
	GIMSK |= (1 << INT0);
	
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
		
		// SBS output switch-off delay
		if ((millis() - sbs_start_time > 500) && input_trigger)
		{
			input_trigger = 0;
			disable_sbs();
			disable_led();
		}
		
		_delay_ms(5);
	}
}

ISR(INT0_vect)
{
	if (!input_trigger)
	{
		input_trigger = 1;
		sbs_start_time = millis();
		enable_sbs();
		blink_led(100);
	}
}