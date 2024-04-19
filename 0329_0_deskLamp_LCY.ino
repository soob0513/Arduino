// 스탠드 LCY
void setup() {
  pinMode(2,INPUT);
  pinMode(10,OUTPUT);

  Serial.begin(9600);
}


int led = 0; 
void loop() {
   int btn = digitalRead(2);
   Serial.println(btn);
   if (btn == 1 ) {
    led += 50; 
    analogWrite(10,led);
    
   }else if(led >=255){
    analogWrite(10,0);
   }
}