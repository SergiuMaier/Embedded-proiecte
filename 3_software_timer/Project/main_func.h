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
	
	uint8_t id;	                                                    //variabila pentru a tine evidenta timerelor utilizate 
	enum stare_timer{ OPRIT = 0, PORNIT = 1, EXPIRAT = 2 }stare;    //stabilirea starii timerului
	uint8_t autoreset;                                              //stabilire daca timerul este one-shot (FALSE) sau cu autoreset (TRUE)
	uint32_t counter_initial;                                       //valoarea initiala de la care porneste cronometrarea
	uint32_t perioada;                                              //valoarea la care timerul expira

	void *callback_fct;                                             //functia care este apelata dupa expirarea timerului
	
}stimer;

stimer timere[MAX_NR_TIMERE];     //array de timere

//functii pentru toggle diferiti pini
void pin_toggle_led0();

void pin_toggle_led1();

void pin_toggle_led2();

void pin_toggle_led3();

//callback function apelata dupa expirarea perioadei
void aprinde_led(void (*callback_fct)());  

//functie pentru crearea unui element din structura
struct timer creeaza_timer(uint8_t id, uint8_t var_stare,  uint8_t var_autoreset, uint32_t val_initiala, uint32_t perioada, void *pfct);

//functie pentru evaluarea starii timerului la fiecare moment de timp
void evalueaza_timer();

//apeleaza functia evaluare_timer() daca are loc intreruperea
void start_evaluare();

//functie pentru resetarea unui element la valorile initiale
struct timer reseteaza_timer();

//functie pentru actualizarea valorilor unui element deja creat
struct timer update_timer(uint8_t var_stare, uint8_t var_autoreset, uint32_t perioada);

//restul prot fct trebuie adaugate

ISR(TIMER0_COMPA_vect);

#endif /* MAIN_FUNC_H_ */