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

void pin_toggle_led0();

void aprinde_led(void (*callback_fct)());

struct timer creeaza_timer(uint8_t var_stare,  uint8_t var_autoreset, uint8_t contor_initial, uint8_t perioada, void *pfct);

void evalueaza_timer();

//restul prot fct trebuie adaugate

ISR(TIMER0_COMPA_vect);

#endif /* MAIN_FUNC_H_ */