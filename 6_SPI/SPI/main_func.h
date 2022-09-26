/*
 * main_func.h
 *
 * Created: 9/26/2022 11:12:50 AM
 *  Author: Sergiu Maier
 */ 


#ifndef MAIN_FUNC_H_
#define MAIN_FUNC_H_

#include <stdlib.h>
#include <avr/interrupt.h>

volatile int contor, secunde, minute;

void timer_init();

void init_devices();

ISR(TIMER0_COMPA_vect);

#endif /* MAIN_FUNC_H_ */