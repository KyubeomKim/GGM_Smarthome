#include "Arduino.h"
#include "temp.h"
#include "RGB.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 Serial.println(getTemp());

 if (getTemp() < 10)
 {
 void Blue();
 }
 else if (getTemp() >= 10 && getTemp() < 28)
 {
 void Green();
 }
 else
 {
 void red();
 }

 }

