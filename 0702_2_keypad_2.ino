#define SCL_PIN 8  // SCL_PIN을 마이크로컨트롤러의 8번 핀으로 정의합니다.
#define SDO_PIN 9  // SDO_PIN을 마이크로컨트롤러의 9번 핀으로 정의합니다.

byte Key;  // 키패드의 키 상태를 저장할 변수

void setup() {
  Serial.begin(9600);    // 시리얼 통신을 9600 보드로 시작합니다.
  pinMode(SCL_PIN, OUTPUT);  // SCL_PIN을 출력 모드로 설정합니다.
  pinMode(SDO_PIN, INPUT);   // SDO_PIN을 입력 모드로 설정합니다.
}

void loop() {
  Key = Read_Keypad();  // 키패드의 상태를 읽어 Key 변수에 저장
  
  if (Key)  // Key가 0이 아니면
    Serial.println(Key);  // Key 값을 시리얼 모니터에 출력
  
  delay(1000);  // 1초 지연
}

byte Read_Keypad(void) {
  byte Key_State = 0;  // 키 상태를 저장할 변수
  
  for (byte Count = 1; Count <= 16; Count++) {
    digitalWrite(SCL_PIN, LOW);  // SCL_PIN을 LOW 상태로 설정하여 현재 열을 활성화
    
    if (digitalRead(SDO_PIN) == 0)  // SDO_PIN의 상태를 읽어 LOW이면
      Key_State = Count;  // Key_State에 현재 Count 값을 저장
    
    digitalWrite(SCL_PIN, HIGH);  // SCL_PIN을 HIGH 상태로 설정하여 현재 열을 비활성화
    
  }
  
  return Key_State;  // 키 상태 반환
}