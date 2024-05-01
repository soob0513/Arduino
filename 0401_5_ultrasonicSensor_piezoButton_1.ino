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

  int duration = pulseIn(3, 1);
  duration = duration / 2;
  int distance = duration / 29.1;
  
  Serial.println(distance);
  delay(100);
  
  if (0 <= distance <= 10){
    tone(9, 330);
    delay(100);
    noTone(9);
    tone(9, 330);
    delay(100);
    noTone(9);
    tone(9, 330);
    delay(100);
    noTone(9);
    tone(9, 330);
    delay(100);
    noTone(9);
    tone(9, 330);
    delay(100);
    noTone(9);
    
  }else {
    tone(9, 330);
    delay(2000);
    noTone(9);
    tone(9, 330);
    delay(2000);
    noTone(9);
    tone(9, 330);
    delay(2000);
    noTone(9);
  }

}
