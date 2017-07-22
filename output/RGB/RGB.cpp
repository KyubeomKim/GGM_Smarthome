#include "Arduino.h"
#include "RGB.h"

int initR, initG, initB;          // RGB 출력 포트

// RGB 출력 포트 설정 함수
void initRgb(int _initR, int _initG, int _initB){
  initR = _initR;
  initG = _initG;
  initB = _initB;
  pinMode(_initR, OUTPUT);
  pinMode(_initG, OUTPUT);
  pinMode(_initB, OUTPUT);
}

// float형 temp를 int형으로 변환
int changeToIntTemp(float floatTemp) {
  int intTemp = (int)floatTemp;
  return intTemp;
}

// 온도에 따라 RGB 출력 함수
void readTemp(float floatTemp, int sectionR, int sectionB) {
  
  int temp = changeToIntTemp(floatTemp);
  if(temp <= sectionB) {
    lightB(255);
  } else if(temp > sectionB && temp < sectionR) {
    lightG(255);
  } else if(temp > sectionR) {
    lightR(255);
    delay(500);
    lightR(0);

  }
  
}

// R을 키는 함수
void lightR(int bright) {
    analogWrite(initG, 0);
    analogWrite(initB, 0);
    analogWrite(initR, bright);
}

// G을 키는 함수
void lightG(int bright) {
    analogWrite(initR, 0);
    analogWrite(initB, 0);
    analogWrite(initG, bright);
}

// B을 키는 함수
void lightB(int bright) {
    analogWrite(initR, 0);
    analogWrite(initG, 0);
    analogWrite(initB, bright);
}
