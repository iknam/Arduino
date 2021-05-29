/*  2021-05-29
 *  버튼 누르면 LED 점등
 *  by iknam
 */

int pushButton = 12;
int ledPin = 8;

void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(pushButton);
  if (buttonState == LOW)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
  Serial.println(buttonState);
}
