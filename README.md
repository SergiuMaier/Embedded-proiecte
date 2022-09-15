## Embedded - proiecte

### Descriere:

- [1_timer0_general](./1_timer0_general/Project)
  
   - implementare rutină de tratare a întreruperii pentru INT0 & INT1;
   - configurare timer0;
   - implementarea rutină de întrerupere pentru contorizarea secundelor;
   - realizare funcție care calculează automat valoarea pentru registrul OCR0A, dat fiind intervalul de timp la care timer-ul executa o întrerupere;
   - s-a încercat implementarea unei modalitați pentru a alege automat prescalarul în registrul TCCR0B, în funcție de valoarea calculată pentru registrul OCR0A;

- [2_timer0_start_stop](./2_timer0_start_stop/Project)
    
   - implementarea timerului 0 a fost mutata in fisierele timer0_func.h si timer0_func.c;
   - realizare functii pt start si stop timer;
   - timer-ul functioneaza doar atunci cand este nevoie sa se contorizeze secuntele;

- [3_software_timer](./3_software_timer/Project)
   
   - realizarea unui timer software;
   - implementarea în noile fișiere stimer.h și stimer.c;
   - realizare funcții pentru creare, update și reset timer;
  
- [4_pwm](./4_pwm/Project)

  - implementare Timer0 cu PWM (explicații în cod);
  - modificarea intensitații unui LED;
   
