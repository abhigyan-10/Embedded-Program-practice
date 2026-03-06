//press any buttons make the leds glow 0 to 7 one by one
void setup() {
  // put your setup code here, to run once:
  volatile unsigned char *dirA, *dirB;
  dirA = 0x21;
  *dirA = 0xFF;
  dirB = 0x24;
  *dirB = 0x00;
  volatile unsigned char *outA,*inB,x;
  outA = 0x22;
  inB = 0x23;
  short a=0;
  
  volatile long i;
  while(1){
    x = *inB;
    unsigned char led = 0x01;
    *outA = 0x00;
    if(x != 0x00){
      for(a=0;a<8;a++){
        *outA = led;
        for(i=0;i<300000;i++);
        led = led<<1;
      }
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly: 
}
