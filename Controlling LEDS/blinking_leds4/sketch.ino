// leds moving from 0 to 7 and then 7 to 0
#include "led.h"

void setup() {
  // put your setup code here, to run once:
  init();
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile long x;
  // volatile unsigned char m=0;
  volatile char i;
  for(i=0;i<8;i++){
    output(1<<i);
    // output(m);
    // m=m/2;
    for(x=0;x<=350000;x++);
    
  }
  for(i=7;i>=0;i--){
    output(1<<i);
    for(x=0;x<=350000;x++);
    
  }
}
