int photoPinD = 2;
int photoPinA = A0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int lightD = digitalRead(photoPinD);
  int lightA = analogRead(photoPinA);
  Serial.print("Digital Reading: ");
  Serial.println(lightD);
  Serial.print("Analog Reading: ");
  Serial.println(lightA);
  delay(100);
}
