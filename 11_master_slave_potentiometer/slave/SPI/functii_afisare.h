/*
 * functii_afisare.h
 *
 * Created: 10/6/2022 10:52:16 AM
 *  Author: Sergiu Maier
 */ 

#ifndef FUNCTII_AFISARE_H_
#define FUNCTII_AFISARE_H_

#include "ADC.h"
#include "timer.h"
#include "USART.h"

#include <stdio.h>
#include <string.h>

//--Variabile--//

//flag pt a memora starea LED-ului
uint8_t stare_led;   

//--Prototipuri--//

//verificarea mesajelor receptionate de la alt mcu si executarea lor
void switch_data(char data[]); 

//schimbare stare led
//@stare poate lua doar valorile 1 sau 0
void schimbare_stare_led(volatile uint8_t *port, uint8_t pin, uint8_t stare); 

//afisare timpul curent in formatul clasic
void afisare_timp();   

#endif /* FUNCTII_AFISARE_H_ */