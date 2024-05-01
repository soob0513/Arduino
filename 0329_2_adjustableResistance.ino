// 가변저항으로 밝기 조절
void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);   // 0~1023
  Serial.println(sensorValue);
  
  //analogWrite(10, sensorValue/4);

  // int num = (sensorValue/1023)/255;
  // analogWrite(10, num);
  // -> 작동 이상함. map() 함수 사용하기.
  int mapValue = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(10,mapValue);
}
