// 스탠드 선생님
void setup() {
  pinMode(7, INPUT);
  pinMode(10, OUTPUT);

  Serial.begin(9600);
}

int cnt = 0;
bool state = true;

void loop() {
  int btnState = digitalRead(7);
  // Serial.println(btnState);

  if (btnState == 1) {
    if (state == true) {
      cnt++;
      state = false;
    }
  } else if (btnState == 0) {
    state = true;
  }

  if(cnt==1){
    analogWrite(10, 100);
  }else if(cnt==2){
    analogWrite(10, 255);
  }else if(cnt==3){
    analogWrite(10,0);
    cnt=0;
  }
}