#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;

void setup() {
  // put your setup code here, to run once:
  pinMode(11,OUTPUT);
  servo1.attach(9);
  servo2.attach(8);
  servo3.attach(7);
  Serial.begin(9600);
}

void loop() {
  //rst();
  //pan();
  potControl();
  //grip();
}

void pan() {
  for (int i = 0; i <= 180; i++) {
    servo3.write(i);
    delay(15);
  }
  for (int i = 180; i >= 0; i--) {
    servo3.write(i);
    delay(15);
  }
}

void rst() {
  servo3.write(90);
}

void potControl() {
  int val = analogRead(A0);
  int deg = map(val,0,1024,0,270);
  servo1.write(getDegrees1(deg));
  //servo2.write(getDegrees2(deg));
  delay(15);
  Serial.println(deg);
}

void grip() {
  int val = analogRead(A0);
  servo3.write(map(val,0,1024,0,180));
  delay(15);
}

int getDegrees1(int x) {
  return map(x,0,270,0,180);
}

int getDegrees2(int x) {
  return map(270 - x,0,270,0,180);
}

