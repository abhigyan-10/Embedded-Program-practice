// here the 5th led will glow after 1st switch and 7th switch are placed one by one.....anything in between will be ignored
void setup() {
  // put your setup code here, to run once:
  volatile char *dirA, *dirB;
  dirA = 0x21;
  *dirA = 0xFF;
  dirB = 0x24;
  *dirB =0x00;
  volatile unsigned char *outA, *inB , x,state =0;;
  outA = 0x22;
  inB = 0x23;
  volatile long i;
  while(1){
    x = *inB;

    switch(state){
      case 0:
      if((x & (1<<0))==(1<<0)){
        for(i=0;i<20000;i++);
        state = 1;
      }
      break;

      case 1:
      if((x & (1<<6))==(1<<6)){
        for(i=0;i<20000;i++);
        *outA = (1<<4);
        for(i=0;i<300000;i++);
        *outA = 0x00;
        state = 0;
      }
      else if(x & ~(1<<6))              // other switch pressed
      {
        state = 0;
      }
      break;
    }
    
  }
}
