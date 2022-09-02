/*
 * main_func.c
 *
 * Created: 9/01/2022 10:14:32 AM
 *  Author: Sergiu Maier
 */ 

#include "main_func.h"
#include "main_defines.h"
#include "timer0_func_def.h"

int flag_on = 0;		//initial, led-urile sunt stinse
int sys_tick = 0;		//contor pentru generarea secundelor
int contor_on = 0;		//contor pentru masurarea duratei de timp in care LED-urile sunt aprinse
int counter = 0;		//contor pt sys_ticks

struct timer{
	
	enum StareTimer{ pornit = 0, oprit = 1, expirat = 2 }; // eg. timer.StareTimer = pornit;
	int autoreseteaza; //1 sau 0
	int counter_initializare;
	int counter_curent; //posibil in legatura cu sys_tick
	 
};

void pinSet(volatile uint8_t *port, uint8_t pin){
	
	*port |=  1 << pin;
}

void pinReset(volatile uint8_t *port, uint8_t pin){
	
	*port &=  ~(1 << pin);
}

void led_on(){			

	if(flag_on == 1)
	{			
		start_timer0();  //prescalar 64
		pinSet(&PORTB, PINB2);
		pinSet(&PORTB, PINB3);
		
		//if(secunde % 2 == 0)			//test timer
			//pinReset(&PORTB, PINB0);
		//else
			//pinSet(&PORTB, PINB0);
	}
	else
	{
		stop_timer0();
		pinReset(&PORTB, PINB2);
		pinReset(&PORTB, PINB3);
	}
	
	//if((secunde - contor_on) >= TIMP_LEDS_ON){
		//pinReset(&PORTB, PINB0);  //LED vf timer
		//secunde = 0;
		//flag_on = 0;
	//}
}

ISR(TIMER0_COMPA_vect){  //pt caz general
	
	cli();
	
	sys_tick++;
	
	if(sys_tick >= (1/GENERARE_INTRERUPERE)){ // 1 sec
		counter++; //1 sec
		sys_tick = 0;
	}
	
	sei();
}

ISR(INT0_vect){ //pt butonul de on
	
	cli();
	
	flag_on = 1;		 //LED-uri on
	//contor_on = secunde; //determinarea timpului la care a fost apasat butonul
	
	sei();
}

ISR(INT1_vect){ //pt butonul de off
	
	cli();
	
	flag_on = 0; //LED-uri off
	
	sei();
}