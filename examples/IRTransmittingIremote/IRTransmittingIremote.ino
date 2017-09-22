/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */


#include <AIRremote.h>

IRsend irsend;

void setup()
{
  Serial.begin(9600);
  pinMode(13, INPUT);
}

void loop() {
  if(digitalRead(13) == HIGH){
    Serial.println("Yes, values!");
    irsend.sendNEC(0x40BFB04F, 32);
  }
  delay(500);
//	irsend.sendNEC(0x40BF8877, 32);
//	delay(5000); //5 second delay between each signal burst
// 
//  irsend.sendNEC(0x40BFB04F, 32);
//  delay(5000); //5 second delay between each signal burst
//
//  irsend.sendNEC(0x40BF906F, 32);
//  delay(5000); //5 second delay between each signal burst
//
//  irsend.sendNEC(0x40BFA857, 32);
//  delay(5000); //5 second delay between each signal burst
//
//  irsend.sendNEC(0x40BFA05F, 32);
//  delay(5000); //5 second delay between each signal burst
}
