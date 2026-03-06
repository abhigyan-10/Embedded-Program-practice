// 0th button glow 0th led.....1st button glow 1st led....and so on
void setup() {
  // put your setup code here, to run once:
  volatile char *dirA, *dirB;
  dirA = 0x21;
  *dirA = 0xFF;
  dirB = 0x24;
  *dirB = 0x00;
  volatile char *outA, *inB,x,a=0;
  outA = 0x22;
  inB = 0x23;
  char led[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
  volatile long i;
  while(1){
    x = *inB;
    *outA = 0x00;
    
    for(a=0;a<8;a++){
      if((x & led[a]) == led[a]){
          *outA = led[a];
        for(i=0;i<50000;i++);
      }
    }
  }
}
