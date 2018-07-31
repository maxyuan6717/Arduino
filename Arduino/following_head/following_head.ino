#include<Servo.h>
Servo servo;
// trigger pin is blue and echo pin is white
#define echoPin1 12 // Echo Pin
#define trigPin1 13 // Trigger Pin
#define echoPin2 10 // Echo Pin
#define trigPin2 11 // Trigger Pin
#define echoPin3 8 // Echo Pin
#define trigPin3 9 // Trigger Pin
#define echoPin4 6 // Echo Pin
#define trigPin4 7 // Trigger Pin
long duration1, duration2, duration3, duration4, distance1, distance2, distance3, distance4;

void setup() {
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
pinMode(trigPin4, OUTPUT);
pinMode(echoPin4, INPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
servo.attach(5);
servo.write(90);
Serial.begin(9600);
}

void loop() {
//distance for hcsr_04 #1
digitalWrite(trigPin1, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin1, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin1, LOW);
 duration1 = pulseIn(echoPin1, HIGH);

 //Calculate the distance (in cm) based on the speed of sound.
 distance1 = duration1/58.2;


//distance for hcsr_04 #2
digitalWrite(trigPin2, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin2, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin2, LOW);
 duration2 = pulseIn(echoPin2, HIGH);

 //Calculate the distance (in cm) based on the speed of sound.
 distance2 = duration2/58.2;


//distance for hcsr_04 #3
digitalWrite(trigPin3, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin3, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin3, LOW);
 duration3 = pulseIn(echoPin3, HIGH);

 //Calculate the distance (in cm) based on the speed of sound.
 distance3 = duration3/58.2;


//distance for hcsr_04 #4
digitalWrite(trigPin4, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin4, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin4, LOW);
 duration4 = pulseIn(echoPin4, HIGH);

 //Calculate the distance (in cm) based on the speed of sound.
 distance4 = duration4/58.2;


if (distance1 >= 60){
  distance1 == 60;
}

else if (distance2 >= 60){
  distance2 == 60;
}

else if (distance3 >= 60){
  distance4 == 60;
}

else if (distance4 >= 60){
  distance4 == 60;
}

else if (distance1 <= 5){
  distance1 == 60;
}

else if (distance2 <= 5){
  distance2 == 60;
}

else if (distance3 <= 5){
  distance3 == 60;
}

else if (distance4 <= 5){
  distance4 == 60;
}
if (distance1 < distance2 && distance1 < distance3 && distance1 < distance4)
{

servo.write(50);  
digitalWrite(4, HIGH);
digitalWrite(3, LOW);
digitalWrite(2, LOW);

}

else if (distance2 < distance1 && distance2 < distance3 && distance2 < distance4)
{

servo.write(70);    
digitalWrite(4, HIGH);
digitalWrite(3, LOW);
digitalWrite(2, LOW);

}

else if (distance3 < distance2 && distance3 < distance1 && distance3 < distance4)
{

servo.write(100);    
digitalWrite(2, HIGH);
digitalWrite(3, LOW);
digitalWrite(4, LOW);

}

else if (distance4 < distance2 && distance4 < distance3 && distance4 < distance1)
{

servo.write(130);    
digitalWrite(2, HIGH);
digitalWrite(3, LOW);
digitalWrite(4, LOW);

}

else if (distance4 > 50 && distance3 > 50 && distance2 > 50 && distance1 > 50)
{

servo.write(90);    
digitalWrite(3, HIGH);
digitalWrite(2, LOW);
digitalWrite(4, LOW);

}

}
