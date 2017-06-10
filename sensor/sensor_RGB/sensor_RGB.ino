#include "RGB.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
//  pinMode(3,OUTPUT);
//  pinMode(5,OUTPUT);
//  pinMode(9,OUTPUT);
//
//  pinMode(11, OUTPUT);   // 온도센터 값
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorInit(3);
  sensorInit(5);
  sensorInit(9);
  sensorInit(11);
  
  Serial.println(readTemp());
  readTemp();

}

