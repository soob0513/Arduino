// 마스터(ESP32)에서 전송된 데이터를 슬레이브(아두이노)에서 출력
// Arduino Uno 보드 연결

// LCD + 조도센서
// 아두이노에 LCD 연결
// 조도센서 데이터의 값을 받아오기
#include <Wire.h>

const byte address = 0x04;

void setup() {

  Serial.begin(9600);
  // I2C 통신 초기화 (0을 보냄)
  Wire.begin(address);
  Wire.onReceive(receiveEvent);  
  
}

void loop() {
  delay(500);
}

void receiveEvent(int howMany){
  while(Wire.available()){
    char c = Wire.read();
    Serial.print(c);

  }
}