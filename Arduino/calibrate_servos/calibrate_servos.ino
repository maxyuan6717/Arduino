#include <Servo.h>


void setup() {
  // put your setup code here, to run once:
  Servo servo1;
  Servo servo2;
  servo1.attach(A0);
  servo2.attach(A1);
  servo1.write(90);
  servo2.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:

}
