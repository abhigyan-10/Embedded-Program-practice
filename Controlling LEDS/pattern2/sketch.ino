// following pattern in pair (0,1) -> (6,7) -> (2,3) -> (4,5)
#include "led.h"

void setup() {
  // put your setup code here, to run once:
  init();
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile long x;
  volatile unsigned char s;
  volatile unsigned char p[]={0,6,2,4};
  volatile char i;
  for(i=0;i<4;i++){
      s=(1<<2)-1;
      output(s<<p[i]);
      for(x=0;x<500000;x++); 
  }
}

// void loop() {
//   // put your main code here, to run repeatedly:
//   volatile long x;
//   volatile unsigned char s=0x03;
//   volatile unsigned char n=0xC0;
//   volatile char i;
//   for(i=0;i<2;i++){
      
//       output(s);
//       for(x=0;x<500000;x++); 
//       output(n);
//       for(x=0;x<500000;x++); 
//       s = s << 2;
//       n = n >> 2;
//   }
// }
