void setup() {
  // pwm 신호를 활용할 수 있음 -> 모터의 세기를 0~255
  pinMode(9, OUTPUT);
}

void loop() {
  /* 1. 모터 돌아가는지 확인
  analogWrite(9,255);
  delay(1000);
  analogWrite(9,0);
  delay(1000);
  */

  // 2. 0~255 서서히 속도를 올려보자!
  for (int i = 0; i <= 255; i+=10){
    analogWrite(9,i);
    delay(100);
  }
  for (int i = 255; i >= 0; i-=10){
    analogWrite(9,i);
    delay(100);
  }
  
}