#include <Arduino.h>

int ledPort1;
int ledPort2;
int ledPort3;

// wifi로 제어할 LED 출력 포트 설정
void initLED(int port_1, int port_2, int port_3) {
  ledPort1 = port_1;
  ledPort2 = port_2;
  ledPort3 = port_3;
  pinMode(port_1,OUTPUT);
  pinMode(port_2,OUTPUT);
  pinMode(port_3,OUTPUT);
}

// LED 출력포트 초기 상태 설정
void lowWriteLED() {
  digitalWrite(ledPort1,LOW);
  digitalWrite(ledPort2,LOW);
  digitalWrite(ledPort3,LOW);
}

