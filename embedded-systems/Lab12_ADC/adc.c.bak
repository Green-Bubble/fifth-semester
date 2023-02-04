//adc.c
#include "adc.h"

#define AT91C_BASE_ADC       ((AT91PS_ADC) 	0xFFFD8000) // (ADC) Base Address
#define AT91C_BASE_PMC       ((AT91PS_PMC) 	0xFFFFFC00) // (PMC) Base Address
#define AT91C_ID_ADC    ((unsigned int) 17) // Analog-to-Digital Converter

typedef volatile unsigned int AT91_REG;

typedef struct _AT91S_ADC {
	AT91_REG	 ADC_CR; 	// ADC Control Register
	AT91_REG	 ADC_MR; 	// ADC Mode Register
	AT91_REG	 Reserved0[2]; 	// 
	AT91_REG	 ADC_CHER; 	// ADC Channel Enable Register
	AT91_REG	 ADC_CHDR; 	// ADC Channel Disable Register
	AT91_REG	 ADC_CHSR; 	// ADC Channel Status Register
	AT91_REG	 ADC_SR; 	// ADC Status Register
	AT91_REG	 ADC_LCDR; 	// ADC Last Converted Data Register
	AT91_REG	 ADC_IER; 	// ADC Interrupt Enable Register
	AT91_REG	 ADC_IDR; 	// ADC Interrupt Disable Register
	AT91_REG	 ADC_IMR; 	// ADC Interrupt Mask Register
	AT91_REG	 ADC_CDR0; 	// ADC Channel Data Register 0
	AT91_REG	 ADC_CDR1; 	// ADC Channel Data Register 1
	AT91_REG	 ADC_CDR2; 	// ADC Channel Data Register 2
	AT91_REG	 ADC_CDR3; 	// ADC Channel Data Register 3
	AT91_REG	 ADC_CDR4; 	// ADC Channel Data Register 4
	AT91_REG	 ADC_CDR5; 	// ADC Channel Data Register 5
	AT91_REG	 ADC_CDR6; 	// ADC Channel Data Register 6
	AT91_REG	 ADC_CDR7; 	// ADC Channel Data Register 7
	AT91_REG	 Reserved1[44]; 	// 
	AT91_REG	 ADC_RPR; 	// Receive Pointer Register
	AT91_REG	 ADC_RCR; 	// Receive Counter Register
	AT91_REG	 ADC_TPR; 	// Transmit Pointer Register
	AT91_REG	 ADC_TCR; 	// Transmit Counter Register
	AT91_REG	 ADC_RNPR; 	// Receive Next Pointer Register
	AT91_REG	 ADC_RNCR; 	// Receive Next Counter Register
	AT91_REG	 ADC_TNPR; 	// Transmit Next Pointer Register
	AT91_REG	 ADC_TNCR; 	// Transmit Next Counter Register
	AT91_REG	 ADC_PTCR; 	// PDC Transfer Control Register
	AT91_REG	 ADC_PTSR; 	// PDC Transfer Status Register
} AT91S_ADC, *AT91PS_ADC;

typedef struct _AT91S_PMC {
	AT91_REG	 PMC_SCER; 	// System Clock Enable Register
	AT91_REG	 PMC_SCDR; 	// System Clock Disable Register
	AT91_REG	 PMC_SCSR; 	// System Clock Status Register
	AT91_REG	 Reserved0[1]; 	// 
	AT91_REG	 PMC_PCER; 	// Peripheral Clock Enable Register
	AT91_REG	 PMC_PCDR; 	// Peripheral Clock Disable Register
	AT91_REG	 PMC_PCSR; 	// Peripheral Clock Status Register
	AT91_REG	 Reserved1[1]; 	// 
	AT91_REG	 PMC_MOR; 	// Main Oscillator Register
	AT91_REG	 PMC_MCFR; 	// Main Clock  Frequency Register
	AT91_REG	 Reserved2[1]; 	// 
	AT91_REG	 PMC_PLLR; 	// PLL Register
	AT91_REG	 PMC_MCKR; 	// Master Clock Register
	AT91_REG	 Reserved3[3]; 	// 
	AT91_REG	 PMC_PCKR[4]; 	// Programmable Clock Register
	AT91_REG	 Reserved4[4]; 	// 
	AT91_REG	 PMC_IER; 	// Interrupt Enable Register
	AT91_REG	 PMC_IDR; 	// Interrupt Disable Register
	AT91_REG	 PMC_SR; 	// Status Register
	AT91_REG	 PMC_IMR; 	// Interrupt Mask Register
} AT91S_PMC, *AT91PS_PMC;

AT91PS_ADC a_pADC = AT91C_BASE_ADC;
AT91PS_PMC a_pPMC = AT91C_BASE_PMC;

void InitADC(void) {

  // Enable clock for interface
  a_pPMC->PMC_PCER = 1 << AT91C_ID_ADC;

  // Reset
  a_pADC->ADC_CR = 0x1;
  a_pADC->ADC_CR = 0x0;

  // Set maximum startup time and hold time
  a_pADC->ADC_MR = 0x0F1F0F00;

}


unsigned int GetAdcChanel(unsigned char chanel) {

  // variable
  unsigned int result;

  // Enable desired chanel
  a_pADC->ADC_CHER = chanel;

  // Start conversion
  a_pADC->ADC_CR = 0x2;

  // wait for end of convertion
  while(!(a_pADC->ADC_SR&chanel));

  switch (chanel) {

    case ADC_CHN_1: result = a_pADC->ADC_CDR0; break;
    case ADC_CHN_2: result = a_pADC->ADC_CDR1; break;
    case ADC_CHN_3: result = a_pADC->ADC_CDR2; break;
    case ADC_CHN_4: result = a_pADC->ADC_CDR3; break;
    case ADC_CHN_5: result = a_pADC->ADC_CDR4; break;
    case ADC_CHN_6: result = a_pADC->ADC_CDR5; break;
    case ADC_CHN_7: result = a_pADC->ADC_CDR6; break;
    case ADC_CHN_8: result = a_pADC->ADC_CDR7; break;
  }

  return result;

}
