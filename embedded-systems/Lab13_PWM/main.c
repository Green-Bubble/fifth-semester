#include <targets/at91sam7.h>
#include <adc.h>

int main(){
  ex5();
}

void ex3(){
  PMC_PCER = 1<<3 | 1<<10;  //Podlaczenie do zegara PIOB i PWM
  PIOB_PDR = 1<<20; //Wylaczenie funkcji I/O PINU
  PIOB_ASR = 1<<20; //Przekazanie multipleksacji pod PWM
  
  PWM_CMR1 = 1<<8;  //Ustawienie okresu center aligned
  PWM_CPRD1 = 3200000; //Gorna granica
  PWM_CDTY1 = 3200000/5; //Wypelnienie 20%
  PWM_ENA = 1<<1; //Wlaczenie

  while(1){
    
  }
}

void ex4(){
  PMC_PCER = 1<<3 | 1<<10;  //Podlaczenie do zegara PIOB i PWM
  PIOB_PDR = 1<<21; //Wylaczenie funkcji I/O PINU
  PIOB_ASR = 1<<21; //Przekazanie multipleksacji pod PWM
  
  PWM_CMR2 = 0b0010 | 1<<8;  //Ustawienie okresu center aligned i prescalera MCK/4
  PWM_CPRD2 = 3264000000; //Gorna granica
  PWM_CDTY2 = 3264000000/2; //Wypelnienie 50%
  PWM_ENA = 1<<2; //Wlaczenie

  while(1){
    
  }
}

void ex5(){
  PMC_PCER = 1<<3 | 1<<10;  //Podlaczenie do zegara PIOB i PWM
  PIOB_PDR = 1<<20; //Wylaczenie funkcji I/O PINU
  PIOB_ASR = 1<<20; //Przekazanie multipleksacji pod PWM
  
  PWM_CMR1 = 0b0110 | 1<<9;  //Prescalowanie i odwrocenie polaryzacji
  PWM_CPRD1 = 1023; //Gorna granica
  PWM_CDTY1 = 0; //Wypelnienie
  PWM_ENA = 1<<1; //Wlaczenie

  Init_ADC();

  while(1){
    int bottomThreshold = 280;
    int topThreshold = 500;
    int maxTrim = 1023;
    int scale = topThreshold - bottomThreshold;
    int trim = GetAdcChanel(ADC_CHN_7);

    PWM_CUPD1 = (int)(bottomThreshold + trim*((float)scale/(float)maxTrim)); //Aktualizacja wype³nienia w trakcie pracy
  }
}