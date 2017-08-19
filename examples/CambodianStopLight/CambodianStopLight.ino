const int din = 10;
const int clk = 11;
const int load = 12;

//First pannel
const int ledG1 = 2;
const int ledY1 = 3;
const int ledR1 = 4;

//Second pannel
const int ledG2 = 5;
const int ledY2 = 6;
const int ledR2 = 7;

void setup() {
  pinMode(din, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(load, OUTPUT);
  
  for(byte i = 2; i < 8; i++){
    pinMode(i, OUTPUT);
  }
  
  check(0x1C, 0x11); //Normal Operation
  check(0x19, 0x0F); // decode for 3-0
  check(0x1B, 0x13); // check the scan limit 0 1 2 3
  check(0x1A, 0x19); // intensity
}

void loop() {
  //First Panenel
    //RED light 30 seconds
    lame(20, 'R');
    //Green Light 35 seconds
    lame(15, 'G');
    //Yello Light 5 seconds
    lame(5, 'Y');
}
