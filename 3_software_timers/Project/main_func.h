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

void set_pin(volatile uint8_t *port, uint8_t pin);

void aprinde_led(volatile uint8_t *port, uint8_t pin, void(*fct_callback)(uint8_t, uint8_t));

//restul functiilor trebuie adaugate

ISR(TIMER0_COMPA_vect);

#endif /* MAIN_FUNC_H_ */