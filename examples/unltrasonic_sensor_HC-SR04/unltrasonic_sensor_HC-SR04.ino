const int trigPin = 2; // Sending signal
const int echoPin = 4; // Recieving signal
long duration, cm;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(100);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCm(duration);

  Serial.print(cm);
  Serial.println(" cm");
  delay(100);
}

long microsecondsToCm(long duration) {
  // can send 340 m/s CONVERT to cm/s
  // 29 microsecond/cm
  return duration / 58;
}
