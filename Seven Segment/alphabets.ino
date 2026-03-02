//alphabets A-J
#define a (1<<0)
#define b (1<<1)
#define c (1<<2)
#define d (1<<3)
#define e (1<<4)
#define f (1<<5)
#define g (1<<6)
#define DP (1<<7)

#define A (a|b|c|g|e|f)
#define B (a|b|c|d|e|f|g)
#define C (a|f|e|d)
#define D (a|b|c|d|e|f)
#define E (a|d|e|f|g)
#define F (a|e|f|g)
#define G (a|c|d|e|f|g)
#define H (b|c|e|f|g)
#define I (b|c)
#define J (a|b|c|d|e)

char digit[10] = {A,B,C,D,E,F,G,H,I,J};
void setup() {
  // put your setup code here, to run once:
  volatile char *dir = (char *)0x21;
  *dir = 0xFF;
  volatile char *dir1 = (char *)0x30;
  *dir1 = 0x01;

}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *out = (char *)0x22;
  volatile char *o = (char *)0x31;
  *o = 0x01;
  volatile char i;
  volatile long x;
  for(i=0;i<10;i++){
      *out = ~(digit[i]);
    for(x=0;x<500000;x++);
  }
}
