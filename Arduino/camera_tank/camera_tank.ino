#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
/*----- Declare all constant pin to be used ----*/
 
#define CE_PIN   9
#define CSN_PIN 10
const int led = 8;
//Motor A
int MotorA1 = 7;
int MotorA2 = 5;
int enableA = 6;
//Motor B
int MotorB1 = 4;
int MotorB2 = 2;
int enableB = 3;
int vspeed;
int hspeed;
int p;
int t;
const uint64_t pipe = 0xE8E8F0F0E1LL; // This is the transmit pipe to communicate the two module
 
 
/*-----Object Declaration ----*/
 
RF24 radio(CE_PIN, CSN_PIN); // Activate the Radio
 
/*-----Declaration of Variables -----*/
 
int joystick[4];  //  Two element array holding the Joystick readings

 
void setup()  
{
  pinMode (led,OUTPUT);
  pinMode (MotorA1, OUTPUT);
  pinMode (MotorA2, OUTPUT);  
  pinMode (enableA, OUTPUT);
  pinMode (enableB, OUTPUT);
  pinMode (MotorB1, OUTPUT);
  pinMode (MotorB2, OUTPUT);  
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
    digitalWrite(led,LOW);
    while (!done)
    {
      // Fetching the data payload
      done = radio.read( joystick, sizeof(joystick) );
      //int hspeed = map(joystick[0],0,100,-50,50);
      hspeed = joystick[0];
      vspeed = map(joystick[1],-255,255,-150,150);
      p = joystick[2];
      t = joystick[3];
      Serial.print("X = ");
      Serial.print(hspeed);
      Serial.print(" Y = ");      
      Serial.println(vspeed);
      
      if (hspeed == 50 && vspeed >= 0) {
        f(vspeed);
      }
      else if (hspeed == 50 && vspeed < 0) {
        b(vspeed);
      }
      else if (hspeed == 100) {
        r();
      }
      else if (hspeed == 0) {
        l();
      }
    }
  }
  else
  {    
      Serial.println("No radio available");
      digitalWrite(led,HIGH);
      analogWrite(enableA, 0);
      analogWrite(enableB, 0);
      digitalWrite (MotorA1, LOW);
      digitalWrite (MotorA2, LOW);
   
      digitalWrite (MotorB1, LOW);
      digitalWrite (MotorB2, LOW);
      
  }
 
}

int f(int vspeed) {
  analogWrite (enableA, vspeed);
  analogWrite (enableB, vspeed);
    
  digitalWrite (MotorA1, LOW);
  digitalWrite (MotorA2, HIGH);
   
  digitalWrite (MotorB1, LOW);
  digitalWrite (MotorB2, HIGH);
}
int r() {
  analogWrite (enableA, 255);
  analogWrite (enableB, 255);
    
  digitalWrite (MotorA1, LOW);
  digitalWrite (MotorA2, HIGH);
   
  digitalWrite (MotorB2, LOW);
  digitalWrite (MotorB1, HIGH);
}
int b(int vspeed) {
  analogWrite (enableA,(0-vspeed));
  analogWrite (enableB,(0-vspeed));
    
  digitalWrite (MotorA2, LOW);
  digitalWrite (MotorA1, HIGH);
   
  digitalWrite (MotorB2, LOW);
  digitalWrite (MotorB1, HIGH);
}
int l() {
  analogWrite (enableA, 255);
  analogWrite (enableB, 255);
    
  digitalWrite (MotorA2, LOW);
  digitalWrite (MotorA1, HIGH);
   
  digitalWrite (MotorB1, LOW);
  digitalWrite (MotorB2, HIGH);
}

