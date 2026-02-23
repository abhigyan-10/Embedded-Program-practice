//make the leds glow one by one....without turning off the led for port B
#include "led.h"

void setup() {
  // put your setup code here, to run once:
  init();
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile long x;
  volatile char s=0;
  volatile char i;
  for(i=0;i<=7;i++){
    s= s|(1<<i);
    output(s);
    for(x=0;x<=300000;x++);
  }
}
