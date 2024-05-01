void setup() {
  Serial.begin(115200);
}

void loop() {
  int value = analogRead(2);
  Serial.println(value);
  delay(1000);
}
