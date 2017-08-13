   // NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PINone            6
#define PINtwo            10
#define PINthree            12
#define PINfour            9

#define NUMPIXELS      16

Adafruit_NeoPixel PINsix = Adafruit_NeoPixel(NUMPIXELS, PINone, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel PINten = Adafruit_NeoPixel(NUMPIXELS, PINtwo, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel PINeleven = Adafruit_NeoPixel(NUMPIXELS, PINthree, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel PINnine = Adafruit_NeoPixel(NUMPIXELS, PINfour, NEO_GRB + NEO_KHZ800);

int delayval = 20;

void setup() {
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  PINsix.begin(); 
  PINten.begin();
  PINeleven.begin();
  PINnine.begin();
}

void loop() {
  for(int i=0;i<NUMPIXELS;i++){
    //RED
  PINsix.setPixelColor(i, PINsix.Color(150,150        ,0)); 
    PINsix.show();
    //BLUE
    PINten.setPixelColor(i, PINten.Color(0,0,150)); 
    PINten.show();
    //GREEN
    PINeleven.setPixelColor(i, PINeleven.Color(0,150,0)); 
    PINeleven.show();
    //YELLOW
    PINnine.setPixelColor(i, PINnine.Color(150,150,0)); 
    PINnine.show();
    
    delay(delayval);
  }
  
}
