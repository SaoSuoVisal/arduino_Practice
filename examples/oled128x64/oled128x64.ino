#include <Wire.h>

#include <SPI.h>

#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 oled(LED_BUILTIN);

void setup(){
  oled.begin(0x3c);
  oled.clearDisplay();
}
void loop(){
  oled.drawCircle(0, 0, 5, WHITE);
  oled.display();
}
