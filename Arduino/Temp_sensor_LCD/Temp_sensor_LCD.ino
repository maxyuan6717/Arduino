#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <LCD.h>

#define I2C_ADDR    0x3F // <<----- Add your address here.  Find it from I2C Scanner
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7
const int temperaturePin = 0;
const int button = 2;
int buttonState = 0;
int num = 0;

LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

void setup() {
  // put your setup code here, to run once
  lcd.begin (16,2); //  <<----- My LCD was 16x2
  // Switch on the backlight
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperature");
  delay(1000);
  lcd.clear();
}

void loop() {
  delay(180);
  //lcd.clear();
  buttonState = digitalRead(button);
  // put your main code here, to run repeatedly:
  float voltage, degreesC, degreesF;
  voltage = getVoltage(temperaturePin);
  degreesC = (voltage-0.5)*100.0;
  degreesF = degreesC * (9.0/5.0) + 32.0;
  if (buttonState == HIGH && num == 0) {
    lcd.clear();
    num = 1;
  }
  else if (buttonState == HIGH && num == 1) {
    lcd.clear();
    num = 0;
  }
  
  if (num == 0) {
    lcd.setCursor(0,0);
    lcd.print("Fahrenheit");
    lcd.setCursor(0,1);
    lcd.print("Degrees: ");
    lcd.setCursor(9,1);
    lcd.print(degreesF);
  }
  else if (num == 1) {
    lcd.setCursor(0,0);
    lcd.print("Celsius");
    lcd.setCursor(0,1);
    lcd.print("Degrees: ");
    lcd.setCursor(9,1);
    lcd.print(degreesC);
  }
  
  
}
float getVoltage(int pin)
{

  return (analogRead(pin) * 0.004882814);

}


