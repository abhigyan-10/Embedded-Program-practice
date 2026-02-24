// following pattern (0,1,2) -> (5,6,7) -> (3,4)
#include "led.h"

void setup() {
  // put your setup code here, to run once:
  init();
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile long x;
  volatile unsigned char s;
  volatile unsigned char n[]={3,3,2};
  volatile unsigned char p[]={0,5,3};
  volatile char i;
  for(i=0;i<=2;i++){
      s=(1<<n[i])-1;
      output(s<<p[i]);
      for(x=0;x<500000;x++); 
  }
}
