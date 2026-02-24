//leds glowing 0to7 and then turn turning off one by one ftom 7 to 0
#include "led.h"

void setup() {
  // put your setup code here, to run once:
  init();
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile long x;
  volatile unsigned char s=0x00;
  volatile unsigned char n=0x00;
  volatile char i;
  for(i=0;i<=7;i++){
      s=s|(1<<i);
      output(s);
      for(x=0;x<500000;x++); 
  }
  
  for(i=0;i<=7;i++){
      n=s>>i;
      output(n);
      for(x=0;x<500000;x++); 
  }
  
}
