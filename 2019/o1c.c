#include <stdio.h>

#define PIN_CHANGE_FLAG GIFR->PCIF0

//define global varible
int8_t static position;

uint8_t rot_pos_init(){
    //Set PA1 as input
    DDRA &= ~(1<<0);

    //Set PA0 as pin change interrupt
    PCMSK0 |= (1<<0);

    //Enable pin interupt
    GICR |= (1<<3);

    //Declare and initialize variables
    position = 0;


    return 1;
}
//interrupt if GI
ISR(PIN_CHANGE_FLAG){
    //Check state og channel B
    if(PORTA->PORTA1 ==1){
        position++;
    }
    else{
        position--;
    }
}

int8_t get_pos(){
    return position;
}
