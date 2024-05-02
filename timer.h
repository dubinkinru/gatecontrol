/*
 * timer.h
 *
 * Created: 02.05.2024 22:59:34
 * Author: dubinkin.ru
 */ 

#ifndef TIMER_H_
#define TIMER_H_

#include <avr/interrupt.h>

void init_timer(void);
uint32_t millis(void);

#endif /* TIMER_H_ */