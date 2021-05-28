/*
 * 2021-05-28
 * 초음파센서와 부저 연동
 * 주차시 차 후면과 장애물 사이를 비프음 빈도로 감지
 * by iknam
 */

  
int trigPin = 8;
int echoPin = 9;
int speakerPin = 12;

void setup()
{
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop()
{
  long duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Wait for 1000 millisecond(s)
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = ((float)(340 * duration) / 1000) / 2;
  delay(200); // Wait for 1000 millisecond(s)

  if(distance < 200)
  {
    tone(speakerPin, 500, distance);
  }
  Serial.println(distance);
}
