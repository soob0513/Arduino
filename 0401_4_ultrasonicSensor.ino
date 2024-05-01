// 초음파 센서
void setup() {
  pinMode(2, OUTPUT);    // trig -> 초음파를 쏘는 부분 (초음파 발생기) (액츄)
  pinMode(3, INPUT);     // echo -> 초음파를 받는 부분 (초음파 수신기) (센서)
  Serial.begin(9600);
}

void loop() {
  digitalWrite(2, 1);   // 초음파를 쏴라!
  delay(10);
  digitalWrite(2, 0);   // 초음파를 쏘지 마라!
  
  int duration = pulseIn(3, 1);      // 초음파를 받아올 때 걸리는 시간
  duration = duration / 2;          // 왕복이 아니라 편도만 구하려고
  int distance = duration / 29.1;  // 거리 = 속력 * 시간 => 사진 참고

  Serial.print("distance : ");
  Serial.print(distance);
  Serial.println("cm");
  delay(100);
}
