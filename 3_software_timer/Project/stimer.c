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
}

void pin_toggle_led1(){
	
	PORTB ^=  1 << PINB1;
}

void pin_toggle_led2(){
	
	PORTB ^=  1 << PINB2;
}

void pin_toggle_led3(){
	
	PORTB ^=  1 << PINB3;
}

void reset_timer_dorit(uint8_t index){
	
	timere[index].counter_initial = 0;
}

void reset_timer(){
	
	reset_timer_dorit(4);
}

void update_timer_dorit(uint8_t index){
	
	timere[index].stare = PORNIT;
	timere[index].autoreset = FALSE;
}

void update_timer(){
	
	update_timer_dorit(0);
}

void creeaza_timer(uint8_t index, uint8_t var_stare, uint8_t var_autoreset, uint32_t val_initiala, uint32_t perioada, void (*pfct)(void)){
	
	struct timer t;
	
	t.id = index;                         //variabila pentru a tine evidenta timerelor utilizate 
	t.stare = var_stare;                  //stabilirea starii timerului (OPRIT, PORNIT, EXPIRAT)
	t.autoreset = var_autoreset;          //stabilire daca timerul este one-shot (FALSE) sau cu autoreset (TRUE)
	t.counter_initial = val_initiala;     //variabila pentru valoarea initiala de la care porneste cronometrarea 
	t.perioada = perioada;                //valoarea la care timerul expira
	t.callback_fct = pfct;                //functia care este apelata dupa expirarea timerului
	
	timere[index] = t;
	
	counter_timere_create++;              //numarul timerelor create initial	
}

void evalueaza_timer(){ 
	
	if((counter_timere_create != 0) && (counter_timp == 1))  //conditie pentru a verifica daca exista timere create si are loc intreruperea
	{	
		for(index_timer = 0; index_timer <= counter_timere_create; index_timer++)   
		{		
			if(timere[index_timer].stare == PORNIT)
			{	
				timere[index_timer].counter_initial++;           //incrementare contor initial (= sys_tick)
				
				if(timere[index_timer].counter_initial == timere[index_timer].perioada)  //timer EXPIRAT
				{    
					timere[index_timer].callback_fct();
					 
					//timere[id_timer].stare = EXPIRAT;          //timerul trece din pornit -> expirat dupa ce a expirat perioada
				
					if(timere[index_timer].autoreset == TRUE)    //verificare daca timerul este one shot
						timere[index_timer].stare = PORNIT;      //schimbare stare timer
					else
						timere[index_timer].stare = OPRIT;
					
					timere[index_timer].counter_initial = 0;     //resetare contor initial	
				}
			}
		}
	} 
}

ISR(TIMER0_COMPA_vect){ 
	
	cli();
	
	sys_tick++;
	flag = 1;     
	counter_timp = 1;
	
	sei();
}
