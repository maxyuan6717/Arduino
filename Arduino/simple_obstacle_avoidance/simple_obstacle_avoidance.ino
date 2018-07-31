#include <Servo.h>
Servo lservo;
Servo rservo;
#define echo 9
#define trig 2
long duration, distance, distancel, distancer;

void setup() {
  // put your setup code here, to run once:
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  lservo.attach(4);
  rservo.attach(3);
  lservo.write(90);
  rservo.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
  scan();
  if (distance > 10) {
    f();
  }
  else if (distance < 10) {
    b();
    delay(300);
    l();
    delay(300);
    s();
    scan();
    distancel = distance;
    delay(200);
    r();
    delay(600);
    s();
    scan();
    distancer = distance;
    delay(200);
    
    if (distancel>distancer && distancel>10) {
      l();
      delay(600);
      f();
    }
    else if (distancer>distancel && distancer>10) {
      
      f();
    }
    else if (distancel < 10 && distancer < 10) {
      r();
      delay(600);
      f();
    }
  }
}
void scan() {
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  distance = duration/58.2;
  delay(100);
}
void f() {
  lservo.write(180);
  rservo.write(0);
}
void b() {
  lservo.write(0);
  rservo.write(180);
}
void r() {
  lservo.write(180);
  rservo.write(180);
}
void l() {
  lservo.write(0);
  rservo.write(0);
}
void s() {
  lservo.write(90);
  rservo.write(90);
}

