void setup() {
  // pinMode(18, OUTPUT);
  ledcSetup(0, 5000, 8);      // LED Channel Setup-> ledcSetup(채널, 주파수, 해상도)
  ledcAttachPin(18, 0);      // ledcAttachPin(gpio핀번호, pwm채널)

  ledcSetup(1, 5000, 16);    // 해상도는 0 ~ 2의 8승 
  ledcAttachPin(19, 1);

}

void loop() {
  ledcWrite(0, 127);   // ledcWrite(pwm채널, 밝기)
  delay(100);
  ledcWrite(0, 255);
  delay(100);

  ledcWrite(1, 127);
  delay(100);
  ledcWrite(1, 255);
  delay(100);

  /* 깜빡깜빡 안함.....
  ledcWrite(1, 30000);
  delay(100);
  ledcWrite(1, 65000);
  delay(100);
  */
}
