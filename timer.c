/*
 * timer.c
 *
 * Created: 02.05.2024 22:59:24
 *  Author: dubinkin.ru
 */ 

#include "timer.h"

volatile uint32_t power_time = 0;

void init_timer(void)
{
	TCCR0B = (1 << CS01);
	TIMSK0 = (1 << TOIE0);
	TCNT0 = 118;	
}

ISR(TIM0_OVF_vect)
{
	power_time++;
	TCNT0 = 118;
}

uint32_t millis(void)
{
	return power_time;
}
