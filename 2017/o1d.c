

void main(){
    uint8_t count;
    //Exactly the same as for NODE A
    timer2_init() = {NORMAL_MODE,PRESCALER_128};
    while(1){
        //LOREM IPSUM DOLOR SIT AMET
    }
}
//CAN MESSAGE
ISR(INT0_vect){
    CAN_msg_t msg;
    CAN_Recieve(&msg); //Assumed to exist
    if(msg.id == CAN_ID_TIME){
        count = 0;
    }
}
ISR(TIMER2_OVERFLOW){
    count++;
    if(count >=2){
        alarm_handler();
    }
}
