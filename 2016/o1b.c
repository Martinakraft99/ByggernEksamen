#include


void main(){
    uint8_t count = 0;

    //Initalize counter to run with TOV1 interrupt at 100Hz
    init_counter(MODE = normal, PRESCALER = NONE, CLOCK = SYSTEM_CLOCK)
    init_PID();
    init_LCD();

    while(1){
        //Will update at 100/2HZ = 50Hz
        if(count%2==0){
            LCD_update();
        }
        //Will update at 100/8HZ = 12.5Hz
        if(count%8==0){
            PID_update();
        }
        //Could mayby implement some logic to avoid count overflow.
    }
}
//The update should be placed in the ISR, because the loop will then run unaffected by whatever is in main 
ISR(TIMER1_OWERFLOW){
    count++;
    //Will update at 100/2HZ = 50Hz
    if(count%2==0){
        LCD_update();
    }
    //Will update at 100/8HZ = 12.5Hz
    if(count%8==0){
        PID_update();
    }
    //Could mayby implement some logic to avoid count overflow.
}
