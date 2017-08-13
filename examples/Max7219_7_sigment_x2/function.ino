void check(byte address, byte data){
  digitalWrite(load, LOW); //open the door
  for(int i = 7; i >= 0; i--){
    digitalWrite(din, bitRead(address, i));
    digitalWrite(clk, LOW);
    digitalWrite(clk, HIGH);
  }

  for(int i = 7; i >= 0; i--){
    digitalWrite(din, bitRead(data, i));
    digitalWrite(clk, LOW);
    digitalWrite(clk, HIGH);
  }
  digitalWrite(load, HIGH); // close the door
}
