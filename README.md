## Embedded Systems - playground

### 📑 Descriere proiecte:
---
📁 [01_timer0_general](./01_timer0_general/Project)
  
   - întreruperi INT0 & INT1;
   - configurare timer0;
   - rutină de întrerupere pentru contorizarea secundelor;
   - realizare funcție care calculează automat valoarea pentru registrul OCR0A, dat fiind intervalul de timp la care timer-ul executa o întrerupere;
   - s-a încercat implementarea unei modalitați pentru a alege automat prescalarul în registrul TCCR0B, în funcție de valoarea calculată pentru registrul OCR0A;
---
📁 [02_timer0_start_stop](./02_timer0_start_stop/Project)
    
   - implementarea timerului 0 a fost mutata in fisierele timer0_func.h si timer0_func.c;
   - realizare functii pt start si stop timer;
   - timer-ul functioneaza doar atunci cand este nevoie sa se contorizeze secuntele;

---
📁 [03_software_timer](./03_software_timer/Project)
   
   - realizarea unui timer software;
   - implementarea în noile fișiere stimer.h și stimer.c;
   - realizare funcții pentru creare, update și reset timer;
---   
📁 [04_timer0_pwm](./04_timer0_pwm/Project)

  - implementare Timer0 cu PWM (explicații în cod);
  - modificarea intensitații unui LED;
---   
📁 [05_hcsr04_lib](./05_hcsr04_lib/Project)
  - creare librarie pentru senzorul cu ultrasunete care poate fi inclusa in viitoarele proiecte;
---  
📁 [06_cronometru_putty](./06_cronometru_putty/SPI)
  - afisare cronometru pe seriala;
---  
📁 [07_usart_rx_complete_interrupt](./07_usart_rx_complete_interrupt/SPI)  
  - recunoasterea unui singur caracter introdus in putty;
  - executarea unor comenzi pe baza caracterelor primite;
  - partial functional (bug rezolvat complet in 08);
---
📁 [08_send_read_text](./08_send_read_text/SPI) 
  - trimiterea si citirea mesajelor pe seriala;
  - recunoasterea si executarea comenzilor introduse in Putty;
---
📁 [09_master_slave_simplex_mode](./09_master_slave_simplex_mode)      
 |─📂[master](./09_master_slave_simplex_mode/master/SPI)    
 |─📂[slave](./09_master_slave_simplex_mode/slave/SPI)
    
  - se utilizează două plăcuțe Arduino cu microcontroler ATmega328P;
  - de la un microcontroler (master) se trimit mesaje/comenzi prin interfata seriala catre celalalt microcontroler (slave);
  - comenzile primite sunt verificate si executate de catre slave (ex: schimbarea starii unul LED, afisare timp, clear Putty);
  - conexiuni: TX (master) - RX (slave);
---
📁 [10_master_slave_full_duplex](./10_master_slave_full_duplex)      
 |─📂[master](./10_master_slave_full_duplex/master/SPI)    
 |─📂[slave](./10_master_slave_full_duplex/slave/SPI)

-
-
---
