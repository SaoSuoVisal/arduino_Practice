#define LDR A0

const float r = 1000; //number of pull down resister
float value;  // value from Light Direct Resister (LDR) 0 - 1023 
float Rldr, vol, Lux;


void setup() {
  Serial.begin(9600);
}

void loop() {

  /*Lux - light reading 
   * Formular: 
   *    Lux = 500/RLDR;
   *    
   * RLDR = resistance value of the LDR 
   * The top formular is for the normal photoResistor.
  */
  value = analogRead(LDR);
  vol = (value * 5)/ 1023; // "value" is the amount voltage in the LDR 
  Rldr = (r * (5 - vol)/ vol)/1000;
  Lux = 500 / Rldr;
  
  Serial.print("Lux = "); // String("Lux = ") + String(Lux)
  Serial.println(Lux);
  
  Serial.print("Value: ");
  Serial.println(value);
  delay(500);
}
