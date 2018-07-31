/* Read Jostick
  * ------------
  *
  * Reads two analog pins that are supposed to be
  * connected to a jostick made of two potentiometers
  *
  * We send three bytes back to the comp: one header and two
  * with data as signed bytes, this will take the form:
  *     Jxy\r\n
  *
  * x and y are integers and sent in ASCII 
  * 
  * http://www.0j0.org | http://arduino.berlios.de
  * copyleft 2005 DojoDave for DojoCorp
  */

 int joyPin1 = 2;                 // slider variable connecetd to analog pin 0
 int joyPin2 = 3;                 // slider variable connecetd to analog pin 1
 int value1 = 0;                  // variable to read the value from the analog pin 0
 int value2 = 0;                  // variable to read the value from the analog pin 1

 void setup() {
              // initializes digital pins 0 to 7 as outputs
  Serial.begin(9600);
 }


 void loop() {
  // reads the value of the variable resistor 
  //value1 = 100-map(analogRead(joyPin2),0,1023,0,100);   
  // this small pause is needed between reading
  // analog pins, otherwise we get the same value twice           
  // reads the value of the variable resistor 
  //value2 = 0-map(analogRead(joyPin1),0,1023,-200,200); 
  value1 = 1023-analogRead(joyPin2);
  value2 = 1023-analogRead(joyPin1);  
  Serial.print("X:  ");
  Serial.print(value1);
  Serial.print("   ");
  Serial.print("Y:  ");
  Serial.println(value2);
 }
