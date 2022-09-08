/*
 * main_func.c
 *
 * Created: 9/01/2022 10:14:32 AM
 *  Author: Sergiu Maier
 */ 
#include "main_defines.h"
#include "timer0_def.h"
#include "stimer.h"

#include <util/delay.h>

void pin_toggle_led0(){  
	
	PORTB ^=  1 << PINB0;	
	_delay_ms(200);	
	PORTB ^=  1 << PINB0;
}

void pin_toggle_led1(){
	
	PORTB ^=  1 << PINB1;
	_delay_ms(200);
	PORTB ^=  1 << PINB1;
}

void pin_toggle_led2(){
	
	PORTB ^=  1 << PINB2;
	_delay_ms(200);
	PORTB ^=  1 << PINB2;
}

void pin_toggle_led3(){
	
	PORTB ^=  1 << PINB3;
	_delay_ms(200);	
	PORTB ^=  1 << PINB3;
}

void aprinde_led(void(*fptr)()){ 
	
	(*fptr)();
}

struct timer creeaza_timer(uint8_t id, uint8_t var_stare,  uint8_t var_autoreset, uint32_t val_initiala, uint32_t perioada, void *pfct){
	
	struct timer t;
	
	t.id = id;                            //variabila pentru a tine evidenta timerelor utilizate 
	t.stare = var_stare;                  //stabilirea starii timerului (OPRIT, PORNIT, EXPIRAT)
	t.autoreset = var_autoreset;          //stabilire daca timerul este one-shot (FALSE) sau cu autoreset (TRUE)
	t.counter_initial = val_initiala;     //variabila pentru valoarea initiala de la care porneste cronometrarea 
	t.perioada = perioada;                //valoarea la care timerul expira
	t.callback_fct = pfct;                //functia care este apelata dupa expirarea timerului
		
	return t;	
}

struct timer update_timer(uint32_t var_update, uint8_t var_stare, uint8_t var_autoreset, uint32_t val_initiala, uint32_t perioada){
	
	struct timer t;

	if(sys_tick > var_update)
	{
		t.stare = var_stare;
		t.autoreset = var_autoreset;
		t.counter_initial = val_initiala;  
		t.perioada = perioada;
	}
	
	return t;
}

void evalueaza_timer(){
	
	int counter_timere_utilizate = 0;                        //contor pentru numararea timerelor create
	
	for(id_timer = 0; id_timer < MAX_NR_TIMERE; id_timer++) 
	{
		if(timere[id_timer].id != 0)                         //verificare timere utilizate in functie de id
			counter_timere_utilizate++;                      //determinare numar timere create
	}
	
	if((counter_timere_utilizate != 0) && (counter_timp == 1))  //conditie pentru a verifica daca exista timere create si are loc intreruperea
	{	
		for(id_timer = 0; id_timer <= counter_timere_utilizate; id_timer++)   
		{			
			timere[id_timer].counter_initial++;              //incrementare contor initial (= sys_tick)
			
			if((timere[id_timer].counter_initial == timere[id_timer].perioada) && (timere[id_timer].stare == PORNIT))  //verificare daca a trecut perioada & timerul creat este pornit
			{	
				aprinde_led(timere[id_timer].callback_fct);  //apelare functie dupa expirarea perioadei
				timere[id_timer].stare = EXPIRAT;            //timerul trece din pornit -> expirat dupa ce a expirat perioada
				
				if(timere[id_timer].autoreset == TRUE)       //verificare daca timerul este one shot
					timere[id_timer].stare = PORNIT;         //schimbare stare timer
				else
					timere[id_timer].stare = OPRIT;
					
				timere[id_timer].counter_initial = 0;        //resetare contor initial
			}
		}
	} 
}

struct timer reseteaza_timer(){
	
	struct timer t;
	
	t.counter_initial = 0;
	
	return t;
}

ISR(TIMER0_COMPA_vect){ 
	
	cli();
	
	sys_tick++;
	flag = 1;     
	counter_timp = 1;
	
	sei();
}
