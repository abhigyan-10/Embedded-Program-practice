//sw1 -> sw4 -> sw7 -> 8th led glows
void setup() {

  volatile char *dirA, *dirB;
  dirA = 0x21;
  *dirA = 0xFF;

  dirB = 0x24;
  *dirB = 0x00;

  volatile unsigned char *outA, *inB, x;
  volatile unsigned char state = 0;
  volatile unsigned char seq[3] ={(1<<0),(1<<3),(1<<6)};
  outA = 0x22;
  inB  = 0x23;

  volatile long i;

  while(1){

    x = *inB;

    if(x == seq[state]){

      for(i=0;i<20000;i++);
      state++;

      if(state == 3){

        *outA = (1<<7);

        for(i=0;i<300000;i++);

        *outA = 0;

        state = 0;
      }
    }
    else if(x!=0 && x!=seq[state-1]){
      state = 0;
    }
}
}

//this switch case code does the same thing but it's lenghtier than the above code

    // switch(state){

    //   case 0:

    //   if(x  == (1<<0))   // SW1
    //   {
    //     for(i=0;i<20000;i++);
    //     state = 1;
    //   }

    //   break;

    //   case 1:

    //   if(x == (1<<3))   // SW4
    //   {
    //     for(i=0;i<20000;i++);
    //     state = 2;
    //   }
    //   else if(x != 0 && x != (1<<0))
    //   {
    //     state = 0;
    //   }

    //   break;

    //   case 2:

    //   if(x == (1<<6))   // SW7
    //   {
    //     for(i=0;i<20000;i++);

    //     *outA = (1<<7);

    //     for(i=0;i<300000;i++);

    //     *outA = 0x00;

    //     state = 0;
    //   }
    //   else if(x != 0 && x != (1<<3))
    //   {
    //     state = 0;
    //   }

    //   break;
    // }
  
