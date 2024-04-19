void setup() {
  // put your setup code here, to run once:
  pinMode(10,OUTPUT);
}

void loop() {
  // 점점 밝아지게
  for (int i = 0; i <= 255; i++){
    analogWrite(10,i);
    delay(10);
  }

  // 점점 어두워지게 1
  for (int i = 255; i >= 0; i--){
    analogWrite(10,i);
    delay(10);
  }
    // 점점 어두워지게 2
    for (int i = 0; i <= 0; i ++){
    analogWrite(10, 255-i);
    delay(10);
  }
}