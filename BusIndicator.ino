/*
2021 - 05 - 30
버스계기판 시뮬레이션
by iknam
*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);


int i = 0;
int lp = 1;

void setup()
{
    lcd.begin(16, 2);
    lcd.print("yeah");
}

void loop()
{
    for (int i = 0; i < 16; i++)
    {
        lcd.setCursor(i , 0);
        lcd.print("1011");
        delay(1000);
        if (i != 0)
        {
            lcd.setCursor(i - 1, 0);
            lcd.print(" ");
        }
    }
}