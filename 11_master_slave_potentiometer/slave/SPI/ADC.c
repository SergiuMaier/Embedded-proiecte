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
	DDRC = ~(1 << PINC0);     //pin A0 intrare
	DIDR0 |= (1 << ADC0D);    //dezactivare buffer
	
	
	//ADMUX |= (0 << REFS1)|(0 << REFS0);     //valoare de referinta AREF               
	
	ADMUX |= (1 << REFS0);                                   //tensiune de referinta AVCC
	ADCSRA |= (1 << ADIE)|(1 << ADEN)|(1 << ADATE);          //activare intrerupere, activare adc, autotrigger 
	ADCSRB &= ~((1 << ADTS2) | (1 << ADTS1) | (1 << ADTS0)); //free running mode
	ADCSRA |= (1 << ADPS2)|(1 << ADPS1)|(1 << ADPS0);        //prescalar 128
	ADCSRA |= (1 << ADSC);                                   //start o conversie initiala (test)
	
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