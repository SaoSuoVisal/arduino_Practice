int lame[]= {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
void setup() {
  for(byte i = 2; i < 9; i++){
    pinMode(i, OUTPUT);
  }
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  int digit1 = 18/10;
  int digit2 = 18%10;
  for(byte i = 0; i < 99; i++){
    showNum(digit1, 0, 1);
    showNum(digit2, 1, 0);
  } 
}


