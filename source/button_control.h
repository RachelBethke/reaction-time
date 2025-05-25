#ifndef BUTTON_CONTROL_H_
#define BUTTON_CONTROL_H_

//#include <stdint.h>

// init SW1 and SW3 pins
void button_init(void);

int sw1_down(void);
int sw3_down(void);

#endif