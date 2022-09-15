/*
 * senzor_hc_sr04.h
 *
 * Created: 9/15/2022 10:33:23 AM
 *  Author: sergi
 */ 


#ifndef SENZOR_HC-SR04_H_
#define SENZOR_HC-SR04_H_

#define PIN_TRIG PINB1 //pinii se modific? dup? caz	 
#define PIN_ECHO PINB2

#define VITEZA_SUNETULUI 0.034 //(cm/microsec)

uint8_t durata;
uint8_t distanta;

//functie trigger

//functie masurare latime impuls pin Echo

void calcul_distanta();

#endif /* SENZOR_HC-SR04_H_ */