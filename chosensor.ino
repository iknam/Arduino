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
  tone(speakerPin, 500, 1000);
  long duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Wait for 1000 millisecond(s)
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = ((float)(340 * duration) / 1000) / 2;
  delay(500); // Wait for 1000 millisecond(s)

  Serial.println(distance);
}
