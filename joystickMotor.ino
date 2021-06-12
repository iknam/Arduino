/*
 * 2021. 06. 10
 * 조이스틱을 사용해 같은 방향 속도로 모터를 돌리기 수학적인 문제
 * (0,1000) (0,500) (0,0)
 * (500,1000) (500,500) (500,0)
 * (1000,1000) (1000,500) (1000,0)
 * 각 조이스틱 위치에서 서보모터 회전각
 */

#include <Servo.h>
Servo servo;
int value = 0;

int joy_x = A0;
int joy_y = A1;
int joy_z = A2;

void setup() {
  // put your setup code here, to run once:
  pinMode(joy_x, INPUT);
  pinMode(joy_y, INPUT);
  pinMode(joy_z, INPUT);
  Serial.begin(9600);
  servo.attach(7);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(joy_x);
  int y = analogRead(joy_y);
  //int z = analogRead(joy_z);

  //if(z = 0) servo.write(90);
  if((x > 0 && x < 1000) && (y > 0 && y < 1028)){
    value+=int(sqrt(pow(x, 2)+pow(y, 2)));
    if(value > 360){
      value %= 360;
    }
    servo.write(value);
  }
  // x,y를 사용해서 서보모터 컨트롤
  Serial.print("x : ");Serial.println(x);
  Serial.print("y : ");Serial.println(y);
  Serial.print("value : ");Serial.println(value);
  
  delay(1000);
}
