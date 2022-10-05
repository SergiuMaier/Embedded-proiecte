/*
 * timer0_defines.h
 *
 * Created: 9/1/2022 12:08:33 PM
 *  Author: Sergiu Maier
 */ 

#ifndef TIMER0_DEFINES_H_
	#define TIMER0_DEFINES_H_
	
#include "main_defines.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#define STOP_TIMER0 0b11111000

#define GENERARE_INTRERUPERE 0.001 //generarea unei intreruperi la fiecare x secunde
#define VALOARE_TOP_REGISTRU 256   //valoarea de top a registrului TCNT0 (pt ca folosesc timer pe 8 biti)

void start_timer0();

void stop_timer0();

#endif /* TIMER0_DEFINES_H_ */

