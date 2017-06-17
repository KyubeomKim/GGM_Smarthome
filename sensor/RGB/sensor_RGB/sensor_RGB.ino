#include "RGB.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  sensorInit(3);
  sensorInit(5);
  sensorInit(9);
  
  Serial.println(readTemp());
  readTemp();

}

