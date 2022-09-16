/*
 * senzor_hc_sr04.c
 *
 * Created: 9/15/2022 10:32:59 AM
 *  Author: sergi
 */ 

#include "senzor_hc_sr04.h"
#include "main_func.h"

void trigger(){
	
	if(contor_secunde >= 10){
		PORTB &= ~(1 << PINB1);
		//*port &= ~(1 << pin);
	}
	
	if(contor_secunde >= 100){
		PORTB |= 1 << PINB1;
		//*port |=  1 << pin;
	}
	
	if(contor_secunde >= 200)
	{
		PORTB &= ~(1 << PINB1);
		//*port &= ~(1 << pin);
		contor_secunde = 0;
	}
}

//void calcul_latime_impuls_echo(volatile uint8_t *port, uint8_t pin){
	//
	//if(flag1 == 1)
	//{
		//if(*port & (1 << pin))
			//timp_start = timp; //primul front al semnalului
		//else
		//{
			//timp_final = timp - timp_start;  //timp intre fronturi
			//timp = 0;
		//}
	//}
	//
//}

uint8_t calcul_distanta(){
	
	distanta = timp_final*VITEZA_SUNETULUI*0.5*10;
	
	return distanta;
}
