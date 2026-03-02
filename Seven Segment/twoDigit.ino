//all two digit nos from 00 to 99 using 2 seven segment display in common anode method
#define A (1<<0)
#define B (1<<1)
#define C (1<<2)
#define D (1<<3)
#define E (1<<4)
#define F (1<<5)
#define G (1<<6)
#define DP (1<<7)

#define D0 (A|B|C|D|E|F) //0X30
#define D1 (B|C)         //0X06
#define D2 (A|B|G|E|D)   //0X5B
#define D3 (A|B|G|C|D)   //0X4F
#define D4 (F|G|B|C)     //0X55
#define D5 (A|F|G|C|D)   //0X5D
#define D6 (A|F|G|C|D|E) //0X7D
#define D7 (A|B|C)       //0X07
#define D8 (A|B|C|D|E|F|G) //0X7F
#define D9 (A|B|C|F|G)    //0X57

char digit[10] = {D0,D1,D2,D3,D4,D5,D6,D7,D8,D9};
void setup() {
  // put your setup code here, to run once:
  volatile char *dirA = (char *)0x21;
  *dirA = 0xFF;
  volatile char *dirB = (char *)0x24;
  *dirB = 0xFF;
  volatile char *d = (char *)0x30;
  *d = 0x03;

}

void loop() {
  // put your main code here, to run repeatedly:
  char *outA = (char *)0x22; 
  char *outB = (char *)0x25;
  char *o = (char *)0x31;
  *o = 0x03;
  char i,j,c=0;
  volatile long x;
  for(i=0;i<10;i++){
    *outA = ~(digit[i]);
    for(j=0;j<10;j++){
      *outB = ~(digit[j]);
      for(x=0;x<500000;x++);
    }
  }
}
