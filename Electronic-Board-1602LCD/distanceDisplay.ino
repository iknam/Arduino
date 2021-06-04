/*
    2021 - 06 - 01
    거리값 디스플레이
    by iknam
*/
#include <LiquidCrystal.h>

const int rs = 4, en = 6, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
const int trigPin = 9, echoPin = 8;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int sLen; // 문자열 길이
String str;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop()
{
  long duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Wait for 1000 millisecond(s)
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = ((float)(340 * duration) / 1000) / 2;

  lcd.print("Distance : ");
  lcd.print(distance);
  delay(100);
  lcd.clear();
  //delay(100);
 }
