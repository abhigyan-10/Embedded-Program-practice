// only Applicable for PORT K of ARDUINO MEGA 
void init();
void output(char x);

void init(){
  volatile char *PORT_dir = (char *)0x107;
  *PORT_dir = 0xFF;
}

void output(char x){
  volatile char *out = (char *)0x108;
  *out = x;
}
