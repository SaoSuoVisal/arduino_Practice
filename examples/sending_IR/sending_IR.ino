#include <IRLibAll.h>

IRsend mySender;
void setup() {
  Serial.begin(9600);
}
//https://learn.adafruit.com/using-an-infrared-library/hardware-needed
void loop() {
  if (Serial.read() != -1) {
    //send a code every time a character is received from the serial port
    //Sony DVD power A8BCA
    //mySender.send(protocols, data, number of bits);
//    Serial.println(Serial.readString());
//    if(Serial.readString() == "f"){
//      Serial.println("OFF");
       //mySender.send(NEC,0x40BF8877, 32); //0x40BF8877
//    } 
//    if(Serial.readString() == "o"){
//      Serial.println("On");
      mySender.send(NEC,0x40BF8877, 32); //on 0x40BFB04F
      //mySender.send(RC6, 0xA55, 36);
//    }
  }
}
