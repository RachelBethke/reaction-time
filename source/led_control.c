#include <MKL46Z4.h>
#include "led_control.h"

#define RED_LED_FRDM_PIN 29 //PTE29
#define GREEN_LED_FRDM_PIN 5 //PTD5

void led_init(void) {
    // Enable clock to Port D and Port E
    SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK | SIM_SCGC5_PORTD_MASK;

    // Configure PTE29 (Red) as GPIO output
    PORTE->PCR[RED_LED_FRDM_PIN] = PORT_PCR_MUX(1);
    PTE->PDDR |= (1 << RED_LED_FRDM_PIN);
    PTE->PSOR = (1 << RED_LED_FRDM_PIN); // LED off

    // Configure PTD5 (Green) as GPIO output
    PORTD->PCR[GREEN_LED_FRDM_PIN] = PORT_PCR_MUX(1);
    PTD->PDDR |= (1 << GREEN_LED_FRDM_PIN);
    PTD->PSOR = (1 << GREEN_LED_FRDM_PIN); // LED off
}

// Red LED
void led_red_on(void) {
    PTE->PCOR = (1 << RED_LED_FRDM_PIN);
}
void led_red_off(void){
    PTE->PSOR = (1 << RED_LED_FRDM_PIN);
}
void led_red_toggle(void){
    PTE->PTOR = (1 << RED_LED_FRDM_PIN);
}

// Green LED control
void led_green_on(void){
    PTD->PCOR = (1 << GREEN_LED_FRDM_PIN);
}
void led_green_off(void){
    PTD->PSOR = (1 << GREEN_LED_FRDM_PIN);
}
void led_green_toggle(void){
    PTD->PTOR = (1 << GREEN_LED_FRDM_PIN);
}

//TODO: Something to turn both off
