/*
 * led.c
 *
 * Created: 02.05.2024 23:19:54
 *  Author: dubinkin.ru
 */ 

#include "led.h"
#include "timer.h"

uint8_t led_blinked = 0;
uint16_t led_delay = 250;

volatile uint32_t last_time = 0;

void init_led(void)
{
	DDRB |= (1 << LED_OUTPUT);
}

void handler_led(void)
{
	if ((millis() - last_time > led_delay) && led_blinked)
	{
		last_time = millis();
		PORTB ^= (1 << LED_OUTPUT);
	}
}

void enable_led(void)
{
	led_blinked = 0;
	PORTB |= (1 << LED_OUTPUT);
}

void blink_led(uint16_t delay)
{
	led_delay = delay;
	led_blinked = 1;
}

void disable_led(void)
{
	led_blinked = 0;
	PORTB &= ~(1 << LED_OUTPUT);
}
