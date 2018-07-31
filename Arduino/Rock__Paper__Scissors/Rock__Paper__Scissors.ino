#include <LiquidCrystal.h>
#include <Servo.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int Rock = 6;
const int Paper = 7;
const int Scissor = 8;
const int Blue = 9;
const int Red = 10;
const int Green = 13;
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
long randomNumber;
int arduinoPlayer = 0;
int needArduino = 0;
int needPlayer = 0;
int Player = 0;
int score = 0;
Servo thumb;
Servo pointer;
Servo middle;
Servo ring;
Servo pinky;
void setup() {
  // put your setup code here, to run once:
thumb.attach(A0);
pointer.attach(A2);
middle.attach(A3);
ring.attach(A4);
pinky.attach(A5);
thumb.write(0);
pointer.write(0);
middle.write(0);
ring.write(0);
pinky.write(0);
pinMode(Rock, INPUT);
pinMode(Paper, INPUT);
pinMode(Scissor, INPUT);
pinMode(Blue, OUTPUT);
pinMode(Red, OUTPUT);
pinMode(Green, OUTPUT);
randomSeed(analogRead(A1));
lcd.begin(16, 2);
lcd.setCursor(3,0);
lcd.print("You Wanna");
lcd.setCursor(4,1);
lcd.print("Play Me?");
delay(1500);
lcd.clear();
lcd.print("Blue = Rock");
delay(1500);
lcd.clear();
lcd.print("Red = Paper");
delay(1500);
lcd.clear();
lcd.print("Green = Scissors");
delay(1500);
lcd.clear();
lcd.print("GO!");
}

void loop() {
  // put your main code here, to run repeatedly:
buttonState1 = digitalRead(Rock);
buttonState2 = digitalRead(Paper);
buttonState3 = digitalRead(Scissor);
/*
if (buttonState1 == HIGH) {
  digitalWrite(Blue, HIGH);
  digitalWrite(Red, LOW);
  digitalWrite(Green, LOW);
}

else if (buttonState2 == HIGH) {
  digitalWrite(Red, HIGH);
  digitalWrite(Blue, LOW);
  digitalWrite(Green, LOW);
}

else if (buttonState3 == HIGH) {
  digitalWrite(Green, HIGH);
  digitalWrite(Red, LOW);
  digitalWrite(Blue, LOW);
}
*/


if (needPlayer == 0){

  if (buttonState1 == HIGH) {     
    // turn LED on:    
    Player = 1;
    needPlayer = 1;
  } 
  else if (buttonState2 == HIGH) {
    // turn LED off:
    Player = 2;
    needPlayer = 1;
  }
  else if (buttonState3 == HIGH) {
    // turn LED off:
    Player = 3;
    needPlayer = 1;
  }
}
 
if (needArduino == 0 and needPlayer == 1){
  randomNumber = random(1,4);
  digitalWrite(Blue, LOW);
  digitalWrite(Red, LOW);
  digitalWrite(Green, LOW);
  if (randomNumber == 1){
    arduinoPlayer = 1;
    needArduino == 1;
    digitalWrite(Blue, HIGH);
    digitalWrite(Red, LOW);
    digitalWrite(Green, LOW);
  }
  else if (randomNumber == 2){
    arduinoPlayer = 2;
    needArduino == 1;
    digitalWrite(Blue, LOW);
    digitalWrite(Red, HIGH);
   digitalWrite(Green, LOW);
  }
  else if (randomNumber == 3){
    arduinoPlayer = 3;
    needArduino == 1;
    digitalWrite(Blue, LOW);
    digitalWrite(Red, LOW);
    digitalWrite(Green, HIGH);
  }
} 
 if (arduinoPlayer != 0 && Player != 0) {
    
    // Decide who won and adjust the score.
    if (arduinoPlayer == 1 && Player == 2 ) {
      score = score + 1;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("YOU: Paper");
      lcd.setCursor(0,1);
      lcd.print("ME: Rock");
      /*
      thumb.write(180);
      pointer.write(180);
      middle.write(180);
      ring.write(180);
      pinky.write(180);*/
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print ("YOU WIN!!");
      lcd.setCursor(0,1);
      lcd.print("Score: ");
      lcd.setCursor(7,1);
      lcd.print(score);
      needArduino = 0;
      needPlayer = 0;
    }
    
    else if (arduinoPlayer == 2 && Player == 3) {
      score = score + 1;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("YOU: Scissors");
      lcd.setCursor(0,1);
      lcd.print("ME: Paper");
      /*
      thumb.write(0);
      pointer.write(0);
      middle.write(0);
      ring.write(0);
      pinky.write(0);
      */
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print ("YOU WIN!!");
      lcd.setCursor(0,1);
      lcd.print("Score: ");
      lcd.setCursor(7,1);
      lcd.print(score);
      needArduino = 0;
      needPlayer = 0;

    }    
   
    else if (arduinoPlayer == 3 && Player == 1) {
      score = score + 1;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("YOU: Rock");
      lcd.setCursor(0,1);
      lcd.print("ME: Scissors");
      /*
      thumb.write(180);
      pointer.write(0);
      middle.write(0);
      ring.write(180);
      pinky.write(180);
      */
      delay(1000);      
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print ("YOU WIN!!");
      lcd.setCursor(0,1);
      lcd.print("Score: ");
      lcd.setCursor(7,1);
      lcd.print(score);
      needArduino = 0;
      needPlayer = 0;
    }  
    
    else if (arduinoPlayer == 1 && Player == 3) {
      score = score - 1;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("YOU: Scissors");
      lcd.setCursor(0,1);
      lcd.print("ME: Rock");
      /*
      thumb.write(180);
      pointer.write(180);
      middle.write(180);
      ring.write(180);
      pinky.write(180);
      */
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print ("you lose :(");      
      lcd.setCursor(0,1);
      lcd.print("Score: ");
      lcd.setCursor(7,1);
      lcd.print(score);
      needArduino = 0;
      needPlayer = 0;
    }
    
    else if (arduinoPlayer == 2 && Player == 1) {
      score = score - 1;    
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("YOU: Rock");
      lcd.setCursor(0,1);
      lcd.print("ME: Paper");
      /*
      thumb.write(0);
      pointer.write(0);
      middle.write(0);
      ring.write(0);
      pinky.write(0);
      */
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print ("you lose :(");      
      lcd.setCursor(0,1);
      lcd.print("Score: ");
      lcd.setCursor(7,1);
      lcd.print(score);
      needArduino = 0;
      needPlayer = 0;
    }
    
    else if (arduinoPlayer == 3 && Player == 2) {
      score = score - 1;     
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("YOU: Paper");
      lcd.setCursor(0,1);
      lcd.print("ME: Scissors");
      /*
      thumb.write(180);
      pointer.write(0);
      middle.write(0);
      ring.write(180);
      pinky.write(180);
      */
      delay(1000);      
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print ("you lose :(");      
      lcd.setCursor(0,1);
      lcd.print("Score: ");
      lcd.setCursor(7,1);
      lcd.print(score);
      needArduino = 0;
      needPlayer = 0;
    } 
    
    else if (arduinoPlayer == 3 && Player == 3) {
      score = score;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("YOU: Scissors");
      lcd.setCursor(0,1);
      lcd.print("ME: Scissors");
      /*thumb.write(180);
      pointer.write(0);
      middle.write(0);
      ring.write(180);
      pinky.write(180);
      */
      delay(1000);      
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print ("tie");      
      lcd.setCursor(0,1);
      lcd.print("Score: ");
      lcd.setCursor(7,1);
      lcd.print(score);
      needArduino = 0;
      needPlayer = 0;
    }

    else if (arduinoPlayer == 2 && Player == 2) {
      score = score;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("YOU: Paper");
      lcd.setCursor(0,1);
      lcd.print("ME: Paper");
      /*
      thumb.write(0);
      pointer.write(0);
      middle.write(0);
      ring.write(0);
      pinky.write(0);
      */
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print ("tie");      
      lcd.setCursor(0,1);
      lcd.print("Score: ");
      lcd.setCursor(7,1);
      lcd.print(score);
      needArduino = 0;
      needPlayer = 0;
    }

    else if (arduinoPlayer == 1 && Player == 1) {
      score = score;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("YOU: Rock");
      lcd.setCursor(0,1);
      lcd.print("ME: Rock");
      /*
      thumb.write(180);
      pointer.write(180);
      middle.write(180);
      ring.write(180);
      pinky.write(180);
      */
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print ("tie");      
      lcd.setCursor(0,1);
      lcd.print("Score: ");
      lcd.setCursor(7,1);
      lcd.print(score);
      needArduino = 0;
      needPlayer = 0;
    }
    
    arduinoPlayer = 0;
    Player = 0;
 
 }


}
