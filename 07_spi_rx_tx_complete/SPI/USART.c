/*
 * main_func.c
 *
 * Created: 9/29/2022 11:46:57 AM
 * Author: Sergiu Maier
 */ 

#include "USART.h"

char msg[10]; //trebuie mutate de aici
uint8_t charsize = 50;

void init_USART(uint16_t ubrr){
	
	UBRR0H = (unsigned char)(ubrr >> 8);
	UBRR0L = (unsigned char)ubrr;
	UCSR0B |= (1 << RXEN0)|(1 << TXEN0);
	UCSR0B |= (1 << RXCIE0)|(1 << TXCIE0)|(1 << UDRIE0);
	UCSR0C |= (1 << USBS0)|(3 << UCSZ00);
	
	sei();
}

void transmit_data(unsigned char data)
{
	while (!(UCSR0A & (1<<UDRE0)));
	
	UDR0 = data;
}

unsigned char receive_data(void)
{
	while (!(UCSR0A & (1<<RXC0)));

	return UDR0;
}

ISR(USART_RX_vect) //atunci cand este apasata tasta Enter
{
	//flag_rx = 1;
	
	read_data(msg, charsize);
	switch_data(msg);
}

void send_data(char data[]){
	
	uint8_t i = 0;
	
	while(data[i]){
		transmit_data(data[i]);
		i++;
	}
}

void read_data(char data[], uint8_t max_length)
{	
	char response;
	uint8_t i;
	i = 0;
	
	while (i < (max_length - 1))
	{	
		response = receive_data();		
		
		if(response == '\r')
		{
			break;	
		}
		else
		{
			data[i] = response;
			i++;
		}
	}
	
	data[i] = 0; //final de string
}


