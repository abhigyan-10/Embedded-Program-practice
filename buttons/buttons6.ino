//7th button when pressed will glow led in the order 0->1->4->7 with delays in btwn
void setup() {

  volatile char *dirA, *dirB;
  dirA = 0x21;
  *dirA = 0xFF;

  dirB = 0x24;
  *dirB = 0x00;

  volatile unsigned char *outA, *inB,l,s;
  unsigned char x[4] = {(1<<0),(1<<1),(1<<3),(1<<7)};

  outA = 0x22;
  inB  = 0x23;

  volatile long i;

  while(1){
    
    if((*inB & (1<<7))==(1<<7)){
      for(l=0;l<4;l++){
        *outA = x[l];
        for(i=0;i<100000;i++);    
      }
      *outA = 0x00;
      while(*inB & (1<<7)); //to prevvent debounce
    }
    else  
      *outA = 0x00;
  }
}
