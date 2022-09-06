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
int counter = 0;		//contor pt sys_ticks
int flag = 0;			//broken
int id_timer;		    //id-ul variabilei din timere[]
  

typedef struct timer{
	
	uint8_t id;															                                           
	enum stare_timer{ OPRIT = 0, PORNIT = 1, EXPIRAT = 2 }stare;	//ex. timere[1].stare_timer = PORNIT;							
	uint8_t autoreset;				                                 //TRUE sau FALSE = one_shot;
	uint8_t counter_initial;	                                     //timpul la care porneste timer-ul = 0s
	uint8_t counter_curent;		                                     //sys_tick
	
	void *callback_fct;			
	 
}stimer;  

stimer timere[MAX_NR_TIMERE];

void pin_toggle_led0(){  
	
	PORTB ^=  1 << PINB0;	
}

void aprinde_led(void(*callback_fct)()){  
	
	(*callback_fct)();
}

int numar_timere_create(){
	
	int counter_timere_create = 0; //numar timere create
	stimer *t = timere;
	
	for(int i = 0; i < MAX_NR_TIMERE; i++)
	{	
		if(t->id != 0)
			counter_timere_create++;
		
		t++;
	}
	
	return counter_timere_create;
}

struct timer creeaza_timer(uint8_t id_timer, uint8_t var_stare,  uint8_t var_autoreset, uint8_t val_initiala, uint8_t perioada, void *pfct){
	
	timere[id_timer].callback_fct = pfct;
	
	timere[id_timer].id = id_timer;                           //trebuie tinuta evidenta la nr timerelor
	timere[id_timer].stare = var_stare;
	timere[id_timer].autoreset = var_autoreset;
	timere[id_timer].counter_initial = val_initiala;    //initial 0 dar creste odata cu sys_tick
	timere[id_timer].counter_curent = sys_tick;			
		
	val_initiala++;
	
	if (timere[id_timer].counter_initial == perioada)
		timere[id_timer].stare = EXPIRAT;               //expirat => callback
	
	return timere[id_timer];  //de id
}

void evalueaza_timer(){
	
	void(*callback_fct)() = &pin_toggle_led0;
	pin_toggle_led0(callback_fct);
	
	//if perioada == 0 
	
	//id timer
	
	//variabila pt timer utilizat
	// => stare = expirat => apelare callback
	//vf autoreset => schimbare stare
	
	for( id_timer = 0; id_timer < MAX_NR_TIMERE; id_timer++){
		
		//contor++ pt cele utilizate si pornite
		//vf timp = perioada
	} 
	if(	timere[id_timer].stare == EXPIRAT ){ //nu de i
		//t.callback_fct(); 
		
		if( timere[id_timer].autoreset == TRUE)
			timere[id_timer].stare = PORNIT;
			//reset ceva
		else
			timere[id_timer].stare = OPRIT;
	}
}

struct timer reseteaza_timer(){
	
	//resetare valori la 0
	return timere[id_timer]; //de id timer
}

struct timer update_timer(uint8_t var_stare, uint8_t var_autoreset){
	
	//param - cei doriti pt update din struct nu timer t 
	//modificare perioada, autoreset din creeare_timer
	
	timere[id_timer].stare = var_stare;
	timere[id_timer].autoreset = var_autoreset;
	
	return timere[id_timer]; //de id timer
}

void startup(){		//redemimeste pls
	
	if(flag == 1)
	{
		flag = 0;
		evalueaza_timer();
	}
}

ISR(TIMER0_COMPA_vect){ 
	
	cli();
	
	sys_tick++;	
	flag = 1;
	//counter++;	//???
	
	sei();
}
