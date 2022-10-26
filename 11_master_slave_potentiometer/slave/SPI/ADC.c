/*
 * ADC.c
 *
 * Created: 10/26/2022 12:58:42 PM
 *  Author: Sergiu
 */ 

#include "ADC.h"

void init_ADC()
{	
	//DIDR0
	ADMUX |= (0 << REFS1)|(0 << REFS0)|(0 << ADLAR);
	ADCSRA |= (1 << ADEN)|(0 << ADSC)|(1 << ADATE)|(0 << ADIF)|(0 << ADIE)|(1 << ADPS2)|(0 << ADPS1)|(0 << ADPS0);  
}