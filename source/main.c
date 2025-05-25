#include <MKL46Z4.h>
#include <led_control.h>

#define RELOAD 48000

volatile int millis;
int pressed = 0; //false

//SysTick_Config(reload); //set reload value
//Set reload val, enable SysTick and its interrupt

void SysTick_Handler(void){
    millis++;
}

// The function returns 1 (true) if pin 3 of Port C is low
// indicating that the button (or switch) connected to this pin is pressed.
// If the pin is high, the function returns 0 (false), meaning the button is not pressed.
static int prsd_switch(void){
    return ((PTC->PDIR & (1u << 3)) == 0);
}

void button_update(void){
    int current = prsd_switch();
}

int main(void){
    led_init();
    SysTick_Config(RELOAD);
    //SysTick interrupt handler
    volatile int curr_time = millis;
    int last_time = 0;
    while(1){
        //Store a last_time
        //Check if (current_time - last_time) >= 1000
        curr_time = millis;
        if ((curr_time - last_time)>= 1000){
            prsd_switch();
            last_time = curr_time;
            red_on_frdm();
        }
    }
}

