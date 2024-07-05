import processing.serial.*;

Serial port;

void setup(){
  // 사용 가능한 시리얼 포트 검색
  // Serial.list() : 사용가능한 포트 리스트
  for (int i = 0; i < Serial.list().length;i++){
    println("[" + i + "]" + Serial.list()[i]);
  }
  
  // 시리얼 포트 할당 -> 아두이노 포트번호에 해당하는 인덱스 설정
  port = new Serial(this, Serial.list()[1], 9600);
  
  // 창 크기 설정
  size(300, 300);
}

void draw(){
   // 배경색 설정 -> 0~255
   background(150); // 회색
   
   // 시리얼 포트로부터 데이터가 수신되었다면 
   if (port.available() > 0){
     // 수신된 값 읽어오기
     int x = port.read();
     
     if (x == 0) {
       // 사각형 그리기 -> rect(좌상단 좌표(x,y), 폭, 높이);
       rect(100, 100, 50, 50);
     }else{
       // 타원 그리기 -> ellipse(중심점 좌표(cx, cy), 폭의 반지름, 높이의 반지름);
       ellipse(100, 100, 50, 50);
     }
   }
}
