#include "temp.h"

void setup()
{
	analogReference(INTERNAL);
	Serial.begin(9600);
}

void loop()
{
	getTemp();	
	Serial.println(getTemp());
	delay(1000);
}


