#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
/*----- Declare all constant pin to be used ----*/
 
#define CE_PIN   8
#define CSN_PIN 10
 
const uint64_t pipe = 0xE8E8F0F0E1LL; // This is the transmit pipe to communicate the two module
 
 
/*-----Object Declaration ----*/
 
RF24 radio(CE_PIN, CSN_PIN); // Activate the Radio
 
/*-----Declaration of Variables -----*/
 
int joystick[2];  //  Two element array holding the Joystick readings
Servo lservo;
Servo rservo;
 
void setup()  
{
  lservo.attach(4);
  rservo.attach(3);
  Serial.begin(9600); /* Opening the Serial Communication */
  delay(1000);
  Serial.println("Nrf24L01 Receiver Starting");
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();;
}//--(end setup )---
 
 
void loop()   
{
  if ( radio.available() )
  {
    // Reading the data payload until the RX received everything
    bool done = false;
    while (!done)
    {
      // Fetching the data payload
      done = radio.read( joystick, sizeof(joystick) );
      int x = joystick[0];
      int y = joystick[1];
      Serial.print("X = ");
      Serial.print(joystick[0]);
      Serial.print(" Y = ");      
      Serial.println(joystick[1]);
      if (x >= 50 && y >= 90) {
        lservo.write(y+(x-50));
        rservo.write(180-y);
      }
      if (x >= 50 && y < 90) {
        lservo.write(y-(x-50));
        rservo.write(180-y);
      }
      if (x < 50 && y >= 90) {
        lservo.write(y);
        rservo.write((180-y)-(50-x));      
      }
      if (x < 50 && y < 90) {
        lservo.write(y);
        rservo.write((180-y)+(50-x));
      }
    }
  }
  else
  {    
      Serial.println("No radio available");
  }
 
}
