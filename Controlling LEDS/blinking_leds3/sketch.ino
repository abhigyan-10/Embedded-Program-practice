//following the pattern of positions 3,7 -> 2,6 -> 1,5 -> 0,4 on port A of arduino MEGA
#include "led.h"

void setup() {
  // put your setup code here, to run once:
  init();
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile long x;
  volatile unsigned char m=0;
  volatile char i;
  for(i=0;i<4;i++){
    output(m>>i);
    // output(m);
    // m=m/2;
    for(x=0;x<=450000;x++);
    
  }
  for(i=2;i>0;i--){
    output(m>>i);
    for(x=0;x<=450000;x++);
    
  }
}
