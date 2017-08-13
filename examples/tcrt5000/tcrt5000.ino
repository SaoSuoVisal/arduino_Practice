int counter = 0; 
int tcrtValue;

void setup() {
  Serial.begin(9600);
}

void loop() {
  tcrtValue = analogRead(A0);
  Serial.println(tcrtValue);
  if(630 < tcrtValue) ++counter;
  if(counter % 10 == 0){
   Serial.print("Counter ");
   Serial.println(counter);
   Serial.println("The color is black");
  }
  delay(1000);
}
