//blink all the 16 leds from top row to bottom row
#include "led.h"

void setup() {
  // put your setup code here, to run once:
  init();

}

void loop() {
  // put your main code here, to run repeatedly:
  volatile short s = 0x0001;
  volatile long i;
  volatile char a;
  for(a=0;a<=15;a++){
    output1((unsigned char)(s& 0x00FF));
    output((unsigned char)((s>>8)& 0x00FF));
    for(i=0;i<=500000;i++);
    s=s<<1;
  }
}
