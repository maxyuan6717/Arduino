#include <Servo.h>
Servo servo;
Servo lservo;
Servo rservo;
#define echopin1 9
#define echopin2 7
#define echopin3 5
#define trigpin1 8
#define trigpin2 6
#define trigpin3 4
int angle = 90;
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
  servo.attach(3);
  servo.write(angle);
  lservo.attach(11);
  rservo.attach(10);
  lservo.write(90);
  rservo.write(90);
  delay(1000);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(trigpin2,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin2,LOW);
  duration2 = pulseIn(echopin2,HIGH);
  distance2 = duration2/58.2;
  delay(10);
  if (distance2 > 10) {
    go();
    for (int i = 15; i <=165; i+=90) {
      servo.write(i);
      delay(120);
      digitalWrite(trigpin2,LOW);
      delayMicroseconds(2);
      digitalWrite(trigpin2,HIGH);
      delayMicroseconds(10);
      digitalWrite(trigpin2,LOW);
      duration2 = pulseIn(echopin2,HIGH);
      distance2 = duration2/58.2;
      delay(10);
      if (distance2 < 10) {
        break;
      }
    }
    for (int i = 165; i >=15; i-=90) {
      servo.write(i);
      delay(120);
      digitalWrite(trigpin2,LOW);
      delayMicroseconds(2);
      digitalWrite(trigpin2,HIGH);
      delayMicroseconds(10);
      digitalWrite(trigpin2,LOW);
      duration2 = pulseIn(echopin2,HIGH);
      distance2 = duration2/58.2;
      delay(10);
      if (distance2 < 10) {
        break;
      }
    }
  }
  
      
      
  else if (distance2 < 10) {
    lservo.write(88);
    rservo.write(92);
    delay(200);
    lservo.write(90);
    rservo.write(90);
    servo.write(140);
    delay(200);
    digitalWrite(trigpin3,LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin3,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin3,LOW);
    duration3 = pulseIn(echopin3,HIGH);
    distance3 = duration3/58.2;
    delay(500);
    servo.write(40);
    delay(200);
    digitalWrite(trigpin1,LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin1,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin1,LOW);
    duration1 = pulseIn(echopin1,HIGH);
    distance1 = duration1/58.2;
    delay(500);
    servo.write(90);
    if (distance1 > distance3) {
      lservo.write(92);
      rservo.write(92);
      delay(500);
    }
    else if (distance1 < distance3) {
      lservo.write(88);
      rservo.write(88);
      delay(500);
    }

  }
}

void go() {
  lservo.write(120);
  rservo.write(60);
  
    
  }
  /*while(1) {
    delay(500);
    servo.write(180);
    delay(400);
    digitalWrite(trigpin2,LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin2,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin2,LOW);
    duration2 = pulseIn(echopin2,HIGH);
    distance2 = duration2/58.2;
    delay(100);
    Serial.println(distance2);
    if (distance2 < 10) {
      break;
    }
    servo.write(0);
    delay(400);
    digitalWrite(trigpin2,LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin2,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin2,LOW);
    duration2 = pulseIn(echopin2,HIGH);
    distance2 = duration2/58.2;
    delay(100);
    Serial.println(distance2);
    if (distance2 <10) {
      break;
    }
    servo.write(90);
    delay(400);
    digitalWrite(trigpin2,LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin2,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin2,LOW);
    duration2 = pulseIn(echopin2,HIGH);
    distance2 = duration2/58.2;
    delay(100);
    Serial.println(distance2);
    if (distance2 < 10) {
      break;
    }
  }*/
  


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
