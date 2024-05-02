/*
 * main.h
 *
 * Created: 02.05.2024 22:09:04
 *  Author: dubinkin.ru
 */ 

#ifndef MAIN_H_
#define MAIN_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define INPUT 1
#define OUTPUT 4

#define enable_sbs()	(PORTB |= (1 << OUTPUT))
#define disable_sbs()	(PORTB &= ~(1 << OUTPUT))

#endif /* MAIN_H_ */