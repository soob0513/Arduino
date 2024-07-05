int ledPin = 8;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (Serial.available()){
    int val = Serial.read();

    if (val > 128){
      digitalWrite(ledPin, 1);
    }else{
      digitalWrite(ledPin,0);
    }
  }
}
