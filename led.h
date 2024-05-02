/*
 * led.h
 *
 * Created: 02.05.2024 23:20:17
 *  Author: dubinkin.ru
 */ 

#ifndef LED_H_
#define LED_H_

#include <avr/io.h>

#define LED_OUTPUT	0

void init_led(void);
void handler_led(void);
void enable_led(void);
void blink_led(uint16_t delay);
void disable_led(void);

#endif /* LED_H_ */