const int sensorPin = 0;
int lightLevel, high = 0, low = 1023;
void setup()
{  
  Serial.begin(9600);
  pinMode(8,OUTPUT);
}


void loop()
{

  lightLevel = analogRead(sensorPin);
  Serial.println(lightLevel);
  if (lightLevel > 820){
    digitalWrite(8,LOW);
  }
  else {
    digitalWrite(8,HIGH);
  }
}
