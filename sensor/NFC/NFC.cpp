#include "NFC.h"
#include "Arduino.h"

int initChipSelectPin(int _CSpin)
{
	int CSpin = _CSpin;
	pinMode(CSpin, OUTPUT);

 return CSpin;
}

int initBuzzer(int _Buzzer)
{
	int Buzzer = _Buzzer;
	pinMode(Buzzer, OUTPUT);

  return Buzzer;
}

int initNRSTPD(int _Rst)
{
	int Rst = _Rst;
	pinMode(Rst, OUTPUT);

 return Rst;
}


