
uint8_t rising = 1;
double temp;
void main(){
    init_timer1(NORMAL, PRESCALER_8, CAPTURE_RISING)
}

ISR(TIMER_INPUT_CAPTURE){
    if(rising && t2>0){
        t1 = ICR1-t2;
    }
    else{
        t2 = ICR2;
    }
    if(t1&&t2){
        temp = -200(0.85-t1/t2)+425*t1/t2-273;
    }
}
