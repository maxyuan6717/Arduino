#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
 
/*----- Declare all constant pin to be used ----*/
 
#define CE_PIN   9
#define CSN_PIN 10
//*******OLD CONTROLLER*********
//#define JOYSTICK_X A5
//#define JOYSTICK_Y A4

//*******NEW CONTROLLER*********
#define JOYSTICK_X A1
#define JOYSTICK_Y A0 
#define pan A3
#define tilt A2
 
const uint64_t pipe = 0xE8E8F0F0E1LL; // This is the transmit pipe to communicate the two module
 
 
/*-----Object Declaration ----*/
 
RF24 radio(CE_PIN, CSN_PIN); // Activate  the Radio
 
/*-----Declaration of Variables -----*/
 
int joystick[4];  // Two element array holding the Joystick readings
 
void setup()   
{
  Serial.begin(9600); /* Opening the Serial Communication */
  radio.begin();
  radio.openWritingPipe(pipe);
}//--(end setup )---
 
 
void loop()   /* Runs Continuously */
{
  
  //OLD CONTROLLER
  //int x = map(analogRead(JOYSTICK_X),0,1023,0,100); // Reading Analog X
  //int y = map(analogRead(JOYSTICK_Y),0,1023,-200,200); // Reading Analog Y

  //NEW CONTROLLER
  int x = 100-map(analogRead(JOYSTICK_X),0,1023,0,100); // Reading Analog X
  int y = 0-map(analogRead(JOYSTICK_Y),0,1023,-255,255); // Reading Analog Y
  int p = map(analogRead(pan),0,1023,30,150);
  int t = map(analogRead(tilt),0,1023,30,150);
  if (x>5 && x <95) {
    x = 50;   
  }
  else if (x <= 5) {
    x = 0;
  }
  else if (x>=95) {
    x = 100;
  }
  if (y>(0-3) && y<3) {
    y = 0;
  }
  joystick[0] = x;
  joystick[1] = y;
  joystick[2] = p;
  joystick[3] = t;
  Serial.print("X: ");
  Serial.print(joystick[2]);
  Serial.print("  Y: ");
  Serial.print(joystick[3]);
  Serial.println("");
  
  
  radio.write( joystick, sizeof(joystick) );
 
}//--(end main loop )---
