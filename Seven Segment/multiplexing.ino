//00 to 99 by multiplexing them on Port A
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
  volatile char *dirA = (char *)0x21;
  *dirA = 0xFF;
  volatile char *dirB = (char *)0x24;
  *dirB = 0x03;

}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *outA = (char *)0x22;
  volatile char *outB = (char *)0x25;
  volatile char i,j;
  volatile long x;

  for(i=0; i<10; i++)
  {
    for(j=0; j<10; j++)
      {
        for(short r=0;r<200;r++) //repeat to display them after multiplexing
        {
        *outB = 0x00;              // Disable both digits
        *outA = ~(digit[i]);       // Digit 1
        *outB = 0x02;              // Enable digit 1
        for(x=0; x<1000; x++);

        *outB = 0x00;
        *outA = ~(digit[j]);       // Digit 2
        *outB = 0x01;              // Enable digit 2
        for(x=0; x<1000; x++);
        }
    }
  }
}
