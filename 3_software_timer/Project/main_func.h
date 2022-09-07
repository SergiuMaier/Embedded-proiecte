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

typedef struct timer{
	
	uint8_t id;
	enum stare_timer{ OPRIT = 0, PORNIT = 1, EXPIRAT = 2 }stare;	//ex. timere[1].stare_timer = PORNIT;
	uint8_t autoreset;				                                 //TRUE sau FALSE = one_shot;
	uint32_t counter_initial;	                                     //timpul la care porneste timer-ul = 0s
	uint32_t perioada;		                                     //sys_tick

	void *callback_fct;
	
}stimer;

stimer timere[MAX_NR_TIMERE];

void pin_toggle_led0();

void pin_toggle_led1();

void pin_toggle_led2();

void aprinde_led(void (*callback_fct)());

struct timer creeaza_timer(uint8_t id, uint8_t var_stare,  uint8_t var_autoreset, uint32_t val_initiala, uint32_t perioada, void *pfct);

void evalueaza_timer();

void start_evaluare();

struct timer reseteaza_timer();

struct timer update_timer(uint8_t var_stare, uint8_t var_autoreset, uint32_t perioada);

//restul prot fct trebuie adaugate

ISR(TIMER0_COMPA_vect);

#endif /* MAIN_FUNC_H_ */