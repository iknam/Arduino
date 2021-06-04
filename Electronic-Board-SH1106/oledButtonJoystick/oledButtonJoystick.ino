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


void setup()
{
  Wire.begin();
  
  // OLED Display initial setting to operation
  Init_OLED(); 

  pinMode(3, INPUT_PULLUP);
  pinMode(A2, INPUT);
  Serial.begin(9600);
}
void loop(){
int x = analogRead(A0);
Serial.println(x);
    OLED_Display();
    if(digitalRead(3) == LOW || x <50) {
  display.print(F("Example ")); display.println("ABC");
  display.print(F("Example ")); display.println("ABC");
  }
  else
  {
    display.print(F("Example ")); display.println("ABCax");
  }
}

void Init_OLED() {
  
  // OLED Display initial setting to operation
  #if (DISPLAY_SIZE == OLED_096_INCH)
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  #endif
  #if (DISPLAY_SIZE == OLED_130_INCH)
   display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  #endif
  display.display();
  delay(1);
  display.clearDisplay();

}

void OLED_Display() {
  
  display.setTextSize(1); // Or display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  //display.println(String( ) + ":" + String( ));

  display.display();
  display.clearDisplay();
    
}