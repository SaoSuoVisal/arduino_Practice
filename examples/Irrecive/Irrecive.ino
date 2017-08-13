#include <IRremote.h>

int irNumber = 0;
IRrecv irrecv(irNumber);
decode_results result;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&result)){
    Serial.println(result.value, HEX);
    delay(10);
    irrecv.resume();
  }
}
