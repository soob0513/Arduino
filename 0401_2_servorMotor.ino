#include <Servo.h>   // 라이브러리 불러오기
Servo myservo;       // 변수 지정
void setup() {
  myservo.attach(8);
}

void loop() {
  // 각도가 0~120도까지 서서히 바뀌도록 만들어보자!
  // myservo.write(10);
  // delay(1000);
  // myservo.write(120);
  // delay(1000);

  for (int angle = 0; angle <=120; angle+=5){
    myservo.write(angle);
    delay(1000);
  }
  for (int angle = 120; angle >= 0; angle-=5){
    myservo.write(angle);
    delay(1000);
  }
}
