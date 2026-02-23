#include "led.h"

void setup() {
  // put your setup code here, to run once:
  init();
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile long x;
  char s;
  volatile char i;
  for(i=0;i<=7;i++){
    s=1<<i;
    output(s);
    for(x=0;x<=60000;x++);
  }
}
