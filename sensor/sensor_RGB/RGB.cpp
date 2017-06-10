#include "Arduino.h"
#include "RGB.h"


int sensorPinNum;

void sensorInit(int _sensorPinNum){
  sensorPinNum=_sensorPinNum;
  pinMode(sensorPinNum, OUTPUT);
}

int red = 0, green = 0, blue = 0;
int temp = 0;

void readTemp(int temp) {
  if(temp <= 25) {
    analogWrite(3, 0);
    analogWrite(5, 0);
    analogWrite(9, 255);
  } else if(temp >= 26 && temp < 41) {
    analogWrite(3, 0);
    analogWrite(9, 0);
    analogWrite(5, 255);
  } else if(temp >42) {
    analogWrite(5, 0);
    analogWrite(9, 0);
    analogWrite(3, 255);
    delay(1000 % (temp % 33));
    analogWrite(3, 0);
    delay(1000 % (temp % 33));

  }
}
