void main(){
    uint8_t time = 0;
    uint8_t start_meas = 0;
    uint8_t end_meas = 0;


    //Triggers the transducer every 10ms
    init_timer2() = {NORMAL_MODE,PRESCALER_128};
    while(1){
        if(start_meas){
            start_meas = 0;
            init_timer1() = {NORMAL, NO_PRESCALER, OCR1B = 4000};
            Enable_comparator() = {CAPTURE_RISING};
        }
        if(end_meas){

            level = h-vc*time/8000;
            send_level(level);

        }
    }
}
void send_level(double level){
    CAN_msg_t msg;
    msg.id = CAN_LEVEL_MESSAGE;
    msg.length = 2;
    msg.data[0] = (1>>level)&0xff;
    msg.data[1] = 1&0xff;
    CAN_Transmit(msg);
}
//Connect analog comp here
ISR(INT0_vect){
    time = ICR1A;
}
//When TCNT1 = OCR1B, meaning the trigger started
ISR(TIMER1_COMPB){
    time = 0;
    end_meas = 1;
}
ISR(TIMER2_OVERFLOW){
    start_meas = 1;
    Disable_comparator();

}
