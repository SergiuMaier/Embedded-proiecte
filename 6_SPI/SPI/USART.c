/*
 * main_func.c
 *
 * Created: 9/29/2022 11:46:57 AM
 *  Author: Sergiu Maier
 */ 

#include "USART.h"
#include "timer.h"

void USART_Init(uint16_t ubrr){
	
	UBRR0H = (unsigned char)(ubrr >> 8);
	UBRR0L = (unsigned char)ubrr;
	UCSR0B |= (1 << RXEN0)|(1 << TXEN0);
	UCSR0B |= (1 << RXCIE0)|(1 << UDRIE0);//(1 << TXCIE0)	
	UCSR0C |= (1 << USBS0)|(3 << UCSZ00);
	
	sei();
}

ISR(USART_UDRE_vect){ //apelata atunci cand se pot trimite info

	flag = 1;	
}

ISR(USART_RX_vect){

	char rec;
	rec = UDR0;   //preiau valoarea receptata 
	UDR0 = rec;   //echo 
}

void SendData(char *c){
	
	while(*c != '\0')
	{
		if(flag == 1)
		{			
			UDR0 = *c;
			c++;
			flag = 0;
		}
	}
}