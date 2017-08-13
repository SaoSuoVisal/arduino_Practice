int pulseData = 1;
int led = 9;
int signalData;
int Threshold = 550;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  signalData = analogRead(pulseData);
  Serial.println(signalData);

  if (signalData > Threshold) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  delay(10);
}

