#include <Servo.h>
Servo s;
int led = 4;
int t = 15500;
int done = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  s.attach(3);
  s.write(10);
  delay(5000);
  digitalWrite(led,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
    while (!done) {
      s.write(10);
      delay(t);
      s.write(70);
      done = 1;
    }
}
