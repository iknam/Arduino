/*
    2021 - 06 - 02
    LCD 위아래로 스크롤 효과
    문자열이 깔끔하게 지워지지 않음 clear 를 쓰면 스크롤 느낌이 안남
    by iknam
*/
#include <LiquidCrystal.h>

const int rs = 4, en = 6, d4 = 10, d5 = 11, d6 = 12, d7 = 13;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String strDefault, str[100]; // 나중에 str을 동적할당 하고 싶음
int i, j, k;
int blankPosition, blankPositionNum = 0;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop()
{
  if (Serial.available() > 0)
  {
      strDefault = Serial.readString();
      //Serial.println(strDefault);
      i = 0;
  }
  do // 문자열들을 공백을 기준으로 쪼갬
  {
    blankPosition = strDefault.indexOf(' ');
    if(blankPosition != -1)
    {
      blankPositionNum++;
      str[i] = strDefault.substring(0, blankPosition);
      strDefault = strDefault.substring(blankPosition+1, strDefault.length());
      i++;
    }
    else
    {
      if(strDefault.length() > 0)
      {
        str[i] = strDefault;
      }
    }
  }
  while(blankPosition >= 0);


 // c에서 strtok를 사용하는 코드
  /*token = strtok(strDefault.c_str(), delim);

  Serial.println(strDefault.c_str());
  for(i = 1; token != NULL; i++)
  {
    str[i] = token;
    token = strtok(NULL, delim);
    Serial.println(str[i]);
  }*/
  
  for(j = 0; j <= blankPositionNum; j++)
  {
    lcd.setCursor(0,0);
    lcd.print(str[j]);
    delay(500);
    lcd.setCursor(0,1);
    lcd.print(str[j]);
    delay(500);
    
  }
}
