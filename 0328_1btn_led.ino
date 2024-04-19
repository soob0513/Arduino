void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT);   // 버튼
  pinMode(5,INPUT);
  pinMode(7,INPUT);
  Serial.begin(9600);  // baud랑 동일하게! 9600 baud가 일반적임
  pinMode(8, OUTPUT);  // LED
  pinMode(10, OUTPUT);  
  pinMode(13, OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(2);
  Serial.println(buttonState);  // ln이 붙으면 개행됨
  int buttonState2 = digitalRead(5);
  Serial.println(buttonState2);
  int buttonState3 = digitalRead(7);
  Serial.println(buttonState3);
