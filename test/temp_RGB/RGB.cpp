#include "Arduino.h"
#include "RGB.h"


int sensorPinNum;

void sensorInit(int _sensorPinNum){
  sensorPinNum=_sensorPinNum;
  pinMode(sensorPinNum, OUTPUT);
}

void Blue()
  {
    analogWrite(3, 0);
    analogWrite(5, 0);
    analogWrite(9, 255);
  }
void Green()
  {
    analogWrite(3, 0);
    analogWrite(9, 0);
    analogWrite(5, 255);
  }
void Red()
  {
    analogWrite(5, 0);
    analogWrite(9, 0);
    analogWrite(3, 255);
  }

