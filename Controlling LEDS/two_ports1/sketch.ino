// moving from bottom row to top row and reverse
#include "led.h"

void setup() {
  // put your setup code here, to run once:
  init();
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile unsigned short s;
  volatile long i;
  volatile char a;
  for(a=0;a<=15;a++){
    s = 1 << a;
    output((unsigned char)(s& 0x00FF));
    output1((unsigned char)((s>>8)& 0x00FF));
    for(i=0;i<=500000;i++);
  }
  for(a=14;a>=0;a--){
    s = 1 << a;
    output((unsigned char)(s & 0x00FF));
    output1((unsigned char)((s>>8)& 0x00FF));
    for(i=0;i<=500000;i++);
  }
}
