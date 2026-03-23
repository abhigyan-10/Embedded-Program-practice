//sw1->sw4->sw7->sw8 to turn on Led5
//sw4->sw7->sw8->sw1 to turn the led off

void setup() {

  volatile char *dirA, *dirB;
  dirA = 0x21;
  *dirA = 0xFF;

  dirB = 0x24;
  *dirB = 0x00;

  volatile unsigned char *outA, *inB, x,l=0;
  volatile unsigned char state = 0;
  volatile unsigned char seq_on[4] ={(1<<0),(1<<3),(1<<6),(1<<7)};
  volatile unsigned char seq_off[4] ={(1<<3),(1<<6),(1<<0),(1<<7)};
  outA = 0x22;
  inB  = 0x23;
  volatile long i;

  while(1){
    switch(l)
    {
      case 0:
        x = *inB;
        if(x == seq_on[state]){

          for(i=0;i<20000;i++);
          state++;
          while(*inB == x);

          if(state == 4){
            *outA = (1<<4);
            l=1;
            for(i=0;i<300000;i++);
            state = 0;
            while(*inB != 0);   
          }
        }
        else if(x!=0 && state>0 && x!=seq_on[state-1]){
          state = 0;
        }
        break;

      case 1:
        x = *inB;
        if(x == seq_off[state]){

          for(i=0;i<20000;i++);
          state++;
          while(*inB == x);

          if(state == 4){
            *outA = 0;
            l=0;
            state = 0;
            while(*inB != 0);   
          }
        }
        else if(x!=0 && state >0 && x!=seq_off[state-1]){
          state = 0;
        }
        break;
    }
  }
}
