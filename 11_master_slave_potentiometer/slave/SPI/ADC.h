/*
 * ADC.h
 *
 * Created: 10/26/2022 12:58:55 PM
 *  Author: Sergiu
 */ 

#ifndef ADC_H_
#define ADC_H_

#include "main_defines.h"

//--Variabile--//

uint16_t val_adc;

//pt conversia var_adc in char 
char buffer[5]; 

//--Prototipuri--//

//initializare ADC
void init_ADC();

//conversia valorii achizitionate si trimiterea ei pe seriala
void start_conversie();

//rutina tratare intrerupere ADC
ISR(ADC_vect);

#endif /* ADC_H_ */