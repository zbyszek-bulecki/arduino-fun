void setup() {
  Serial.begin(115200);
}

void loop() {
  int light = analogRead(A0);
  float lightIntensity = map(light, 0 ,4095, 0, 100);
  Serial.println(lightIntensity);
  delay(100);
}
