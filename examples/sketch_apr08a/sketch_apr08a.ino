#include <IRremote.h>

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
  if (irrecv.decode(&results))
    {
      /*
     if((results.value, HEX) == 'C0E8'){
      Serial.println('ON');
     }else{
      Serial.println('OFF');
     }*/
     Serial.println(results.value, HEX);
     irrecv.resume(); // Receive the next value
     
    }
}
