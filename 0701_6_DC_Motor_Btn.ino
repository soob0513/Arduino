void setup() {
  pinMode(9, OUTPUT);
  pinMode(2,INPUT);
  Serial.begin(9600);
}

// 스위치를 1번 눌렀을 때 선풍기 켜지도록
// 두 번 누르면 꺼지도록
int cnt = 0;
bool state = true;

void loop() {
  int btn = digitalRead(2);
  if (btn == 1){
    if (state == true){
      cnt++;
      state = false;
    }
  }else if (btn == 0){
    state = true;
  }
  Serial.println(cnt);

  if (cnt % 2 == 1){
    analogWrite(9,255);
  }else if (cnt % 2 == 0){
    analogWrite(9,0);
  }  
}
