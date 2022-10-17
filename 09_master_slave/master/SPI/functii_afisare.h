/*
 * functii_afisare.h
 *
 * Created: 10/6/2022 10:52:16 AM
 *  Author: Sergiu Maier
 */ 

#ifndef FUNCTII_AFISARE_H_
#define FUNCTII_AFISARE_H_

#include "timer.h"
#include "USART.h"

#include <stdio.h>
#include <string.h>

uint8_t stare_led;    //flag pt a memora starea LED-ului

void switch_data(char data[]); //verificare mesaje primite din putty si executarea lor
void new_line();      //inceput de rand nou, unde se poate tasta o comanda
void afisare_meniu(); //afisare lista comenzi

#endif /* FUNCTII_AFISARE_H_ */