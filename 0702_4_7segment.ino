// 7 세그먼트
#include <TM1637Display.h>
#define CLK 3
#define DIO 2

TM1637Display display(CLK, DIO); 

void setup() {
  display.setBrightness(0x0f);  // 최대 밝기로 세그먼트 디스플레이 설정
}

void loop() {
  int number = 1234;  
  // display.showNumberDecEx(number,0x40);
  display.showNumberDecEx(number,0x40,true,4,0);  // 12:34 로 보여지도록 하는 함수
  delay(1000);
}
