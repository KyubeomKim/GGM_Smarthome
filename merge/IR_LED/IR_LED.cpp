#include "Arduino.h"
#include "IR_LED.h"

// LED VDD 포트 설정 함수
int LEDPinNum;
void initLED(int _LEDPinNum) {
  LEDPinNum = _LEDPinNum;
  pinMode(LEDPinNum, OUTPUT);
}
// LED 초기 밝기 설정 함수
int ledBright;
void led(int ledDefault) {
  ledBright = ledDefault;
}

// LED 밝기 출력 함수
void ledOutput() {
  analogWrite(LEDPinNum, ledBright);
  //Serial.println(ledBright);
  //Serial.println(LEDPinNum);
}

// 어느 버튼이 눌렸는지 확인 함수
uint16_t IRInt(uint16_t resultCode) {
      switch(resultCode) {
        case 0x00FF6897: // key 0
        //Serial.println("Press '0'");
        break;
        case 0x00FF30CF: // key 1
        //Serial.println("Press '1'");
        break;
        case 0x00FF18E7: // key 2
        //Serial.println("Press '2'");
        break;
        case 0x00FF7A85: // key 3
        //Serial.println("Press '3'");
        break;
        case 0x00FF10EF: // key 4
        //Serial.println("Press '4'");
        break;
        case 0x00FF38C7: // key 5
        //Serial.println("Press '5'");
        break;
        case 0x00FF5AA5: // key 6
        //Serial.println("Press '6'");
        break;
        case 0x00FF42BD: // key 7
        //Serial.println("Press '7'");
        break;
        case 0x00FF4AB5: // key 8
        //Serial.println("Press '8'");
        break;
        case 0x00FF52AD: // key 9
        //Serial.println("Press '9'");
        break;
        case 0x00FFA25D: // key CH-
        //Serial.println("Press CH-");
        break;
        case 0x00FF629D: // key CH
        //Serial.println("Press CH");
        break;
        case 0x00FFE21D: // key CH+
        //Serial.println("Press CH+");
        break;
        case 0x00FF22DD: // key <<
        //Serial.println("Press <<");
        break;
        case 0x00FF02FD: // key >>
        //Serial.println("Press >>");
        break;
        case 0x00FFC23D: // key >||
        //Serial.println("Press 재생/정지");
        break;
        case 0x00FFE01F: // key VOL-
        Serial.println("Press VOL-");
        break;
        case 0x00FFA857: // key VOL+
        Serial.println("Press VOL+");
        break;
        case 0x00FF906F: // key EQ
        //Serial.println("Press EQ");
        break;
        case 0x00FF9867: // key 100+
        //Serial.println("Press 100+");
        break;
        case 0x00FFB04F: // key 200+
        //Serial.println("Press 200+");
        break;
        default:
        //Serial.println(resultCode);
        break;
      }
      return resultCode;
}



int ir_ledBright(uint16_t resultCode){

 Serial.print("*");
 Serial.print(resultCode);
  if(resultCode == 0x00FFA857) { // key VOL+
    ledBright = 255;
    Serial.print("+");
  }
  if(resultCode == 0x00FFE01F) { // key VOL-
    ledBright = 0;
    Serial.print("-");
  }
  Serial.print(" ");
  Serial.println(ledBright);
  
  return ledBright;
}

