// 1. 글자가 지나가게 하기 (scrollDisplay)
// 2. lcd에 시리얼통신 수신결과 쓰기

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); // 검색된 I2C주소와 lcd의 열, 행
/* 1. scrollDisplay
const char data[] = "Hello World";
const int textSize = sizeof(data)-1;
*/ 
void setup() {
  lcd.init(); // lcd 사용 시작
  lcd.backlight();
  Serial.begin(9600);
  // lcd.print(data);
}

void loop() {
  /* 1. scrollDisplay
  for(int pos = 0; pos < textSize; pos++){
    lcd.scrollDisplayLeft(); // lcd 왼쪽으로 스크롤
    // lcd 오른쪽으로 스크롤 -> scrollDisplayRight()
    delay(200);
  }
  */
  // 2. lcd에 시리얼 통신 수신결과 쓰기
  if(Serial.available()){
    lcd.setCursor(0,0);
    lcd.clear();
    while(Serial.available()>0){
      char c = Serial.read();
      lcd.print(c);  // lcd에 시리얼 통신 수신결과 쓰기
      // lcd.write(Serial.read());
    }
  }
}
