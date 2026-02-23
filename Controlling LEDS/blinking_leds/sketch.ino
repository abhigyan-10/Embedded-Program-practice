#include "led.h"

void setup() {
  // put your setup code here, to run once:
  init();
}

void loop() {
  // put your main code here, to run repeatedly:
  char x=0xFF;
  volatile short i;
  output(x);
  for(i=0;i<=10000;i++);
  x = 0;
  output(x);
  for(i=0;i<=10000;i++);
}
