#include <IRremote.h>
#include <Servo.h>
Servo lame;

int pos = 0;

int irNumber = 11; 
IRrecv irrecv(irNumber);
decode_results result;

void setup(){
  lame.attach(13);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop(){
  if(irrecv.decode(&result)){
    Serial.println(result.value, HEX); //DEC or HEX
    if(result.value == 0xDC123E){ //DC123E is OFF/ON button of the Fan
      for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        lame.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }
      for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        lame.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }
      Serial.println("ON");
    }else if(result.value == 0xDFE201){   //DFE201 is Speed of the fan button 
      lame.write(0);
    }else if(result.value == 0xDEE211){   //DEE211 is  OSCIL. of the fan button
      lame.write(180);
    }
    irrecv.resume();
  }
}
