// 적외선센서 근처에 가면 선풍기가 돌도록, 아니면 돌지 않도록 만들어보기
void setup() {
  pinMode(8, INPUT);  // 적외선센서
  pinMode(9, OUTPUT); // DC 모터
  Serial.begin(9600);
}

void loop() {
  int val = digitalRead(8);
  Serial.println(val);
  if (val == 1){
    analogWrite(9,255);
  }else {
    analogWrite(9,0);
  }
}
