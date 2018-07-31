#include <Servo.h>
Servo lservo;
Servo rservo;
Servo hservo;
const int lsen = 0;
const int msen = 6;
const int rsen = 7;
int lightLevel1, lightLevel2, lightLevel3;
const int redPin = A1;
const int bluePin = A2;
const int greenPin = A3;
void setup() {
  // put your setup code here, to run once:
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  lservo.attach(11);
  rservo.attach(10);
  hservo.attach(3);
  lservo.write(90);
  rservo.write(90);
  hservo.write(90);
  delay(500);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightLevel1 = analogRead(lsen);
  lightLevel2 = analogRead(msen);
  lightLevel3 = analogRead(rsen);
  Serial.println(lightLevel2);
  if (lightLevel2 > 900) {
    lservo.write(90);
    rservo.write(90);
    setColor(25,25,255);
  }
  else if (lightLevel1 < 550 && lightLevel2 < 550 && lightLevel3 < 550) {
    lservo.write(90);
    rservo.write(90);
    setColor(255,0,0);
  }
  else if (lightLevel1 > lightLevel2 && lightLevel1 > lightLevel3) {
    lservo.write(95);
    rservo.write(90);
    setColor(255,255,0);
  }
  
  else if (lightLevel2 > lightLevel1 && lightLevel2 > lightLevel3) {
    lservo.write(120);
    rservo.write(60);
    setColor(25,25,255);
  }
  else if (lightLevel3 > lightLevel2 && lightLevel3 > lightLevel1) {
    lservo.write(90);
    rservo.write(85);
    setColor(0,255,255);
  }
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
