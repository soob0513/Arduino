// 밝기를 넘겨받아 LED 밝기 제어하기 
// 아두이노 보드에 ~표시 있는 곳에 꽂아야 함

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}

void loop() {
  if (Serial.available()){
    int val = Serial.read();
    analogWrite(9, val);
  }
}
