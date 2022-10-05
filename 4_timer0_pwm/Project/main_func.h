/*
 * main_func.h
 *
 * Created: 8/31/2022 9:14:46 AM
 *  Author: Sergiu Maier
 */ 

#ifndef MAIN_FUNC_H_
	#define MAIN_FUNC_H_

#include "main_defines.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void pinSet(volatile uint8_t *port, uint8_t pin);

void pinReset(volatile uint8_t *port, uint8_t pin);

void led_on();

ISR(TIMER0_COMPA_vect);

ISR(INT0_vect);

ISR(INT1_vect);

#endif /* MAIN_FUNC_H_ */