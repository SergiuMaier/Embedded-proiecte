/*
 * main_func.c
 *
 * Created: 9/01/2022 10:14:32 AM
 *  Author: Sergiu Maier
 */ 

#include "main_func.h"
#include "main_defines.h"
#include "timer0_func_def.h"

#include <util/delay.h>

int sys_tick = 0;		//contor pentru generarea secundelor
int counter = 0;		//contor pt sys_ticks	
int id_timer;		    //id-ul variabilei pt evaluare
int flag = 0;
int counter_curent = 0;
int counter_timp = 0;

void pin_toggle_led0(){  
	
	PORTB ^=  1 << PINB0;	
	_delay_ms(500);	//sau calculat in fct de sys_tick 
	PORTB ^=  1 << PINB0;
}

void pin_toggle_led1(){
	
	PORTB ^=  1 << PINB1;
	_delay_ms(500);
	PORTB ^=  1 << PINB1;
}

void pin_toggle_led2(){
	
	PORTB ^=  1 << PINB2;
	_delay_ms(500);
	PORTB ^=  1 << PINB2;
}

void aprinde_led(void(*fptr)()){  
	
	(*fptr)();
}

void start_evaluare(){		//redenumeste pls
	
	if(flag == 1)
	{
		flag = 0;
		evalueaza_timer();
	}
}

struct timer creeaza_timer(uint8_t id, uint8_t var_stare,  uint8_t var_autoreset, uint32_t val_initiala, uint32_t perioada, void *pfct){
	
	struct timer t;
	
	t.id = id;			               //trebuie tinuta evidenta la nr timerelor
	t.stare = var_stare;
	t.autoreset = var_autoreset;
	t.counter_initial = val_initiala;     //initial 0 si creste odata cu sys_tick
	t.perioada = perioada;			
	
	t.callback_fct = pfct;

	counter_curent = sys_tick;
		
	return t;	
}

void evalueaza_timer(){
	
	int counter_timere_utilizate = 0;
	
	for(id_timer = 0; id_timer < MAX_NR_TIMERE; id_timer++) //functioneaza corect 
	{
		if((timere[id_timer].id != 0) && (timere[id_timer].stare == PORNIT)) //timere utilizate si pornite
			counter_timere_utilizate++;
	}

	if(counter_timp == 1){
		timere[0].counter_initial++;
		timere[1].counter_initial++;
		timere[2].counter_initial++;
	}
	
	if(counter_timere_utilizate != 0) 
	{	
		for(id_timer = 0; id_timer < counter_timere_utilizate; id_timer++)
		{			
			if(timere[id_timer].counter_initial == timere[id_timer].perioada)//sys_tick)
			{	
				aprinde_led(timere[id_timer].callback_fct);
				timere[id_timer].stare = EXPIRAT;
				
				if(timere[id_timer].autoreset == TRUE) 
					timere[id_timer].stare = PORNIT;
				else
					timere[id_timer].stare = OPRIT;
					
				timere[id_timer].counter_initial = 0;
			}
		}
	} 
}

struct timer reseteaza_timer(){
	
	struct timer t;
	
	t.counter_initial = 0;
	
	return t;
}

struct timer update_timer(uint8_t var_stare, uint8_t var_autoreset, uint32_t perioada){
	
	struct timer t;
	
	t.stare = var_stare;
	t.autoreset = var_autoreset;
	t.perioada = perioada;	
	
	return t; 
}

ISR(TIMER0_COMPA_vect){ 
	
	cli();
	
	//sys_tick++;	
	flag = 1;
	counter_timp = 1;
	
	//timere[MAX_NR_TIMERE].counter_initial++;
	
	
	sei();
}
