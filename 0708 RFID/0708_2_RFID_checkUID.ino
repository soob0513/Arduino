// RFID - RC522
// RFID 태그를 읽고 태그 UID가 일치하는지 확인하기
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9  // RST 핀 번호
#define SS_PIN 10  // SS 핀 번호

MFRC522 mfrc522(SS_PIN, RST_PIN);  // MFRC522 객체 생성

void setup() {
  Serial.begin(9600);
  SPI.begin();       // SPI 통신 시작
  mfrc522.PCD_Init();   // MFRC522 모듈 초기화
  Serial.println("Approximate your card to the reader...");
}

void loop() {
  // MFRC522 Card Reader의 버전 출력
  if (!mfrc522.PICC_IsNewCardPresent())
    return;
  // 자가 테스트
  if (!mfrc522.PICC_ReadCardSerial())
    return;
  
  Serial.print("UID tag :");
  String content ="";
  byte letter;

  for(byte i=0; i<mfrc522.uid.size;i++){
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();
}
