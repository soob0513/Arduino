// RFID - RC522
// RFID 태그를 읽고 태그 UID가 일치하는지 확인하기
// 일치 / 불일치 판별

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

  // 태그값 출력
  for(byte i=0; i<mfrc522.uid.size;i++){
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    // 태그값을 문자열에 저장 (2byte 데이터를 병합)
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  content.toUpperCase();
  
  // 카드 : 737689E2 / 태그키 : 382D213
  if(content == "382D213"){
    Serial.println("Authorized access");
    Serial.println();
    delay(3000);
  }else {
    Serial.println("Access denied");
    delay(3000);
  }
}
