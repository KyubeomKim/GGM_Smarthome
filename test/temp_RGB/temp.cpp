#include "temp.h"
#include "Arduino.h"

float temperature;
int reading;
int lm35Pin = A0;

float getTemp()
{
	reading = analogRead(lm35Pin);
	temperature = reading/9.31;
  Serial.println(reading);
  Serial.println(temperature);

 return temperature;
}

