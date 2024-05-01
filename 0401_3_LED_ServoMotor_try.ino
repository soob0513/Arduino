// LED 두 개와 Servo motor 시도
#include <Servo.h>   // 라이브러리 불러오기
Servo myservo;       // 변수 지정
void setup() {
  myservo.attach(8);
  pinMode(12, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}
int cnt = 0;
void loop() {
  // 버튼 누르면 서브모터 0도에서 LED 2개 하나씩 점등된 후 90도로 열리도록 만들기
  int btn = digitalRead(12);
  myservo.write(0);
  if (btn == 1){
    delay(200);
    digitalWrite(4, 1);
    delay(500);
    digitalWrite(4, 0);
    digitalWrite(3, 1);
    delay(500);
    digitalWrite(3, 0);
    
    cnt++;
    if (cnt == 1){
      myservo.write(90);
    }else if (cnt == 2){
      myservo.write(180);
    }else if (cnt == 3){
      myservo.write(270);
    }else if (cnt == 4){
      myservo.write(0);
      cnt = 0;
    }
    
  }