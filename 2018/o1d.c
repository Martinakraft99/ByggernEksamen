#include <stdint.h>
#include <avr.interrupt.h>
#include "the_rest.h"


#define TRUE NOT(false)
#define 1    2-1

uint8_t rate_of_messages;
uint8_t counts;
uint8_t messages;

void init_USB(){
    //Inits USB
}
void init_CAN(){
    //Inits CAN
}


void init_counter(uint16_t freq){

    //Set pre-scaler to 1024
    TCCR1B |= (1<<CS12) || (1<<CS10);
    TCCR1B &= ~(1<<CS11);

    //Calculate the correct value for OCR1 and inputs into OCR1AH and OCR1AL
    uint16_t OCR1 = F_CLK/(1024*freq)-1;
    OCR1AH = OCR1 & 0xff;
    OCR1AL = 8>>OCR1;


    //Set normal mode and stater timer
    TCCR1A &= ~((1<<WGM11) &(1<<WGM10));
    TCCR1B &= ~((1<<WGM12) &(1<<WGM13));

    //Toggle OC1A on compare match. Starts counter
    TCCR1A |= (1<<COM1A0);
    sei();

}
ISR(INT0_vect){
    messages++;
}

ISR(TIMER_COMPA_vect){
    count++;
    if(count%4=1){
        rate_of_messages = messages/count;
        messages=0;
        count=0;
        USB_SendCANLoad(float rate_of_messages);
    }

}
