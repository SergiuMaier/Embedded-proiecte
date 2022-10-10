/*
 * main_func.c
 *
 * Created: 9/29/2022 11:46:57 AM
 * Author: Sergiu Maier
 */ 

#include "USART.h"

void init_USART(uint16_t ubrr){
	
	UBRR0H = (unsigned char)(ubrr >> 8);
	UBRR0L = (unsigned char)ubrr;
	UCSR0B |= (1 << RXEN0)|(1 << TXEN0);
	UCSR0B |= (1 << RXCIE0)|(1 << TXCIE0)|(1 << UDRIE0);
	UCSR0C |= (1 << USBS0)|(3 << UCSZ00);
	
	sei();
}

void USART_Transmit(unsigned char data)
{
	while (!(UCSR0A & (1<<UDRE0)));
	
	UDR0 = data;
}

//----------------------------------------/
ISR(USART_UDRE_vect){ //apelata atunci cand se pot trimite info
	
	//flag_tx = 1;
			
}

ISR(USART_TX_vect){
	
	//NIMIC MOMENTAN
}
//----------------------------------------*/


void send_data(char *c){
	
	while(*c != '\0')
	{
		USART_Transmit(*c);
		c++;
		//if(flag_tx == 1)
		//{
		//	UDR0 = *c;
		//	c++;
		//	flag_tx = 0;
		//}
	}
}

ISR(USART_RX_vect){
	
	flag_rx = 1;
}

void receive_data(){
	
	char c;
	 
	if(flag_rx == 1)
	{	
		
		c = UDR0;
		//UDR0 = c; //echo, afisez ce trimit (tastez)
		//c++;  
			
		switch_data(c);	
		flag_rx = 0;
	}
}

