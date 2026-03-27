//sw1->sw2->sw3->sw4 to turn on Led8
//sw5->sw6->sw7->sw8 to turn the led off

void setup() {

  volatile char *dirA, *dirB;
  dirA = 0x21;
  *dirA = 0xFF;

  dirB = 0x24;
  *dirB = 0x00;

  volatile unsigned char *outA, *inB, x,l=0;
  volatile unsigned char state = 0;
  volatile unsigned char seq1[4] ={(1<<0),(1<<1),(1<<2),(1<<3)};
  volatile unsigned char seq2[4] ={(1<<4),(1<<3),(1<<5),(1<<6)};
  outA = 0x22;
  inB  = 0x23;

  volatile long i;

  while(1){

    x = *inB;
    if(l==0){

      if(x == seq1[state]){

        for(i=0;i<20000;i++);
        state++;

        if(state == 4){

          *outA = (1<<7);
          l=1;
          state = 0;
        }
      }
      else if(x!=0 && (state == 0 || x != seq1[state-1])){
        state = 0;
      }
    }
    if(l==1){
      if(x == seq2[state]){

        for(i=0;i<20000;i++);
        state++;

        if(state == 4){

          *outA = 0;
          l=0;
          state = 0;
        }
      }
      else if(x!=0 && (state == 0 || x != seq2[state-1])){
        state = 0;
      }
    }

}
}

  }
}
