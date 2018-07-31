#include <Servo.h>
Servo lservo;
Servo rservo;

void setup() {
  // put your setup code here, to run once:
  lservo.attach(4);
  rservo.attach(3);
  lservo.write(90);
  rservo.write(90);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  lservo.write(180);
  rservo.write(0);
  delay(5000);
  lservo.write(90);
  rservo.write(90);
  delay(500);
  /*lservo.write(0);
  rservo.write(180);
  delay(1000);
  lservo.write(90);
  rservo.write(90);
  delay(500);*/
}
