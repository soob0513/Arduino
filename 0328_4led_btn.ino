// LED 버튼으로 강중약
void setup() {
  pinMode(2, INPUT);
  pinMode(5, INPUT);
  pinMode(7, INPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  if (digitalRead(2) == 1){
    analogWrite(10, 0);
  }
  if (digitalRead(5) == 1){
    analogWrite(10, 100);
  }
  if (digitalRead(7) == 1){
    analogWrite(10, 255);
  }

// 두번째 방법!
 int btn1 = digitalRead(2);
 int btn2 = digitalRead(5);
 int btn3 = digitalRead(7);


}
