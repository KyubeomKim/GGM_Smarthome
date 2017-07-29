#include "Arduino.h"
#include "WiFiShield_test.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if(Serial.available()){
    Serial.println("GGM WiFi Start");
  }
  initLED(11,12,13);
}

void loop() {
  // put your main code here, to run repeatedly:
  //char inputString = Serial.read();
  
  lowWriteLED();
  long inputValue = Serial.parseInt();
  Serial.print("input value : ");
  Serial.println(inputValue);
  switch (inputValue) {
    case 1:
      digitalWrite(11,HIGH);
      break;
    case 2:
      digitalWrite(12,HIGH);
      break;
    case 3:
      digitalWrite(13,HIGH);
      break;
  }
  delay(2000);
}
