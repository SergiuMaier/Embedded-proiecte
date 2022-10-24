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
	}
	
	if(contor_secunde >= 100){
		PORTB |= 1 << PINB1;
	}
	
	if(contor_secunde >= 200)
	{
		PORTB &= ~(1 << PINB1);
		contor_secunde = 0;
	}
}

//calculul latimii impulsului se face in rutina de intrerupere INT0

uint8_t calcul_distanta(){
	
	distanta = timp_final*VITEZA_SUNETULUI*0.5*10;
	
	return distanta;
}
