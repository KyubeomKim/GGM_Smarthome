#include "Arduino.h"
#include "tilt.h"

// 기본 함수 전역변수
int sensorPinNum;

// tiltSwitchReadInterval() 전역변수
long time = 0; // 최종으로 상태값이 바뀐 시간
int previous = LOW; // 이전 기울기 상태 저장 변수
int reading; // 현재 기울기 상태 저장 변수
int result = HIGH; // 리턴 값 최초정의

void initTilt(int _sensorPinNum){
  sensorPinNum=_sensorPinNum;
  pinMode(sensorPinNum, INPUT);
}

int tiltSwitchRead() {
  return digitalRead(sensorPinNum);
}

int tiltSwitchReadInterval(int _interval){
  reading = tiltSwitchRead();
 
  // If the switch changed, due to bounce or pressing...
  if (reading != previous) {
    // reset the debouncing timer
    time = millis();
  } 
 
  if ((millis() - time) > _interval) {
     result = reading;
  } 
  // Save the last reading so we keep a running tally
  previous = reading;
  return result;
}

