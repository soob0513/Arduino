// 마스터(ESP32)에서 슬레이브(아두이노)로 데이터를 전송
// ESP32에 연결하기 
// 이쪽 Serial Monitor에 입력하면

// LCD + 조도센서 
// ESP에 조도센서 연결
#include <Wire.h>

const byte address = 0x04;

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  if(Serial.available()){
    char c = Serial.read();

    Wire.beginTransmission(address);
    Serial.println(c);
    Wire.write(c);
    Wire.endTransmission();
  }
}
