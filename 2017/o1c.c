

void main(){
    //Timer 2 now gives TOV1-interupt at 1HZ
    uint32_t sec = 0;
    uint8_t min = 0;
    uint8_t hour = 0;
    uint8_t day = 0;
    init_timer2() = {NORMAL_MODE,PRESCALER_128};
    while(1){
        if(sec%60==0){
            min++;
        }
        if(min%60==0){
            hour++;
            min = 0;
        }
        if(hour%24==0){
            day++;
            hour = 0;
        }
    }
}
ISR(TIMER2_OVERFLOW){
    sec++;
    send_time(sec)
}
void send_time(uint32_t time){
    CAN_msg_t = msg;
    msg.id = CAN_ID_TIME;
    msg.length = 4;
    msg.[0] = (sec>>24)&0xff;
    msg.[1] = (sec>>16)&0xff;
    msg.[2] = (sec>>8)&0xff;
    msg.[3] = sec&0xff;
    CAN_Transmit(msg);

}
