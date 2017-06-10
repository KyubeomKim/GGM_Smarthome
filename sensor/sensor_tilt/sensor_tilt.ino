#include "tilt.h"

void setup() {
  tiltInit(2);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13,tiltSwitchReadInterval(50));
}
