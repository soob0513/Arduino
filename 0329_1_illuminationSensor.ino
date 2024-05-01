// 조도센서로 가로등
void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);   // 0~1023
  Serial.println(sensorValue);
  if (sensorValue >= 400){
    digitalWrite(10,0);
  }else{
    digitalWrite(10,1);
  }
}
