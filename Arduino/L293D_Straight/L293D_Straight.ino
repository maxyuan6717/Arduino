//Testing the DC Motors with
// L293D
 
//Define Pins
//Motor A
int MotorA1 = 5;
int MotorA2 = 7;
int enableA = 6;
//Motor B
int MotorB1 = 2;
int MotorB2 = 4;
int enableB = 3;
void setup() {
  
  Serial.begin (9600);
  //configure pin modes
  pinMode (MotorA1, OUTPUT);
  pinMode (MotorA2, OUTPUT);  
  pinMode (enableA, OUTPUT);
  pinMode (enableB, OUTPUT);
  pinMode (MotorB1, OUTPUT);
  pinMode (MotorB2, OUTPUT);  
}
 
void loop() {
    
    analogWrite (enableA,200);
    analogWrite (enableB,200);
    
    Serial.println ("Motion Forward");
    digitalWrite (MotorA1, LOW);
    digitalWrite (MotorA2, HIGH);
   
    digitalWrite (MotorB2, LOW);
    digitalWrite (MotorB1, HIGH);
   
    delay(3000);
    
    digitalWrite(enableA,LOW);
    digitalWrite(enableB,LOW);

    delay(1000);
    
}
