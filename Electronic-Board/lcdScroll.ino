/*
    2021 - 06 - 02
    LCD 위아래로 스크롤 효과
    by iknam
*/
#include <LiquidCrystal.h>

const int rs = 4, en = 6, d4 = 10, d5 = 11, d6 = 12, d7 = 13;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String strDefault, str[3];
int i;
char delim[] = " \n";
char *token;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop()
{
  //Serial.println(str[0]);
  /*if (Serial.available() > 0)
  {
      strDefault = Serial.readString(); // 값들을 공백으로 구분
      Serial.println(strDefault);
  }*/

  /*token = strtok(strDefault.c_str(), delim);

  Serial.println(strDefault.c_str());
  for(i = 1; token != NULL; i++)
  {
    str[i] = token;
    token = strtok(NULL, delim);
    Serial.println(str[i]);
  }*/
  
/*  for(i = 0; i < 3; i++)
  {
    str[i]
  }
  str[i] = inString.substring(
  이 방식은 별로*/
  if (Serial.available() > 0)
  {
      str[0] = Serial.readString(); // 스트링을 이방식으로 입력받으면 세값은 안됨 공백이 두개이상이 되기 때문
      Serial.println(str[0]);
  }
  if (Serial.available() > 0)
  {
      str[1] = Serial.readString();
      Serial.println(str[1]);
  }
  if (Serial.available() > 0)
  {
      str[2] = Serial.readString();
      Serial.println(str[2]);
  }
  lcd.setCursor(0, 0);
  lcd.print(str[0]);
  delay(400);
  lcd.clear();
  lcd.print(str[1]);
  delay(400);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(str[2]);
  delay(400);
  lcd.clear();
  delay(400);
}
