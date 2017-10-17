#include <AIRremote.h>

IRsend irsend;

void setup()
{
}

void loop() {
   irsend.sendNEC(0x40BFB04F, 32); //off
   delay(5000);
}
