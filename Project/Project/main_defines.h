/*
 * main_defines.h
 *
 * Created: 8/31/2022 9:10:38 AM
 *  Author: Sergiu Maier
 */ 

#ifndef MAIN_DEFINES_H_
#define MAIN_DEFINES_H_

#define F_CPU 16000000UL
#define TIMP_ON 4					//durata de timp in secunde cat LED-urile sunt aprinse
#define GENERARE_INTRERUPERE 0.004  //generarea unei intreruperi la fiecare x secunde
#define VALOARE_TOP_REGISTRU 256    //valoarea de top a registrului TCNT0 (pt ca folosesc timer pe 8 biti)

//prescalari
#define TIMER_NO_PRESCALAR     ((0 << CS02) | (0 << CS01) | (1 << CS00))        // 001
#define TIMER_PRESCALAR_8      ((0 << CS02) | (1 << CS01) | (0 << CS00))        // 010
#define TIMER_PRESCALAR_64     ((0 << CS02) | (1 << CS01) | (1 << CS00))        // 011
#define TIMER_PRESCALAR_256    ((1 << CS02) | (0 << CS01) | (0 << CS00))        // 100
#define TIMER_PRESCALAR_1024   ((1 << CS02) | (0 << CS01) | (1 << CS00))        // 101

#endif /* MAIN_DEFINES_H_ */