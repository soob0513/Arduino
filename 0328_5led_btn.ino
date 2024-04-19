// 버튼 하나로 LED 밝기 제어
void setup() {
  pinMode(2, INPUT);
  pinMode(5, INPUT);
  pinMode(7, INPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  int btn1 = digitalRead(2);

  /*
  if (btn1.count() == 1){
    analogWrite(10, 100);
  }else if (btn1.count() == 2){
    analogWrite(10, 255);
  }else if (btn1.count() == 3){
    analogWrite(10,0);
  }
  // Compilation error: request for member 'count' in 'btn1', which is of non-class type 'int'
  */

}