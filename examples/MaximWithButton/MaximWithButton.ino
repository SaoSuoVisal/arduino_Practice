const int din = 8;
const int clk = 10;
const int load = 9; 
const int pullDown = 7;
const int pullUp = 6; 

int counter = 0; 
byte signDown = 0;
byte signUp = 0;
byte on = 0;

void setup() {
  pinMode(din, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(load, OUTPUT);

  Serial.begin(9600);
  pinMode(pullDown, INPUT);
  pinMode(pullUp, INPUT);
  check(0x0C,0x00); //shoutdown mode 0x01 = 1 || 0x00 = 0
}

void loop() {  
  if(digitalRead(pullDown) == 1 && digitalRead(pullUp) == 0){
    on = 1;
    counter = 0;
    check(0x0C, 0x01); //shoutdown mode 0x01 = 1 || 0x00 = 0
    check(0x09, 0xFF); //decode mode
    check(0x0B, 0x07); //scan limmit from 0 to 1
    check(0x0A, 0x0f); //intensity MAX7219 25/32
    
    delay(500);
  }
  
  if(on == 1){
   
    if(digitalRead(pullDown) == 1 && on == 1){
      signDown = 1;
    }
      
    if(digitalRead(pullDown) == 0 && signDown == 1){
      counter++;
      signDown = 0;
    }
    if(digitalRead(pullUp) == 0 && on == 1){
      signUp = 1;
    }
      
    if(digitalRead(pullUp) == 1 && signUp == 1){
      counter--;
      signUp = 0;
    }
  
    if(counter < 0 ){
      counter = 0;
    }
    
    byte d1 = counter / 10000000;
    byte d2 = (counter / 1000000) % 10;
    byte d3 = (counter / 100000) % 10;
    byte d4 = (counter / 10000) % 10;
  
    byte d5 = (counter / 1000) % 10;
    byte d6 = (counter / 100) % 10;
    byte d7 = (counter / 10) % 10;
    byte d8 = counter % 10;
    
    check(1, d8);
    check(2, d7);
    check(3, d6);
    check(4, d5);
  
    check(5, d4);
    check(6, d3);
    check(7, d2);
    check(8, d1);
  }
}
