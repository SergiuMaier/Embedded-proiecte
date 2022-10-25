/*
 * main_func.h
 *
 * Created: 9/29/2022 11:46:43 AM
 *  Author: Sergiu Maier
 */ 

#ifndef MAIN_FUNC_H_
#define MAIN_FUNC_H_

#include "main_defines.h"
#include "functii_afisare.h" //doar pt switch_data

#include <util/delay.h>
#include <string.h>

volatile uint8_t flag_tx; //flag-uri folosite atunci cand are loc o intrerupere de USART
volatile uint8_t flag_rx; //flag_rx devine 1 atunci cand este apasata tasta Enter
char mesaj[50];

void init_USART(uint16_t ubrr); //initializare
void transmit_data(unsigned char data); //transmitere date
unsigned char receive_data(void); //primire date
void send_data(char data[]);  //trimiterea unui nou mesaj
void read_data(char data[]);  //citirea unui mesaj primit
void start_program(); //citirea si executarea comenzilor primite
ISR(USART_TX_vect);
ISR(USART_RX_vect);

#endif /* MAIN_FUNC_H_ */