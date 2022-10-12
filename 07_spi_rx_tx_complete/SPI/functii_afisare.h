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

uint8_t flag_afisare_timp;

void switch_data(char data[]);
void new_line();
void afisare_meniu();
void afisare_timp();

#endif /* FUNCTII_AFISARE_H_ */