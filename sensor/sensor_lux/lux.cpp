#include "Arduino.h"
#include "lux.h"

int sensorPinNum;

void sensorInit(int _sensorPinNum){
  sensorPinNum=_sensorPinNum;
  pinMode(sensorPinNum, OUTPUT);
}

int getLux(int _bias=0){
  int lux =analogRead(sensorPinNum)+_bias; 
  if (lux<0) {
    lux = 0;
  }
  return lux;
}

int getLuxScaleDown(int _bias=0){
  int lux =analogRead(sensorPinNum)/4+_bias;
  if (lux<0) {
    lux = 0;
  }
  return lux;
}

int getLuxReverse(int _bias=0){
  int lux =1024-analogRead(sensorPinNum)+_bias;
  if (lux<0) {
    lux = 0;
  }
  return lux;
}

int getLuxScaleDownReverse(int _bias=0){
  int lux =255-analogRead(sensorPinNum)/4+_bias;
  if (lux<0) {
    lux = 0;
  }
  return lux;
}
