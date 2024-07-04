// 마스터(ESP32)에서 전송된 데이터를 슬레이브(아두이노)에서 출력
// Arduino Uno 보드 연결
// 이쪽 Serial Monior에 출력된다

// LED 연결해서 1을 보내면 LED ON, 0을 보내면 LED OFF
#include <Wire.h>

const byte address = 0x04;

void setup() {
  Serial.begin(9600);
  Serial.println("I2C test!!");

  Wire.begin(address);
  Wire.onReceive(receiveEvent);
  // LED 연결
  pinMode(13, OUTPUT);
}

void loop() {
  delay(500);
}

void receiveEvent(int howMany){
  while(Wire.available()){
    char c = Wire.read();
    Serial.println(c);
    if(c=='1'){
      digitalWrite(13,1);
    }else if(c=='0'){
      digitalWrite(13,0);
    }
  }
}