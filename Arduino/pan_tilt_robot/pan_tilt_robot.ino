#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
/*----- Declare all constant pin to be used ----*/
 
#define CE_PIN   9
#define CSN_PIN 10
Servo pan;
Servo tilt;
const int led = 8;
//Motor A
int MotorA1 = 7;
int MotorA2 = 5;
int enableA = 6;
//Motor B
int MotorB1 = 2;
int MotorB2 = 4;
int enableB = 3;
int vspeed;
int hspeed;
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
  
  pan.attach(A0);
  tilt.attach(A1);
  pan.write(90);
  tilt.write(90);
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
      vspeed = joystick[1];
      int p = joystick[2];
      int t = joystick[3];
      pan.write(p);
      tilt.write(t);
      Serial.print("X = ");
      Serial.print(p);
      Serial.print(" Y = ");      
      Serial.println(t);
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
  analogWrite (enableA, 100);
  analogWrite (enableB, 100);
    
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
  analogWrite (enableA, 100);
  analogWrite (enableB, 100);
    
  digitalWrite (MotorA2, LOW);
  digitalWrite (MotorA1, HIGH);
   
  digitalWrite (MotorB1, LOW);
  digitalWrite (MotorB2, HIGH);
}

