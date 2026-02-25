void output(char x);
void output1(char x);
void init(void);

void init(void){
  volatile char *PORTA_dir = (char *)0X21;
  *PORTA_dir = 0xFF;
  volatile char *PORTB_dir = (char *)0x24;
  *PORTB_dir = 0xFF;
}

void output(char x){
  volatile char *output = (char *)0X22;
  *output = x;
}

void output1(char x){
  volatile char *output = (char *)0x25;
  *output = x;
}
