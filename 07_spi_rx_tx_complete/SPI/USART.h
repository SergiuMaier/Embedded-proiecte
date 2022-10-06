/*
 * main_func.h
 *
 * Created: 9/29/2022 11:46:43 AM
 *  Author: Sergiu Maier
 */ 

#ifndef MAIN_FUNC_H_
#define MAIN_FUNC_H_

#include "main_defines.h"

#include <util/delay.h>

volatile uint8_t flag_tx;
volatile uint8_t flag_rx;
volatile uint8_t afiseaza_timp;
uint8_t flag_afisare_timp;
uint8_t stare_led;

void init_USART(uint16_t ubrr);

void send_data(char *c);

void receive_data();

void switch_data(char c);

void new_line();

ISR(USART_UDRE_vect);

ISR(USART_RX_vect);

#endif /* MAIN_FUNC_H_ */