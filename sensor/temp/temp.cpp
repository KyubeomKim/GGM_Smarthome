#include "temp.h"
#include "Arduino.h"

int sensorPinNum;

void initTemp(int _sensorPinNum)
{
	sensorPinNum = _sensorPinNum;
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
