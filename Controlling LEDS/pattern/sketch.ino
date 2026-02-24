// following pattern 0,2,1,3,4,6.5.7
#include "led.h"

void setup() {
  // put your setup code here, to run once:
  init();
}
void loop() {
  // put your main code here, to run repeatedly:
  volatile long x;
  volatile unsigned char s;
  volatile unsigned char p[]={0,2,1,3,4,6,5,7};
  volatile char i;
  for(i=0;i<8;i++){
      s=(1<<1)-1;
      output(s<<p[i]);
      for(x=0;x<600000;x++); 
  }
}
// void loop() {
//   // put your main code here, to run repeatedly:
//   volatile long x;
//   volatile unsigned char m=0x01;
//   volatile unsigned char n=0x10;
//   volatile char i;
//   for(i=0;i<2;i++){
//     pat(&m);
//   }
//   for(i=0;i<2;i++){
//     pat(&n);
    
//   }
// }
}
