#ifndef LED_H
#define LED_H

void init();
void output(char x);

void init(){
  volatile char *PORT_dir = (char *)0x24;
  *PORT_dir = 0xFF;
}

void output(char x){
  volatile char *out = (char *)0x25;
  *out = x;
}

#endif
