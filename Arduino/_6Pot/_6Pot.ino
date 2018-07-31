#include <Servo.h>
Servo servos[7];

int pins[6] = {A0,A1,A2,A3,A4,A5};
int vals[6];

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 6; i++) pinMode(pins[i],INPUT);
  for (int i = 0; i < 7; i++) {
    servos[i].attach(i+7);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 6; i++) {
    vals[i] = analogRead(pins[i]);
    Serial.print(vals[i]);
    Serial.print(" ");
    int deg = map(vals[i],0,1024,0,180);
    if (i == 1) {
      servos[i].write(deg);
      servos[i+1].write(180-deg);
    }
    else if (i == 0) {
      servos[i].write(deg);
    }
    else {
      servos[i+1].write(deg);
    }
  }
  Serial.println();
  delay(15);
}
