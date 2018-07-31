//Testing the DC Motors with
// L293D
 
//Define Pins
//Motor A
int enableA = 11;
int MotorA1 = 6;
int MotorA2 = 7;
 
//Motor B
int enableB = 10;
int MotorB1 = 9;
int MotorB2 = 8;
 
void setup() {
  
  //configure pin modes
  pinMode (enableA, OUTPUT);
  pinMode (MotorA1, OUTPUT);
  pinMode (MotorA2, OUTPUT);  
  
  pinMode (enableB, OUTPUT);
  pinMode (MotorB1, OUTPUT);
  pinMode (MotorB2, OUTPUT);  
  
}
 
void loop() {
  //enabling motor A
  analogWrite (enableA, 255);
  analogWrite (enableB, 255);

  //do something
 
  digitalWrite (MotorA1, LOW);
  digitalWrite (MotorA2, HIGH);
 
  digitalWrite (MotorB1, LOW);
  digitalWrite (MotorB2, HIGH);
 
  //3s forward
  delay (3000);
  
  //reverse
  analogWrite(enableA,255);
  analogWrite(enableB,153);
  digitalWrite (MotorA1,HIGH);
  digitalWrite (MotorA2,LOW);  
  
  digitalWrite (MotorB1,HIGH);
  digitalWrite (MotorB2,LOW);  
 
  //5s backwards
  delay (3000);
 
  //stop
  digitalWrite (enableA, LOW);
  digitalWrite (enableB, LOW);
  delay (3000);
}
