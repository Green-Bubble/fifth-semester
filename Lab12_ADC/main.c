#include <targets/AT91SAM7.h>
#include "adc.h"
#include "lcd.h"

#define AUDIO_OUT PIOB_SODR_P19 //
#define SW_1 PIOB_SODR_P24 // lewy przycisk
#define SW_2 PIOB_SODR_P25 // prawy przycisk

__attribute__((section(".fast"))); // konfiguracja delay

void delay(int n){
  volatile int i;

  for(i=3000*n; i>0; i--)
  {
    __asm("nop");
  }
}


int main(void){


  PMC_PCER = PMC_PCER_PIOB; //w³¹czenie obs³ugi przerwañ
  PIOB_OER = AUDIO_OUT;
  PIOB_PER = AUDIO_OUT;
  int kanal;
  int w;
  int x=25, y=50;
  int play=-1, play_b=-1;
  char* bufor;

  InitLCD();
  Init_ADC();

  LCDSettings();//ustawienie LCD
  LCDClearScreen(); 

  LCDSetRect(0,0,130,130,FILL,BLACK);

  while(1){
  //------------------ZADANIE 1----------------------------------
/*
    kanal = GetAdcChanel(ADC_CHN_7);
    switch(kanal){
    case 0: // MIN
      LCDPutStr("          ",y,x,LARGE,WHITE,BLACK);
      if (play_b==0){
      PIOB_SODR |= AUDIO_OUT;
      delay(1);
      PIOB_CODR |= AUDIO_OUT;}
      play=1;
      play_b=1;
      break;
    case 102:
      LCDPutStr("*         ",y,x,LARGE,WHITE,BLACK);
      if ((play==1)||(play_b==1)){
        PIOB_SODR |= AUDIO_OUT;
        delay(1);
        PIOB_CODR |= AUDIO_OUT;
      }
      play=2;
      play_b=0;
    break;
    case 204:
      LCDPutStr("**        ",y,x,LARGE,WHITE,BLACK);
      if ((play==2)||(play_b==2)){
        PIOB_SODR |= AUDIO_OUT;
        delay(1);
        PIOB_CODR |= AUDIO_OUT;
      }
      play=3;
      play_b=1;
    break;
    case 306: LCDPutStr("***       ", y, x, LARGE, WHITE, BLACK);
    if ((play == 3) || (play_b == 3)) {
      PIOB_SODR |= AUDIO_OUT;
      delay(1);
      PIOB_CODR |= AUDIO_OUT;
    }
    play = 4;
    play_b = 2;
    break;
    case 409: LCDPutStr("****      ", y, x, LARGE, WHITE, BLACK);
    if ((play == 4) || (play_b == 4)) {
      PIOB_SODR |= AUDIO_OUT;
      delay(1);
      PIOB_CODR |= AUDIO_OUT;
    }
    play = 5;
    play_b = 3;
    break;
    case 512: LCDPutStr("*****     ", y, x, LARGE, WHITE, BLACK);
    if ((play == 5) || (play_b == 5)) {
      PIOB_SODR |= AUDIO_OUT;
      delay(1);
      PIOB_CODR |= AUDIO_OUT;
    }
    play = 6;
    play_b = 4;
    break;
    case 614: LCDPutStr("******    ", y, x, LARGE, WHITE, BLACK);
    if ((play == 6) || (play_b == 6)) {
      PIOB_SODR |= AUDIO_OUT;
      delay(1);
      PIOB_CODR |= AUDIO_OUT;
    }
    play = 7;
    play_b = 5;
    break;
    case 716: LCDPutStr("*******   ", y, x, LARGE, WHITE, BLACK);
    if ((play == 7) || (play_b == 7)) {
      PIOB_SODR |= AUDIO_OUT;
      delay(1);
      PIOB_CODR |= AUDIO_OUT;
    }
    play = 8;
    play_b = 6;
  break;
    case 818: LCDPutStr("********  ", y, x, LARGE, WHITE, BLACK);
    if ((play == 8) || (play_b == 8)) {
      PIOB_SODR |= AUDIO_OUT;
      delay(1);
      PIOB_CODR |= AUDIO_OUT;
    }
    play = 9;
    play_b = 7;
    break;
    case 921: LCDPutStr("********* ", y, x, LARGE, WHITE, BLACK);
    if (play == 9) {
      PIOB_SODR |= AUDIO_OUT;
      delay(1);
      PIOB_CODR |= AUDIO_OUT;
    }
    play = 10;
    play_b = 8;
    break;
    case 1023: LCDPutStr("**********", y, x, LARGE, WHITE, BLACK);
    if (play == 10) {
      PIOB_SODR |= AUDIO_OUT;
      delay(1);
      PIOB_CODR |= AUDIO_OUT;
    }
    play = 9;
    break;
    }
    if ((PIOB_PDSR & SW_1) == 0) {
      bufor = (char * ) malloc(40);
      LCDPutStr("    ", 70, 40, LARGE, BLACK, BLACK);
      sprintf(bufor, "%d\0", kanal);
      LCDPutStr(bufor, 70, 40, LARGE, WHITE, BLACK);
      free(bufor);
    }
    if ((PIOB_PDSR & SW_2) == 0) {
      LCDPutStr("    ", 70, 40, LARGE, BLACK, BLACK);
    }
*/
    //------------------ZADANIE 2----------------------------------
    
    kanal = (float)GetAdcChanel(ADC_CHN_6);
    
    int thermistorMin = 555;
    int thermistorMax = 575;
    int tempMin = 22;
    int tempMax = 37;
    int tempRange = tempMax - tempMin;
    int thermistorRange = thermistorMax - thermistorMin;

    int temperature = (kanal-thermistorMin)*((float)tempRange/(float)thermistorRange) + tempMin;

    bufor = (char * ) malloc(40);
    sprintf(bufor, "%dC\0", temperature);
    LCDPutStr(bufor, 50, 40, LARGE, WHITE, BLACK);
    free(bufor);
  }
  return 0;
}
