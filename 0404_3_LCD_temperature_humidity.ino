// LCD와 온습도센서
// include the library code:
#include <LiquidCrystal.h>
#include "DHT.h"
#define DHTPIN 27
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const int rs = 14, en = 12, d4 = 13, d5 = 5, d6 = 23, d7 = 19;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte heart[8] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000
};
byte cc[8] = {
  B11100,
  B10100,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};


void setup() {
  lcd.begin(16, 2);   // 16열 2행
  dht.begin();
  lcd.createChar(0, heart);    // 문자를 8개까지 만들 수 있음 => lcd.createChar(0, heart) 0번째로 heart라는 문자를 만들겠다
  lcd.createChar(1, cc);
}

void loop() {
  float h = dht.readHumidity(); 
  float t = dht.readTemperature();
  // 하트 출력
  lcd.setCursor(12,1);
  lcd.write(byte(0));

  lcd.setCursor(0,0);
  lcd.print("H : ");
  lcd.print(h);
  lcd.print("% ");
  lcd.setCursor(0,1);
  lcd.print("T : ");
  lcd.print(t);
  lcd.write(byte(1));
  lcd.print("C");
}

