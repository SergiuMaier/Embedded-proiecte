/*
 * main_func.h
 *
 * Created: 9/26/2022 11:12:50 AM
 *  Author: Sergiu Maier
 */ 

#ifndef MAIN_FUNC_H_
#define MAIN_FUNC_H_

#include "main_defines.h" 
#include <string.h>

/* VARIABILE */

//incrementare secunde si minute
volatile uint16_t contor, secunde, minute; 

//conversia int -> char a sec si min
char ch_sec[10], ch_min[10]; 

//activat atunci cand are loc intreruperea de timer
volatile uint8_t flag_timer; 

/* PROTOTIPURI*/

void init_timer();  
void init_devices();  
void incrementare_minute(); 
void afisare_timp();
ISR(TIMER0_COMPA_vect);

#endif /* MAIN_FUNC_H_ */