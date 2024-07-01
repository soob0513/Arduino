#include <Wire.h>

// I2C 주소를 검색해보자! -> 1~119까지 주소를 가지고 있음!
void setup() {
  Serial.begin(9600);
  Wire.begin();
  while (!Serial){}
  Serial.println("");
  for(byte i = 1; i < 120; i++){
    Wire.beginTransmission(i);    // 1~119번 주소의 장치를 검색

    if(Wire.endTransmission()==0){ // I2C통신이 가능한 장치가 있다면
      Serial.print("Address : ");
      Serial.print("0x");
      Serial.println(i, HEX);
      delay(10);
    }
  }
}

void loop() {
  

}
