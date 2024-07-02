#define SCL_PIN 8
#define SDO_PIN 9

void setup() {
  Serial.begin(9600);
  pinMode(SCL_PIN, OUTPUT); // 출력모드
  pinMode(SDO_PIN, INPUT);  // 입력모드
}

void loop() {
  byte Key = Read_Keypad();  // 키패드 상태를 읽어서 Key 변수에 저장
  if (Key){
    Serial.println(Key);  
  }
}

byte Read_Keypad(void){
  byte Key_state = 0;  // 키 상태를 저장할 변수
  for(byte Count = 1; Count <= 8; Count++){
    digitalWrite(SCL_PIN, LOW);  // SCL_PIN을 LOW 상태로 설정해서 현재 열을 활성화

    if(digitalRead(SDO_PIN)==LOW){  //SDO_PIN 상태를 읽어서 LOW(활성화)이면 
     Key_state = Count;             // Key_state에 현재 Count 값 저장
     digitalWrite(SCL_PIN, HIGH);   // SCL_PIN을 HIGH 상태로 설정해서 비활성화 시킨다!
    }
  }
  return Key_state; // 키 상태 반환
}