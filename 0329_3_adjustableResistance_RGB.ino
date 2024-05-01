// 가변저항으로 RGB LED 조절
// 선생님코드
void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue1 = analogRead(A0);  // 0~1023
  int sensorValue2 = analogRead(A1);
  int sensorValue3 = analogRead(A2);
  Serial.println(sensorValue3);

  int mapValue1 = map(sensorValue1, 0, 1023, 0, 255); //0~1023 -> 0~255
  int mapValue2 = map(sensorValue2, 0, 1023, 0, 255);
  int mapValue3 = map(sensorValue3, 0, 1023, 0, 255);

  analogWrite(9, mapValue1);
  analogWrite(10, mapValue2);
  analogWrite(11, mapValue3);
}