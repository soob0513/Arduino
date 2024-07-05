// 자이로센서 (Gyro Sensor)
#include<Wire.h>

// 자이로 센서 I2C 주소
const int MPU = 0x68;

// 센서값 저장 -> 자이로센서 x, y, z, 온도센서, 가속도센서 x, y, z
// 2byte -> 14byte
int16_t AcX, AcY, AcZ,Temp,GyX,GyY,GyZ;

void setup() {
  // I2C 통신
  Wire.begin();                 // I2C 통신 시작 (0을 전송해서 시작)
  Wire.beginTransmission(MPU);  // I2C 주소 확인 

  // 자이로 센서 값을 읽겠다!
  Wire.write(0x6B);             // 데이터가 저장된 주소 
  Wire.write(0);                // 0을 전송해서 시작
  Wire.endTransmission(true);   // 1(true)을 전송해서 종료
  Serial.begin(9600);
}

void loop() {
  Wire.beginTransmission(MPU);     // 자이로 센서 연결
  Wire.write(0x3B);                // 데이터 저장 주소 
  Wire.endTransmission(false);     // 0(false)을 전송해서 I2C 통신 유지
  Wire.requestFrom(MPU, 14, true); // 자이로 센서로부터 값을 읽어온다

  // Wire.read() : 1byte 읽기
  // <<8 : 8비트 (1byte)만큼 왼쪽으로 시프트 
  // |Wire.read() : 다음 1byte를 읽어 이전 시프트한 값에 연결
  // 2byte로 데이터를 GX에 저장
  // 값 범위 : -17000 ~ 17000
  GyX = Wire.read()<<8|Wire.read();
  GyY = Wire.read()<<8|Wire.read();
  GyZ = Wire.read()<<8|Wire.read();

  Temp = Wire.read()<<8|Wire.read();

  AcX = Wire.read()<<8|Wire.read();
  AcY = Wire.read()<<8|Wire.read();
  AcZ = Wire.read()<<8|Wire.read();

  Serial.print("AcX="); Serial.print(AcX);
  Serial.print("|AcY="); Serial.print(AcY);
  Serial.print("|AcZ="); Serial.println(AcZ);

  Serial.print("|Temp="); Serial.println(Temp/340.00+36.53);

  Serial.print("|GyX="); Serial.print(GyX);
  Serial.print("|GyY="); Serial.print(GyY);
  Serial.print("|GyZ="); Serial.println(GyZ);

  // 자이로 센서값을 각도로 변환
  int16_t GX2 = map(GyX, -17000, 17000, -180, 180);
  int16_t GY2 = map(GyY, -17000, 17000, -180, 180);
  int16_t GZ2 = map(GyZ, -17000, 17000, -180, 180);

  Serial.print("||GX2="); Serial.print(GX2);
  Serial.print("||GY2="); Serial.print(GY2);
  Serial.print("||GZ2="); Serial.println(GZ2);
  Serial.println("   ");

  delay(333);
}
