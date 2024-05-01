// 초음파센서와 피에조 버튼
void setup() {
  pinMode(2, OUTPUT);    // trig -> 초음파를 쏘는 부분 (초음파 발생기) (액츄)
  pinMode(3, INPUT);     // echo -> 초음파를 받는 부분 (초음파 수신기) (센서)
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(2,1);
  delay(10);
  digitalWrite(2,0);

  // 현재 echo핀의 상태는 0(low)상태
  // echo핀이 1(HIGH)상태가 될 때까지 걸리는 시간을 측정하는 함수!
  // -> pulseIn()
  int duration = pulseIn(echo, 1);
  duration = duration / 2;  // 왕복시간이기 때문에 2로 나눠줌
  int distance = duration / 29.1;  // 29.1 : HC-SR04 보정 값
  Serial.println(distance);
  if (distance >5 && distance <50){
    tone(9,330);
    delay(500);
    noTone(9);
    delay(500);
  }
  else if (distance <= 5){
    tone(9,330);
    delay(50);
    noTone(9);
    delay(50);
  }
  else{
    noTone(9);
  }
}
