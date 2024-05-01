void setup()
{
  pinMode(13,OUTPUT); 
  Serial.begin(9600);  // bps : beat per second
}

void loop()
{
 // Serial.println("hello");
  
  if (Serial.available()) {
    char c = Serial.read();    // 문자로 받아오기
    Serial.println(c);

    if (c == '1') {
      digitalWrite(13, 1);
      Serial.println("turn on");
    }else if (c == '0'){
      digitalWrite(13, 0);
      Serial.println("turn off");
    }
  
  
    
  /*
  if (Serial.available()){
    int num = Serial.parseInt();   // 정수로 받아오기

    if (num == 1) {
      digitalWrite(13, 1);
    }else if (num == 0){
      digitalWrite(13,0) ;
    }
  }
  */
}