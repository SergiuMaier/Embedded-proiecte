/*
 * main_func.c
 *
 * Created: 9/21/2022 11:46:57 AM
 *  Author: sergiu
 */ 

#include "main_defines.h"
#include "USART_func.h"

void USART_Init(unsigned int ubrr)
{
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);	
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}

void USART_Transmit(unsigned char data){
	
	while(!(UCSR0A & (1<<UDRE0)));
	
	UDR0 = data;
}

unsigned char USART_Receive(void){
	
	while(!(UCSR0A & (1<<RXC0)));
	
	return UDR0;
}

void send_data(char *ptr){
	
	while(*ptr != 0x00)
	{
		USART_Transmit(*ptr);
		ptr++;
	}
}