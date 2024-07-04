// 마스터(ESP32)에서 슬레이브(아두이노)로 데이터를 전송
// ESP32에 연결하기 

// 조도센서 연결
#include <Wire.h>

const byte address = 0x04;

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  int val = analogRead(39); 
  Wire.beginTransmission(address);
  Serial.println(val);
  Wire.println(val);
  Wire.endTransmission();

  delay(1000);
}
