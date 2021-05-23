#define choLeft 10
#define choRight 9
#define motor 8

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  pinMode(choLeft, OUTPUT);
  digitalWrite(choLeft, LOW);
  delayMicroseconds(2);
  digitalWrite(choLeft, HIGH);
  delayMicroseconds(5);
  digitalWrite(choLeft, LOW);
  
  pinMode(choRight, OUTPUT);
  digitalWrite(choRight, LOW);
  delayMicroseconds(2);
  digitalWrite(choRight, HIGH);
  delayMicroseconds(5);
  digitalWrite(choRight, LOW);

  pinMode(choLeft, INPUT);
  double duration = pulseIn(choLeft, HIGH);
  double cmLeft = duration * 349 / 10000 / 2;
  
    pinMode(choRight, INPUT);
  duration = pulseIn(choRight, HIGH);
  double cmRight = duration * 349 / 10000 / 2;
  
  if(cmLeft < 100 && cmRight < 100)
  digitalWrite(motor, LOW);
  else
    digitalWrite(motor, HIGH);
  Serial.println(cmRight);
}