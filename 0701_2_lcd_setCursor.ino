#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); // 검색된 I2C주소와 lcd의 열, 행

void setup() {
  lcd.init(); // lcd 사용 시작
  lcd.backlight();
  /*
  lcd.setCursor(0,0);
  lcd.print("Hello World!");
  */
}

void loop() {
  /*
  lcd.setCursor(0,2);
  lcd.print(millis()/1000); // 1초마다 초로 출력해보기!
  */

  // 1. 커서를 깜빡거리기
  lcd.setCursor(0,0);
  lcd.print("Cursor blink");
  lcd.blink(); // 커서를 깜빡거리게 하는 함수
  delay(2000);
  // 2. 커서를 깜빡거리지 않게 하기
  lcd.clear(); // lcd 내용 지우기
  lcd.noBlink(); // 커서를 깜빡거리지 않게 하는 함수
  lcd.print("Cursor noblink");
  delay(2000);
  // 3. lcd 내용을 보이지 않게 하기
  lcd.clear();
  lcd.print("Display off");
  delay(1000);
  lcd.noDisplay(); // lcd display 보이지 않게 하는 함수
  // 4. lcd 내용 보이게 하기
  lcd.clear();
  delay(2000);
  lcd.print("Display on");
  lcd.display();  // lcd display 보이게 하는 함수
  delay(2000);
  lcd.clear();
}
