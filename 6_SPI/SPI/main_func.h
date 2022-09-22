/*
 * main_func.h
 *
 * Created: 9/21/2022 12:29:51 PM
 *  Author: sergiu
 */ 


#ifndef MAIN_FUNC_H_
#define MAIN_FUNC_H_

#include <avr/interrupt.h>

int contor;
int secunde;
int minute;
int ore;

void timer_init(void);

void init_devices(void);

void apelare(void);

ISR(TIMER0_COMPA_vect);

#endif /* MAIN_FUNC_H_ */