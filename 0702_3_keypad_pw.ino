// 비밀번호 확인하기
#define SCL_PIN 8  // SCL_PIN을 마이크로컨트롤러의 8번 핀으로 정의합니다.
#define SDO_PIN 9  // SDO_PIN을 마이크로컨트롤러의 9번 핀으로 정의합니다.

const byte pw[4] = { 1, 2, 3, 4 };  // 정해진 비밀번호를 저장하는 배열
byte Key[4];  // 입력된 비밀번호를 저장할 배열
int co = 0, ok_co = 0;  // 입력된 키의 개수와 비밀번호가 맞는지 확인하기 위한 변수

void setup() {
  Serial.begin(9600);  // 시리얼 통신을 9600 보드로 시작합니다.
  pinMode(SCL_PIN, OUTPUT);  // SCL_PIN을 출력 모드로 설정합니다.
  pinMode(SDO_PIN, INPUT);  // SDO_PIN을 입력 모드로 설정합니다.
}

void loop() {
  Serial.println("Input Password");  // "Input Password"를 시리얼 모니터에 출력합니다.

  while (co < 4) {  // co가 4보다 작을 동안 반복합니다.
    byte temp = Read_Keypad();  // 키패드의 상태를 읽어 temp에 저장합니다.
    if (temp) {  // temp가 0이 아니면 (즉, 키가 눌렸으면)
      Key[co] = temp;  // 입력된 키를 Key 배열에 저장합니다.
      Serial.print(temp);  // 입력된 키를 시리얼 모니터에 출력합니다.
      Serial.print(" ");
      co++;  // 입력된 키의 개수를 증가시킵니다.
    }
    delay(500);  // 0.5초 지연합니다.
  }

  Serial.println("");  // 새로운 줄을 시리얼 모니터에 출력합니다.
  for (int i = 0; i < 4; i++) {  // 입력된 비밀번호를 확인합니다.
    if (Key[i] == pw[i]) {  // 입력된 비밀번호와 저장된 비밀번호가 일치하면
      ok_co++;  // 일치하는 개수를 증가시킵니다.
    }
  }

  if (ok_co == 4) {  // 비밀번호가 모두 일치하면
    Serial.println("Open !!");  // "Open !!"을 시리얼 모니터에 출력합니다.
  } else {
    Serial.println("Wrong password");  // 일치하지 않으면 "Wrong password"를 시리얼 모니터에 출력합니다.
  }
  co = 0;  // 입력된 키의 개수를 초기화합니다.
  ok_co = 0;  // 일치하는 개수를 초기화합니다.
}

byte Read_Keypad(void) {
  byte Count;
  byte Key_State = 0;  // 키 상태를 저장할 변수

  for (Count = 1; Count <= 8; Count++) {  // 키패드의 16개 키를 확인합니다.
    digitalWrite(SCL_PIN, LOW);  // SCL_PIN을 LOW 상태로 설정하여 현재 열을 활성화합니다.

    if (!digitalRead(SDO_PIN))  // SDO_PIN의 상태를 읽어 LOW이면 (즉, 키가 눌렸으면)
      Key_State = Count;  // Key_State에 현재 Count 값을 저장합니다.

    digitalWrite(SCL_PIN, HIGH);  // SCL_PIN을 HIGH 상태로 설정하여 현재 열을 비활성화합니다.
  }
  return Key_State;  // 키 상태를 반환합니다.
}