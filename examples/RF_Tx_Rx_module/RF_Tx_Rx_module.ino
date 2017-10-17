#include <RH_ASK.h>
#include <SPI.h>

RH_ASK mainChara;

void setup() {
  Serial.begin(9600);
  if(!mainChara.init()){
     Serial.println("Inital Failed:(");
  }
}

void loop() {
  char msg[100];
  String info = "Arrowdot!";
  info.toCharArray(msg, info.length()+1);
  
  mainChara.send(msg, strlen(msg));
  mainChara.waitPacketSent();
  
  Serial.println("Sent!");
  delay(1000);
}
