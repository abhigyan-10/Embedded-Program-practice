//displaying 0.000 to 999.9 by multiplexing 4 seven segment displays in common anode 
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
#define D4 (B|C|F|G)
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
  *dirB = 0x0F;

}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char *outA = (char *)0x22;
  volatile char *outB = (char *)0x25;
  volatile long count=0, val;
  volatile char one, ten, hun, thou,c=0;
  volatile long x;
  while(1){
    // if(count <= 9999)
    count++;
    if(count > 9999){
      count = count/10;
      c++;
    }

    one = count % 10;
    ten = (count /10) %10;
    hun = (count /100) %10;
    thou = count / 1000;
    for(char r=0; r<100; r++){

      *outB = 0x00;
      if(c==2)
        *outA = ~(digit[ten] | DP);
      else 
        *outA = ~digit[ten];
      *outB = 0x04;
      for(x=0;x<100;x++); 

      *outB = 0x00;
      if(c==1)
        *outA = ~(digit[hun] | DP);
      else
        *outA = ~digit[hun];
      *outB = 0x02;
      for(x=0;x<100;x++);

      *outB = 0x00;
      if(c==0)
        *outA = ~(digit[thou] |DP);
      else 
        *outA = ~(digit[thou]);
      *outB = 0x01;
      for(x=0;x<100;x++);

      *outB = 0x00;
      *outA = ~(digit[one]);
      *outB = 0x08;
      for(x=0;x<100;x++);

      
    }
    
    if(c>2)
      break;

  }
}
