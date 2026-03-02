//check and display one digit prime no
#define A (1<<0)
#define B (1<<1)
#define C (1<<2)
#define D (1<<3)
#define E (1<<4)
#define F (1<<5)
#define G (1<<6)
#define DP (1<<7)

#define D0 (A|B|C|D|E|F)
#define D1 (B|C)
#define D2 (A|B|G|E|D)
#define D3 (A|B|G|C|D)
#define D4 (F|G|B|C)
#define D5 (A|F|G|C|D)
#define D6 (A|F|G|C|D|E)
#define D7 (A|B|C)
#define D8 (A|B|C|D|E|F|G)
#define D9 (A|B|C|F|G)

char digit[10] = {D0,D1,D2,D3,D4,D5,D6,D7,D8,D9};
void setup() {
  // put your setup code here, to run once:
  volatile char *dir = (char *)0x21;
  *dir = 0xFF;
  volatile char *d = (char *)0x30;
  *d = 0x01;

}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *out = (char *)0x22;
  volatile char *o = (char *)0x31;
  *o = 0x01;
  volatile char i,j,c=0;
  volatile long x;
  for(i=2;i<10;i++){
    c=0;
      for(j=2;j*j<=i;j++){
        if(i%j==0){
          c=1;
          break;
        }
      }
      if(c==0){
        *out = ~(digit[i]);
        for(x=0;x<500000;x++);
      }
  }
}
