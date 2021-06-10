#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16, 2);
  lcd.print("o65465546k");
}

void loop()
{
  lcd.noDisplay();
  delay(500);
  lcd.display();
  delay(500);
}
