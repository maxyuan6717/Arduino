/*int tx=1;
int rx=0;
int led = 11;
char inSerial[15];
// motor one
int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;

void setup(){
  Serial.begin(9600);
  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(led,OUTPUT);
}

void loop(){
    int i=0;
    int m=0;
    delay(500);                                         
    if (Serial.available() > 0) {             
       while (Serial.available() > 0) {
         inSerial[i]=Serial.read(); 
         i++;      
       }
       inSerial[i]='\0';
      Check_Protocol(inSerial);
     }} 
  
  
void Check_Protocol(char inStr[]){   
  int i=0;
  int m=0;
  Serial.println(inStr);
  
  if(!strcmp(inStr,"F")){      //Forward
    digitalWrite(led,HIGH);
    forward();
   
    for(m=0;m<11;m++){
      inStr[m]=0;}
       i=0;}
  if(!strcmp(inStr,"B")){      //Backward
    backward();
    for(m=0;m<11;m++){
      inStr[m]=0;}
       i=0;}     
  if(!strcmp(inStr,"L")){      //Left
    left();
    for(m=0;m<11;m++){
      inStr[m]=0;}
       i=0;}    
  
  if(!strcmp(inStr,"R")){      //Right
    right();
    for(m=0;m<11;m++){
      inStr[m]=0;}
       i=0;}     
  if(!strcmp(inStr,"S")){      //Stop
    halt();
    for(m=0;m<11;m++){
      inStr[m]=0;}
       i=0;}        
   else{
     for(m=0;m<11;m++){
       inStr[m]=0;
     }
   i=0;
  }
  
}
void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  
  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 200);
  analogWrite(enB, 214);
}

void backward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 140);
  analogWrite(enB, 150);
}
void left() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 150);
  analogWrite(enB, 150);
}
void right() {
  digitalWrite(in2, LOW);
  digitalWrite(in1, HIGH); 
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
  analogWrite(enA, 150);
  analogWrite(enB, 150);
}
void halt() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}*/
int led = 11;
char command = 'S';
char prevCommand = 'A';  
unsigned long timer0 = 2000;  //Stores the time (in millis since execution started) 
unsigned long timer1 = 0;  //Stores the time when the last command was received from the phone
// motor one
/*int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;*/
#include <Servo.h>
Servo lservo;
Servo rservo;
void setup() 
{       
  Serial.begin(9600);  //Set the baud rate to that of your Bluetooth module.
  /*pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);*/
  pinMode(led,OUTPUT);
  lservo.attach(4);
  rservo.attach(3);
  lservo.write(90);
  rservo.write(90);

}

void loop(){
  if(Serial.available() > 0){ 
    timer1 = millis();   
    prevCommand = command;
    command = Serial.read(); 
    //Change pin mode only if new command is different from previous.   
    if(command!=prevCommand){
      //Serial.println(command);
      switch(command){
      case 'F':  
        
        f();
        break;
      case 'B':  
        b();
        break;
      case 'L':  
        l();
        break;
      case 'R':
        r(); 
        break;
      case 'S':  
        s();
        break; 
      case 'I':  //FR  
        fr();
        break; 
      case 'J':  //BR  
        br();
        break;        
      case 'G':  //FL  
        fl();
        break; 
      case 'H':  //BL
        bl();
        break;       
      
      }
    }
  }
  else{
    timer0 = millis();  //Get the current time (millis since execution started).
    //Check if it has been 500ms since we received last command.
    if((timer0 - timer1)>500){  
      //More tan 500ms have passed since last command received, car is out of range.
      //Therefore stop the car and turn lights off.
  
      s();
    }
  }  
}
void f() {
  lservo.write(180);
  rservo.write(0);
}
void b() {
  lservo.write(0);
  rservo.write(180);
}
void r() {
  lservo.write(180);
  rservo.write(180);
}
void l() {
  lservo.write(0);
  rservo.write(0);
}
void s() {
  lservo.write(90);
  rservo.write(90);
}
void fl() {
  lservo.write(90);
  rservo.write(0);
}
void fr() {
  lservo.write(180);
  rservo.write(90);
}
void bl() {
  lservo.write(90);
  rservo.write(180);
}
void br() {
  lservo.write(0);
  rservo.write(90);
}
/*void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  
  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 250);
  analogWrite(enB, 255);
}

void backward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 250);
  analogWrite(enB, 255);
}
void left() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW); 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  analogWrite(enB, 140);
}
void right() {
  digitalWrite(in2, LOW);
  digitalWrite(in1, HIGH); 
  digitalWrite(in4, LOW);
  digitalWrite(in3, LOW);
  analogWrite(enA, 140);
  
}
void halt() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void forwardl() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  
  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 180);
  analogWrite(enB, 255);
}
void forwardr() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  
  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 255);
  analogWrite(enB, 180);
}
void backwardl() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 220);
  analogWrite(enB, 255);
}
void backwardr() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 255);
  analogWrite(enB, 220);
}*/

  
