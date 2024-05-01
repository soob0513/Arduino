// 색깔이 바뀌는 조명
void setup() {
  pinMode(A0, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int btn1 = digitalRead(5);
  int btn2 = digitalRead(6);
  int btn3 = digitalRead(7);
  int sensorValue = analogRead(A0);
  int mapValue = map(sensorValue, 0, 1023, 0, 255);

  if (btn1 == 1){
    analogWrite(11, mapValue);
  }else if(btn2 == 1){
    analogWrite(10, mapValue);
  }else if(btn3 ==1){
    analogWrite(9, mapValue);
  }
}