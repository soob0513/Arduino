// 스탠드 LDW
int cnt = 0;
int btn1 = 0;
int btn2 = 0;

void loop() {
  int btn1 = digitalRead(2);
  if (btn1 != btn2){
    if (btn1 == 1){
      cnt++;
      if (cnt > 2){
        cnt = 0;
      }
    }
    btn1 = btn2 ; // 초기화
  }
  if (cnt == 0){
    analogWrite(10,0); 
  }else if (cnt == 1){
    analogWrite(10, 100);
  }else if(cnt == 2){
    analogWrite(10, 255);
  }
}