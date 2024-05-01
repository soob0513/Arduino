void setup() {
  Serial.begin(9600);    // bps : beat per second
  pinMode(13, OUTPUT);
}

void loop() {
  // Serial.println("hello");
  
  if (Serial.available()) {
    char c = Serial.read();
    Serial.println(c);

    if (c == '1') {
      digitalWrite(13, 1);
      Serial.println("turn on");
    }else if (c == '0'){
      digitalWrite(13, 0);
      Serial.println("turn off");
    }
  }
}
