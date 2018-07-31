#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

#define CE  5
#define CSN 6
#define led 4

RF24 radio(CE,CSN);

const byte address[6] = "00001";

Servo servos[7];
int vals[6];

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  for (int i = 0; i < 7; i++) servos[i].attach(i+7);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0,address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(5);
  if (radio.available()) {
    digitalWrite(led,HIGH);
    radio.read(vals,sizeof(vals));
    for (int i = 0; i < 6; i++) {
      Serial.print(vals[i]);
      Serial.print(" ");
     }
    Serial.println();
  }
  else {
    digitalWrite(led,LOW);
  }
}
