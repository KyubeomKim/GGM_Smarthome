#include "temp.h"
#include "Arduino.h"


void initTemp(int _sensorPinNum)
{
	int sensorPinNum = _sensorPinNum;
	pinMode(sensorPinNum, INPUT);
}

float getTemp()
{
	float temperature;
	int reading;

	reading = analogRead(sensorPinNum);
	temperature = reading / 9.31;

 return temperature;
}
