/* [LCD 설명]
  vss gnd연결 (-)
  vdd 전원연결 (+)
  vo 가변저항을 색상 대비조정 (명암)
  RS 명령/데이터 레지스터 선택
  RW 읽기/쓰기 선택
  E LCD활성화신호
  DB0~DB7 데이터비트 0~7 (8비트에서는 모든 핀 사용) 
*/

/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 14, en = 12, d4 = 13, d5 = 5, d6 = 23, d7 = 19;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);   // 16열 2행
  // Print a message to the LCD.
  // lcd.print("hello, world!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print("Subin");
}

