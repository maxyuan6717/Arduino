#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE  5
#define CSN 6

RF24 radio(CE,CSN);

const byte address[6] = "00001";

int pins[6] = {A0,A1,A2,A3,A4,A5};
int vals[6];

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 6; i++) pinMode(pins[i],INPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(5);
  for (int i = 0; i < 6; i++) {
    vals[i] = analogRead(pins[i]);
    Serial.print(vals[i]);
    Serial.print(" ");
  }
  Serial.println();
  radio.write(vals,sizeof(vals));
}
