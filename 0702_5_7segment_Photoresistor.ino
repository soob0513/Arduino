// 7 세그먼트 + 온도센서(or 조도센서;Photoresistor)
#include <TM1637Display.h>
#define CLK 3
#define DIO 2

TM1637Display display(CLK, DIO); 

void setup() {
  display.setBrightness(0x0f);  // 최대 밝기로 세그먼트 디스플레이 설정
}

void loop() {
  int sensorValue = analogRead(A0);
  // 조도센서 연결했을 때
  display.showNumberDec(sensorValue);

  /* 온도센서 연결했을 때! 
  float voltage = sensorValue / 1024.0 * 5.0; 
  int temp = round((volatage - 0.5) * 100); // round() : 반올림 함수
  display.showNumberDec(temp);
  */
  delay(2000);
}
