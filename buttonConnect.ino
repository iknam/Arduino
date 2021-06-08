//---------- I2C setting ------------------------------------------------------------------------
#include <Wire.h> 

//---------- 128x64 OLED setting ----------------------------------------------------------------
#define OLED_096_INCH   1
#define OLED_130_INCH   2

#define DISPLAY_SIZE OLED_130_INCH    // Select Display Size

#define OLED_RESET 13

#include <Adafruit_GFX.h>

#if (DISPLAY_SIZE == OLED_096_INCH)
 #include <Adafruit_SSD1306.h>
#endif
#if (DISPLAY_SIZE == OLED_130_INCH)
 #include <Adafruit_SH1106.h>
#endif

#if (DISPLAY_SIZE == OLED_096_INCH)
 Adafruit_SSD1306 display(OLED_RESET);
#endif
#if (DISPLAY_SIZE == OLED_130_INCH)
 Adafruit_SH1106 display(OLED_RESET);
#endif

int i, j = 0;
int curColumn = 0, curRow = 40, menuChoice = 0;
int button, button2;

void setup()
{
  Serial.begin(9600);
  
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
}
void loop(){

//delay(500);

  int button = digitalRead(3);
  int button2 = digitalRead(4);
  
  if(button == HIGH) {
    Serial.println("b0 hi");
    
  }
  else//if(button == LOW)
  {
    Serial.println("b0 lo");//delay(300);
  }

  if(button2 == HIGH) {
    Serial.println("b1 hi");
  }
  else //if(button2 == LOW)
  {
    Serial.println("b1 lo");//delay(300);
  }
}
