/*
 * ADC.c
 *
 * Created: 10/26/2022 12:58:42 PM
 *  Author: Sergiu
 */ 

#include "ADC.h"
#include "USART.h"

void init_ADC()
{	
	DDRC = ~(1 << PINC0);
	DIDR0 |= (1 << ADC0D);    //disable digital input buffer
	
	//ADMUX |= (0 << REFS1)|(0 << REFS0);                    //voltage ref. AREF
	
	ADMUX |= (1 << REFS0);                                   //AVCC
	ADCSRA |= (1 << ADIE)|(1 << ADEN)|(1 << ADATE);          //enable interrupt,start adc, autotrigger
	ADCSRB &= ~((1 << ADTS2) | (1 << ADTS1) | (1 << ADTS0)); //free running mode
	ADCSRA |= (1 << ADPS2)|(1 << ADPS1)|(1 << ADPS0);        //prescaler 128
	ADCSRA |= (1 << ADSC);                                   //start initial conversion (test)
	
	sei();
}

ISR(ADC_vect)
{	
	val_adc = ADCL;
	val_adc |= (uint16_t)(ADCH << 8);
}

void start_conversie()
{
	itoa(val_adc, buffer, 10);
	send_data(buffer);
}