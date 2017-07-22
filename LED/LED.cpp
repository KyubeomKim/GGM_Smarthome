#include "LED.h"
#include "Arduino.h"

int LEDPinNum;

void initLED(int _LEDPinNum) {
  LEDPinNum = _LEDPinNum;
  pinMode(_LEDPinNum, INPUT);

  return _LEDPinNum;
}

// LED 밝기 자동 조절
void ledBright() {
//  for(int i=0; i<256; i++) {
//    analogWrite(LEDPinNum, i);
//    delay(10);
//  }
//  for(int i=255; i>0; i--) {
//    analogWrite(LEDPinNum, i);
//    delay(10);
//  }

    analogWrite(LEDPinNum, 125);
    delay(50);
    analogWrite(LEDPinNum, 50);
    delay(50);
    analogWrite(LEDPinNum, 155);
    delay(50);
}
