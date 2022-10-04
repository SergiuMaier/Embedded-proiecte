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

volatile uint16_t contor, secunde, minute;
char ch_sec[100], ch_min[100];
uint8_t flag_timer;

void timer_init();

void init_devices();

void afisare_timp();

void introducere_mesaj();

ISR(TIMER0_COMPA_vect);

#endif /* MAIN_FUNC_H_ */