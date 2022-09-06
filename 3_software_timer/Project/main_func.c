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

typedef struct timer{
	
	enum stare_timer{ OPRIT = 0, PORNIT = 1, EXPIRAT = 2 }stare; //ex. timere[1].stare_timer = PORNIT;
								
	int autoreset;				//TRUE sau FALSE = one_shot;
	int counter_initial;		//timpul la care porneste timer-ul = 0s
	int counter_curent;			//sys_tick
	
	void *callback_fct;			
	 
}stimer;  

struct timer timere[MAX_NR_TIMERE];

void pin_toggle_led0(){  
	
	PORTB ^=  1 << PINB0;	
}

void aprinde_led(void(*callback_fct)()){  
	
	(*callback_fct)();
}

struct timer creeaza_timer(uint8_t var_stare,  uint8_t var_autoreset, uint8_t contor_initial, uint8_t perioada, void *pfct){
	
	 //global
	//enum stare_timer st;
	//trebuie tinuta evidenta la nr timerelor
	timere[1].callback_fct = pfct;
	
	//t.stare = var_stare;
	//t.autoreset = var_autoreset;
	//t.counter_initial = contor_initial;	//sys_tick	//ar trebui sa fie 0 si se incrementeaza pana la expirare
	//t.counter_curent = sys_tick;			//nu stiu daca trebuie variabila asta, pare in plus daca folosesc perioada
											//sau e doar pt memorare
	
	//if (t.contor_initial == perioada)
		//expirat => callback
	
	return timere[1];  //de id
}

void evalueaza_timer(){
	
	void(*callback_fct)() = &pin_toggle_led0;
	pin_toggle_led0(callback_fct);
	
	//if perioada == 0 
	
	//id timer
	
	//variabila pt timer utilizat
	// => stare = expirat => apelare callback
	//vf autoreset => schimbare stare
	
	for(int i = 0; i < MAX_NR_TIMERE; i++){
		
		//contor++ pt cele utilizate si pornite
		//vf timp = perioada
	} 
	if(	timere[1].stare == EXPIRAT ){ //nu de i
		//t.callback_fct();
		//aprinde_led(&PORTB, PINB0, pin_toggle); 
		
		if( timere[1].autoreset == TRUE)
			timere[1].stare = PORNIT;
			//reset perioada sau contor.initial
		else
			timere[1].stare = OPRIT;
	}
}

struct timer reseteaza_timer(){
	
	//resetare valori la 0
	return timere[1]; //de id timer
}

struct timer update_timer(uint8_t var_stare, uint8_t var_autoreset){
	
	//param - cei doriti pt update din struct nu timer t 
	//modificare perioada, autoreset din creeare_timer
	
	timere[1].stare = var_stare;
	timere[1].autoreset = var_autoreset;
	
	return timere[1]; //de id timer
}

ISR(TIMER0_COMPA_vect){ 
	
	cli();
	
	sys_tick++;	
	flag = 1;
	//counter++;
	
	sei();
}
