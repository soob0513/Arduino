// 스탠드(실패)
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
  pinMode(5, INPUT);
  pinMode(7, INPUT);
  
}
void loop()
{
  int btn1 = digitalRead(2);
  int btn2 = digitalRead(5);
  int btn3 = digitalRead(7);
  
  if (analogWrite(13, 0)){
    if(btn1 == 1){
    analogWrite(13,100);
    }
  }
  if (analogWrite(13, 100)){
    if(btn1 == 1){
    analogwrite(13,255);
    }
  }if (analogWrite(13, 255)){
    if(btn1 == 1){
    analogWrite(13,0);
    }
  }
}

// 오류 --> analogWrite(13,0)이 불리언 타입이 아님!!
-----------------------------------------------------------
void loop()
{
  int btn1 = digitalRead(2);
  int btn2 = digitalRead(5);
  int btn3 = digitalRead(7);
  
  if (analogRead(13) == 0){
    if(btn1 == 1){
    analogWrite(13,100);
    }
  }
  if (analogRead(13) == 100){
    if(btn1 == 1){
    analogWrite(13,255);
    }
  }if (analogRead(13) == 255){
    if(btn1 == 1){
    analogWrite(13,0);
    }

// 오류는 안나는데 실행이 안됨
// ------------------------------------------------------
void loop() {
  int btn1 = digitalRead(2);
  int num = 1;

  if ((num%3 == 1) & (btn1 == 1)){
    analogWrite(10,100);
    num+= 1;

  }else if ((num%3 == 2) & (btn1 == 1)){
    analogWrite(10, 255);
    num+= 1;
  }else if ((num% 3 == 0) & (btn1 == 1)){
    analogWrite(10,0);
    num+= 1;
  }
  Serial.println(num);
}

}