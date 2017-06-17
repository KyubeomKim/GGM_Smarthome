#include "tilt.h"

void setup() {
  initTilt(2);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(tiltSwitchReadInterval(50));
  digitalWrite(13,tiltSwitchReadInterval(50));
}
