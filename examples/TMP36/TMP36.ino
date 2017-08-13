const int temper = A0;
int sensor = 0;
int degreesC = 0;
void setup() {
  pinMode(temper, INPUT);
  Serial.begin(9600);
}

void loop() {
  sensor = analogRead(temper);
  degreesC = (sensor - 0.5) * 100.0;
  Serial.print("temperature value: ");
  Serial.println(sensor);
  delay(2);
}
