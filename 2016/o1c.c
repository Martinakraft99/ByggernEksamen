
void main(){
    init_timer1(FAST_PWM, PRESCALER_1024, TOP = 0x00ff, NON_INVERTING,OCR1A);
    while(1){
        //Delay for button bounces
    }
}
//Connect dim-down to INT0
ISR(INT0){
    OCR1A --;
}
//Connect dim-up to INT0
ISR(INT1){
    OCR1++;
}
