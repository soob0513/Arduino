void setup() {
  pinMode(10, OUTPUT);
}

void loop() {
  analogWrite(10, 0);
  delay(1000);
  analogWrite(10, 30);
  delay(1000);
  analogWrite(10, 130);
  delay(1000);
  analogWrite(10, 255);
  delay(1000);
}