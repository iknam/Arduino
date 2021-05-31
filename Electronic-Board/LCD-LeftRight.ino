/*
    2021 - 05 - 30
    LCD 문자 좌우로 움직이기
    by iknam
*/
#include <LiquidCrystal.h>

const int rs = 4, en = 6, d4 = 10, d5 = 11, d6 = 12, d7 = 13;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int sLen; // 문자열 길이
String str;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop()
{
  if (Serial.available() > 0)
  {
      str = Serial.readString();
      Serial.println(str);
      lcd.clear();
      lcd.print(str);
      sLen = str.length();
  }
  
  for(int i = 0; i < 16 - sLen; i++)
  {
    lcd.scrollDisplayRight();
    delay(100);
  }

  for(int i = 0; i < 16 - sLen; i++)
  {
    lcd.scrollDisplayLeft();
    delay(100);
  }
}