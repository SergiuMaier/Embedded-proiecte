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

volatile uint16_t contor, contor_led_on, secunde, minute; //incrementare secunde si minute
char ch_sec[10], ch_min[10]; //folosite pentru conversia in char a sec si min
volatile uint8_t flag_timer; //activat atunci cand are loc intreruperea de timer
volatile uint8_t flag_led_on, flag_led_off; //flag-uri utilizate pt a trimite comenzi catre slave la un interval de timp prestabilit

void interrupt_init();
void init_timer();  
void init_devices();  
void incrementare_minute(); 

ISR(TIMER0_COMPA_vect);

#endif /* MAIN_FUNC_H_ */