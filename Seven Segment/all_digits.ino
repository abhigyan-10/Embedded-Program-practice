// display digits from 0-9 in common anode mode
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

}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *out = (char *)0x22;
  volatile char i;
  volatile long x;
  for(i=0;i<10;i++){
    *out = ~(digit[i]);
    for(x=0;x<1000000;x++);
  }
}
