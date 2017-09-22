#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 5, 6, 7, 8, 9);
int text[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', ' ', 'W', 'e', 'l', 'c', 'o', 'm', 'e', ' ', 't', 'o', ' ', 'P', 'h', 'n', 'o', 'm', ' ', 'P', 'e', 'n', 'h', '!'};

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  //  for(byte i = 0; i < 5; i++){
  //    lcd.scrollDisplayRight();
  //    delay(500);
  //  }
  //
  //  for(byte i = 5; i > 0; i--){
  //    lcd.scrollDisplayLeft();
  //    delay(500);
  //  }
  //  delay(5000);
  //  
  //  lcd.home();
  //  for (byte i = 0; i < 36; i++) {
  //
  //    lcd.leftToRight();
  //    lcd.write(text[i]);
  //
  //    lcd.cursor();
  //    lcd.blink();
  //
  //    delay(500);
  //  }
  //  lcd.clear();
  //  delay(1000);
  
  if(Serial.available() > 0){
    // int data = Serial.read(); // read the number
    // lcd.print(data - '0'); // because of Asciii table it will change to different table, so to solve that we need to substract by 0 (- "0")
    // lcd.write(data); // also another way that we display numbers

     String data = Serial.readString(); // read string
     
     lcd.print(data);
     Serial.println(data);
  }
}
