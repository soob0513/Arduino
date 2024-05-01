void setup() {
  pinMode(18, OUTPUT);
  pinMode(26, INPUT); 
}

void loop() {
  
  digitalWrite(18, 1);
  delay(2);
  digitalWrite(18, 0);
  delay(2);
  
/*
  int btn = digitalRead(26);
  digitalWrite(18, btn);
  */
}