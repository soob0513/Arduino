import processing.serial.*;

Serial port;

void setup(){
  // 창 크기 설정
  size(255, 255);
  
  for (int i = 0; i < Serial.list().length;i++){
    println("[" + i + "]" + Serial.list()[i]);
  }
  port = new Serial(this, Serial.list()[1], 9600);
}

void draw(){
  // 현재 마우스 좌표를 출력
  println("mouseX = " + mouseX + ",mouseY =" + mouseY);
  
  background(mouseX);
  port.write(mouseX); // 화면 크기가 255X255라서 mouseX의 값이 0~255를 가짐
}
