#include "lux.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  initLux(0);
  pinMode(3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(getLuxScaleDownReverse(-130));
  analogWrite(3, getLuxScaleDownReverse(-130));
}
