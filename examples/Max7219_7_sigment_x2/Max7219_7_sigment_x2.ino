const int din = 7;
const int clk = 6;
const int load = 5; 
const int LED = 8; 

void setup() {
  pinMode(din, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(load, OUTPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  
  check(0x0C, 0x01); //shoutdown mode 0x01 = 1 || 0x00 = 0
  check(0x09, 0x0F); //decode mode
  check(0x0B, 0x02); //scan limmit from 0 to 1
  check(0x0A, 0x00); //intensity MAX7219 25/32  
}

void loop() {
  for(int i = 0; i < 200; i++){
    int D1 = i / 10;
    int D2 = i % 10;
    
    if( i < 100){
      digitalWrite(LED, LOW);
      check(1, D1); // first digit
      check(2, D2); // second digit
    }
    if(i > 99){
      D1 -= 10;
      digitalWrite(LED, HIGH);
      check(1, D1); // first digit
      check(2, D2); // second digit
    }
    delay(100);
  }
}

