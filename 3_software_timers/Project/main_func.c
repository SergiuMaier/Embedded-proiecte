/*
 * main_func.c
 *
 * Created: 9/01/2022 10:14:32 AM
 *  Author: Sergiu Maier
 */ 

#include "main_func.h"
#include "main_defines.h"
#include "timer0_func_def.h"

int sys_tick = 0;		//contor pentru generarea secundelor
int contor_on = 0;		//contor pentru masurarea duratei de timp in care LED-urile sunt aprinse
int counter = 0;		//contor pt sys_ticks

struct timer{
	
	enum stare_timer{ pornit = 0, oprit = 1, expirat = 2 }; // eg. t1.stare_timer = pornit;
	int autoreseteaza; //1 sau 0
	int counter_initial;
	int counter_curent; //posibil in legatura cu sys_tick
	 
}timere[MAX_NR_TIMERE];

void set_pin(volatile uint8_t *port, uint8_t pin){  //modifica in toggle dupa test
	
	*port |=  1 << pin;
}

void aprinde_led(volatile uint8_t *port, uint8_t pin, void(*fct_callback)(void)){  //netestata, dar sintaxa e ok
	
	return fct_callback(*port, pin);
}

ISR(TIMER0_COMPA_vect){  //pt caz general
	
	cli();
	
	sys_tick++;
	
	if(sys_tick >= (1/GENERARE_INTRERUPERE)){ // 1 sec
		counter++; //1 sec
		//sys_tick = 0; //idk
	}
	
	sei();
}
