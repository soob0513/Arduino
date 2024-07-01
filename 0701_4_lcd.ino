// 수신한 문자가 6이라면 오른쪽으로 스크롤
// 수신한 문자가 4라면 왼쪽으로 스크롤
// 수신한 문자가 2라면 화면을 지우고 (0, 1)로 이동해서 "Hello IoT" 출력
// 수신한 문자가 8이라면 화면을 지우고 (0, 0)로 이동해서 "Hello IoT" 출력
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); // 검색된 I2C주소와 lcd의 열, 행

const char data[] = "Hello World";
const int textSize = sizeof(data)-1;
const byte arrow = B01111110;  // → 특수문자 사용하기

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  lcd.print(data);
  lcd.write(arrow);
}

void loop() {
  if(Serial.available()){
    lcd.setCursor(0,0);
    while(Serial.available()>0){
      char c = Serial.read();
      if (c == '6'){
        for(int pos = 0; pos < textSize; pos++){
          lcd.scrollDisplayLeft();
        }
      }else if(c == '4'){
        for(int pos = 0; pos < textSize; pos++){
          lcd.scrollDisplayRight();
        }
      }else if(c == '2'){
        lcd.clear();
        lcd.setCursor(0,1);
        lcd.print("Hello IoT");
      }else if(c == '8'){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Hello IoT");
      }
    }  
  }
}
