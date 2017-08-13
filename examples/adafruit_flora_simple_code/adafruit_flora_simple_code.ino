#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define neo 6
#define numpixels 16

Adafruit_NeoPixel pixels = Adafruit_NeoPixel (numpixels, neo, NEO_GRB + NEO_KHZ800);
int delayval = 500;

void setup() {
#if defined (__AVR_ATtiny85__)
  if(F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
pixels.begin();
}

void loop() {
  for(int i = 0; i < numpixels; i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0)); //RGB
    pixels.show();
    delay(delayval);
  }

}
