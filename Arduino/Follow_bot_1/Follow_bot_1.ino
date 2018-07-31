#include <Servo.h>
Servo hservo;
Servo lservo;
Servo rservo;
#define echopin1 9
#define echopin2 7
#define echopin3 5
#define trigpin1 8
#define trigpin2 6
#define trigpin3 4
int angle = 90;
int maxd = 40;
int distancespeed = 0;
const int redPin = A1;
const int bluePin = A2;
const int greenPin = A3;

long duration1, duration2, duration3, distance1, distance2, distance3;
void setup() {
  // put your setup code here, to run once:
  pinMode(echopin1,INPUT);
  pinMode(echopin2,INPUT);
  pinMode(echopin3,INPUT);
  pinMode(trigpin1,OUTPUT);
  pinMode(trigpin2,OUTPUT);
  pinMode(trigpin3,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  hservo.attach(3);
  hservo.write(angle);
  lservo.attach(11);
  rservo.attach(10);
  lservo.write(90);
  rservo.write(90);
  Serial.begin(9600);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  // distance for left ultrasound
  digitalWrite(trigpin1,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin1,LOW);
  duration1 = pulseIn(echopin1,HIGH);
  distance1 = duration1/58.2;
  // distance for middle ultrasound
  digitalWrite(trigpin2,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin2,LOW);
  duration2 = pulseIn(echopin2,HIGH);
  distance2 = duration2/58.2;
  // distance for right ultrasound
  digitalWrite(trigpin3,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin3,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin3,LOW);
  duration3 = pulseIn(echopin3,HIGH);
  distance3 = duration3/58.2;
  if (distance1 > maxd) {
    distance1 = maxd;
  }
  if (distance2 > maxd) {
    distance2 = maxd;
  }
  if (distance3 > maxd) {
    distance3 = maxd;
  }
  if (distance1 == 0) {
    distance1 = maxd;
  }
  if (distance2 == 0) {
    distance2 = maxd;
  }
  if (distance3 == 0) {
    distance3 = maxd;
  }

  /*if (distance1 == maxd && distance2 == maxd && distance3 == maxd) {
    lservo.write(90);
    rservo.write(90);
    setColor(255,0,0);
  }*/
  if (distance1 < distance2 && distance1 < distance3) {
    setColor(255,255,0);
    lservo.write(95);
    rservo.write(90);
  }
  else if (distance2 < distance1 && distance2 < distance3) {
    setColor(25,25,255);
    distancespeed =  15-distance2;
    lservo.write(90-distancespeed);
    rservo.write(90+distancespeed);
    /*if (distance2 < 20) {
      lservo.write(90-distancespeed);
      rservo.write(90+distancespeed);
    }
    else if (distance2 > 20) {
      lservo.write(90-distancespeed);
      rservo.write(90+distancespeed);
    }
    else if (distance2 == 20) {
      lservo.write(90);
      rservo.write(90);
    }*/
  }
  else if (distance3 < distance1 && distance3 < distance2) {
    setColor(0,255,255);
    lservo.write(90);
    rservo.write(85);
  }
  
  /*if (distance1 > 40 && distance2 > 40 && distance2 > 40) {
    setColor(255,0,0);
    lservo.write(90);
    rservo.write(90);
  }*/

}
void setColor(int red, int green, int blue) {
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
