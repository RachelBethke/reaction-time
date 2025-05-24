#ifndef LED_CONTROL_H_
#define LED_CONTROL_H_

#include <stdint.h>

// init GPIO pins
void led_init(void);

// Red LED
void led_red_on(void);
void led_red_off(void);
void led_red_toggle(void);

// Green LED
void led_green_on(void);
void led_green_off(void);
void led_green_toggle(void);

// Turn both LEDs off
void led_all_off(void);

// Blocking delay in ms
void delay_ms(uint32_t ms);

#endif
