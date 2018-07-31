#define echopin 7
#define trigpin 6
long duration, distance;
void setup() {
  // put your setup code here, to run once:
  pinMode(echopin,INPUT);
  pinMode(trigpin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  duration = pulseIn(echopin,HIGH);
  distance = duration/58.2;
  Serial.println(distance);
}
