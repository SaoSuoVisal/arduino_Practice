#define input A0

const float T0 = 298.15;
const float R0 = 100000; // Resistor Value
const float belta = 3950;
const float r = 10000;
float value;
float R, vol, T, cels, feh;

void setup() {
  Serial.begin(9600);
}

void loop() {
  value = analogRead(input);
  vol = (value * 5) / 1023; 
  R = (r * (5 - vol)) / vol;
  T = (T0 * belta) / (belta + (T * log(R/R0))); //T = kelvin
  
  //K = °C + 273.15
  cels = T - 273.15;
  
  //T(°F) = T(K) × 9/5 - 459.67
  feh = T * (9/5) - 459.67;

  Serial.print("Temperature: ");
  Serial.print(T);
  Serial.println(" Kelvin");

  Serial.print("Temperature: ");
  Serial.print(feh);
  Serial.println(" Fahrenheit");
  
  Serial.print("Temperature: ");
  Serial.print(cels);
  Serial.println(" Celsius");
  Serial.println();

  delay(500);
}
