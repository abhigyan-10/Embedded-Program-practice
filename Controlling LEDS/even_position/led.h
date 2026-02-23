//only applicable for PORT L of Arduino Mega
void init();
void output(char x);

void init(){
  volatile char *PORT_dir = (char *)0x10A;
  *PORT_dir = 0xFF;
}

void output(char x){
  volatile char *out = (char *)0x10B;
  *out = x;
}
