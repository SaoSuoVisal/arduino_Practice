#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(4);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  //display.setTextColor(WHITE);
  //display.setCursor(0,0);
  
  //display.setTextSize(10);
  //display.print("A");
  
  //display.display();
  //display.drawCircle(60, 30, 30, WHITE);
  
  //display.drawBitmap(32,16,fan, 64, 32, WHITE);
  delay(1000);
  display.setTextColor(WHITE);
  display.setCursor(0, 30);
  display.setTextSize(1.3);
  
  display.print("Hello, welcome to the");
  display.setCursor(20, 45);
  display.println("Inovation Lab!");
  display.display();
  delay(3000);
  
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(0, 35);
  display.setTextSize(1.3);
  display.print("Let's start!");
  display.display();
}

void loop() {

}

