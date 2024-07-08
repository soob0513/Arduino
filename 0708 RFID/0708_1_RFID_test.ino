// RFID - RC522
// mfrc522 라이브러리 설치
// 연결 테스트

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9  // RST 핀 번호
#define SS_PIN 10  // SS 핀 번호

MFRC522 mfrc522(SS_PIN, RST_PIN);  // MFRC522 객체 생성

void setup() {
  Serial.begin(9600);
  SPI.begin();       // SPI 통신 시작
  mfrc522.PCD_Init();   // MFRC522 모듈 초기화

  Serial.println(F("MFRC522 Digital self test"));
  mfrc522.PCD_DumpVersionToSerial();  // MFRC522 Card Reader의 버전 출력
  Serial.println(F("Only known versions supported"));
  Serial.println(F("Performing test..."));
  bool result = mfrc522.PCD_PerformSelfTest();  // 연결 테스트 -> 연결되었다면 true를 반환
  Serial.print(F("Result:"));

  if (result)    // result = true -> 연결되었다면
    Serial.println(F("OK"));
  else 
    Serial.println(F("DEFECT or UNKNOWN"));
}

void loop() {}
