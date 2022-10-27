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
	ADCSRA |= (1 << ADPS2)|(1 << ADPS1)|(1 << ADPS0); //prescalar 128
	ADMUX |= (0 << REFS1)|(0 << REFS0); //AREF, Vref off
	ADCSRA |= (1 << ADEN); //ADC ON
	ADCSRA |= (1 << ADSC); //o conversie initiala pt test
}

uint16_t read_ADC(uint8_t input)
{
	ADMUX &= 0xF0;
	ADMUX |= input;
	ADCSRA |= (1 << ADSC); //start conversie
	
	while(ADCSRA & (1 << ADSC));
	
	return ADCW;	//returneaza valoarea convertita, de pe pinul ales
}

void start_conversie()
{
	send_data("Valoare: ");
	
	val_adc = 0.004882815*read_ADC(0); //step_ADC*val
	itoa(val_adc, buffer, 10);
	send_data(buffer);
	send_data("\r\n");
	
	_delay_ms(100);
}