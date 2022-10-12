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

void transmit_data(unsigned char data)
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
		transmit_data(*c); //fara intrerupere
		c++;
		//if(flag_tx == 1) //cu intrerupere
		//{
			//UDR0 = *c;
			//c++;
			//flag_tx = 0;
		//}
	}
}

ISR(USART_RX_vect){
	
	flag_rx = 1;
}

void receive_data(){
	
	int i;
	i = 0;
		
	if(flag_rx == 1)
	{	
		//PORTB &= ~(1 << PINB0); //pt debug
			
		c[i] = UDR0;
		i++;
			
		flag_rx = 0;	
	}
	else
	{
		//send_data(c);
		
		switch_data(c);
		
		//PORTB |= (1 << PINB0);  //pt debug
		
		//--------------test---------------------//
	/*
	
		if( strcmp(c, "m") == 0)
		{
			send_data(CLEAR);
			afisare_meniu();
			new_line();
			flag_afisare_timp = 0;
		}
		else
		{
			//send_data(c); //afiseaza prima litera
			if((*c != '\r') && (*c != '\0')){
				send_data("Incorect!\n\r");
				afisare_meniu();
				new_line();
			}
		}
	*/
		//---------------test--------------------//
	}			
}
