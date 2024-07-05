// 2개 이상의 센서 값 전송하기
// 가변저항, 버튼
void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT);
}

void loop() {
  int portVal = analogRead(A0);   // 가변저항
  int switchVal = digitalRead(8); // 스위치 

  // 읽은 값들을 프로세싱으로 전송
  // 1. 문자열로 만들어서 보내는 방식 "val1:val2"
  // 2. 시작비트 -> 값1,값2 -> 종료비트

  // 시작비트 : 255
  Serial.write(255);  // 데이터 시작 위치 설정

  // 데이터 전송
  // 값1 - 가변저항 값 전송 (0~255)
  // map(변수, 원 시작값, 원 종료값, 목표 시작값, 목표 종료값)
  Serial.write(map(portVal, 0, 1023, 0, 253)); 
  // 값2 - 버튼 값 전송
  Serial.write(switchVal);  
  
  // 종료비트 : 254
  Serial.write(254);  
  delay(100);
}
