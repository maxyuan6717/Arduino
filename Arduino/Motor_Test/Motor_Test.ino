#include "DualMC33926MotorShield.h"
DualMC33926MotorShield md;
void stopIfFault()
{
  if (md.getFault())
  {
    Serial.println("fault");
    while(1);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Dual MC33926 Motor Shield");
  md.init();
  md.setM1Speed(367);
  md.setM2Speed(400);
  delay(5600);
  md.setM1Speed(0);
  md.setM2Speed(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
