void showNum (int number, boolean pin11, byte pin13){
  digitalWrite(11, pin11);
  digitalWrite(13, pin13);
  for(byte i = 2; i < 9; i++){
    digitalWrite(i, bitRead(lame[number], i-2));
  }
  delay(10);
}

