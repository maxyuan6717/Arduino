#include <Servo.h>
const int green1 = 7;
const int green2 = 6;
const int green3 = 5;
const int but1 = 10;
const int but2 = 11;
const int but3 = 12;
int butstate1 = 0;
int butstate2 = 0;
int butstate3 = 0;
int numlock;
Servo lock;

void setup() {
  // put your setup code here, to run once:
  pinMode(green1,OUTPUT);
  pinMode(green2,OUTPUT);
  pinMode(green3,OUTPUT);
  lock.attach(8);
  pinMode(but1,INPUT);
  pinMode(but2,INPUT);
  pinMode(but3,INPUT);
  lock.write(130);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  butstate1 = digitalRead(but1);
  butstate2 = digitalRead(but2);
  butstate3 = digitalRead(but3);
  if (numlock == 0 && butstate1 == HIGH) {
    digitalWrite(green1,HIGH);
    numlock = 1;
    delay(500);
  }
  if (numlock == 1 && butstate2 == HIGH) {
    digitalWrite(green2,HIGH);
    numlock = 2;
    delay(500);
  }
  else if (numlock == 1 && butstate3 == HIGH) {
    digitalWrite(green1,LOW);
    digitalWrite(green2,LOW);
    numlock = 0;
  }
  /*if (numlock == 1 && butstate3 == HIGH) {
    digitalWrite(green1,LOW);
    digitalWrite(green2,LOW);
    numlock = 0;
    delay(500);
  }*/
  if (numlock == 2 && butstate3 == HIGH) {
    digitalWrite(green3,HIGH);
    lock.write(180);
    numlock = 3;
    delay(500);
  }
  if (numlock == 3 && butstate1 == HIGH) {
    digitalWrite(green1,LOW);
    digitalWrite(green2,LOW);
    digitalWrite(green3,LOW);
    lock.write(130);
    numlock = 0;
    delay(500);
  }
  if (numlock == 2 && butstate1 == HIGH) {
    digitalWrite(green1,LOW);
    digitalWrite(green2,LOW);
    digitalWrite(green3,LOW);
    numlock = 0;
    delay(500);
  }
  /*if (numlock == 2 && butstate2 == HIGH) {
    digitalWrite(green1,LOW);
    digitalWrite(green2,LOW);
    digitalWrite(green3,LOW);
    numlock = 0;
  }*/

}
