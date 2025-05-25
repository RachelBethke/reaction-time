#include <MKL46Z4.h>
#include "button_control.h"

#define SW1 3  // PTC3
#define SW3 12 // PTC12

void button_init(void){
    SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK; //clock to portc
    //GPIO input pin w/ pull-up register
    PORTC->PCR[SW1] = PORT_PCR_MUX(1) | PORT_PCR_PS_MASK | PORT_PCR_PE_MASK;
    PORTC->PCR[SW3] = PORT_PCR_MUX(1) | PORT_PCR_PS_MASK | PORT_PCR_PE_MASK;
    //Set directions for input
    PTC->PDDR &= ~(1u<<SW1);
    PTC->PDDR &= ~(1u<<SW3);
}

int sw1_down(void){
    return ((PTC->PDIR & (1u << SW1)) == 0); //return 1 if pressed
}

int sw3_down(void){
    return ((PTC->PDIR & (1u << SW3)) == 0); //return 1 if pressed
}