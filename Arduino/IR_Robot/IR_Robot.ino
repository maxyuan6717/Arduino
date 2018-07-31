#include <Servo.h>
#include <IRremote.h>
int recv = 12;
const int redPin = A1;
const int greenPin = A2;
const int bluePin = A3;
IRrecv irrecv(recv);
Servo left;
Servo right;
decode_results results;
void setup() {
  // put your setup code here, to run once:
  irrecv.enableIRIn();
  left.attach(11);
  right.attach(10);
  left.write(90);
  right.write(90);
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  setColor(0,255,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) {
    irrecv.resume();
    if (results.value == 0x3D9AE3F7) {
      left.write(180);
      right.write(0);
    }
    else if (results.value == 0x8C22657B) {
      left.write(88);
      right.write(88);
    }
    else if (results.value == 0x1BC0157B) {
      left.write(0);
      right.write(180);
    }
    else if (results.value == 0x449E79F) {
      left.write(92);
      right.write(92);
    }
    else if (results.value == 0x488F3CBB) {
      left.write(90);
      right.write(90);
    }
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

