#include <IRLibAll.h>
IRrecv myReceiver(2);
IRdecode myDecoder; 
byte LED = 8; 

void setup() {
  myReceiver.enableIRIn(); // star the receiver
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  if(myReceiver.getResults()){
    myDecoder.decode();
    if(myDecoder.protocolNum == NEC){
      Serial.println(myDecoder.value);
        if(myDecoder.value == 0x40BF8877){ // off
            Serial.println("LOW");
            digitalWrite(LED, LOW);
        } else if (myDecoder.value == 0x40BFB04F) { // on
          Serial.println("HIGH");
          digitalWrite(LED, HIGH);
        }
        myReceiver.enableIRIn();
    }
  }
}
