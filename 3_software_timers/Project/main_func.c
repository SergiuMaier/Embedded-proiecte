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
int contor_on = 0;		//contor pentru masurarea duratei de timp in care LED-urile sunt aprinse
int counter = 0;		//contor pt sys_ticks

typedef struct timer{
	
	int counter_initial;		//timpul la care porneste timer-ul;
	int counter_curent;			//sys_tick
	int stare_timer;			//ex. t1.stare_timer = pornit;
	int autoreseteaza;			//TRUE sau FALSE = one_shot;
	
								//durata timer = counter_curent - counter_initial (in milisecunde);
	
	void *pfct;
	 
};  //timere[MAX_NR_TIMERE]

void set_pin(volatile uint8_t *port, uint8_t pin){  //modifica in toggle dupa test
	
	*port |=  1 << pin;
}

void aprinde_led(volatile uint8_t *port, uint8_t pin, void(*fct_callback)(uint8_t, uint8_t)){  //netestata, dar sintaxa e ok
	
	return fct_callback(*port, pin);
}

void creeaza_timer(int contor_initial, int perioada, int stare, int autoreset, void *pfct){
	struct timer t;
	
	perioada--; //perioada = 3000 => loop => perioada = 0 => stare = expirat
	//trebuie o conditie intre sys_tick si stare pt a ramane expirat sau nu
	//cred ca perioada poate fi introdusa in struct
	
	t.counter_initial = contor_initial;
	t.counter_curent = sys_tick; //nu stiu daca trebuie variabila asta, pare in plus 
	t.stare_timer = stare;
	t.autoreseteaza = autoreset; 
	
	/*
	//in main pt un singur element
	struct timer x;
	x = creeaza_timer(.....);
	*/
}

void evalueaza_timer(struct timer t){
	
	//timerul expira la 2 sec
	//daca timpul a trecut => stare = expirat => apelare callback
	//vf autoreset => schimbare stare
	
	if(	t.stare_timer == EXPIRAT ){
		aprinde_led(&PORTB, PINB0, set_pin);
		
		if( t.autoreseteaza == TRUE){
			t.stare_timer = PORNIT;
			//counter = 0; perioada cred;
		}
		else{
			t.stare_timer = OPRIT;
		}
	}
	
}

void reseteaza_timer(struct timer t){
	
	//resetare valori la 0
}

void update_timer(struct timer t){
	
	//modificare perioada, autoreset din creeare_timer
}

ISR(TIMER0_COMPA_vect){  //pt caz general
	
	cli();
	
	sys_tick++;	//pt a-l folosi in main
	
	//counter++;
	
	//if(sys_tick >= (1/GENERARE_INTRERUPERE)){ // 1 sec
		//counter++; //1 sec
	//}
	
	sei();
}
