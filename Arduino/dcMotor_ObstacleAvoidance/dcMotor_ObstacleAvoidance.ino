int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;
#define echo 4
#define trig 3
long duration, distance, distancel, distancer;
void setup() {
  // put your setup code here, to run once:
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  look();
  if (distance > 10) {
    forward();
  }
  else {
    backward();
    delay(300);
    halt();
    left();
    delay(100);
    halt();
    look();
    distancel = distance;
    right();
    delay(200);
    halt();
    look();
    distancer = distance;
    
    if (distancel > distancer && distancel > 10) {
      left();
      delay(200);
      forward();
    }
    else if (distancer > distancel && distancer > 10) {
      forward();
    }
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
}
void look() {
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  distance = duration/58.2;
  delay(100);
  
}

