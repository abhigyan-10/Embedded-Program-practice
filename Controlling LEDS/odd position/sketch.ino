#include "led.h"
void setup() {
    init();
}

void loop() {
  // char x=0b10101010;
  // output(x);
  char i;
  for(i = 0; i<8;i++){
    if(i%2 != 0 )
      output(1<<i);
  }
}
