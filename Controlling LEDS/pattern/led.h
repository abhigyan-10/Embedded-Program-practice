#ifndef LED_H
#define LED_H

void init();
void output(char x);

void init(){
  volatile char *PORT_dir = (char *)0x21;
  *PORT_dir = 0xFF;
}

void output(char x){
  volatile char *out = (char *)0x22;
  *out = x;
}

void pat(char *m){
  volatile long x;
  output(*m);
  for(x=0;x<=600000;x++);
  *m= *m << 2;
  output(*m);
  for(x=0;x<=600000;x++);
  *m=*m>>1;
}
#endif
