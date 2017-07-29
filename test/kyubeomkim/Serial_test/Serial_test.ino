#include <SoftwareSerial.h>

SoftwareSerial taekyun(4,3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial Start");
  taekyun.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  // 수신
  taekyun.listen();
  if (taekyun.available()){
    char c = (char)taekyun.read();
    Serial.println(c);
  }

  // 송신
  if (Serial.available()){
    char c = Serial.read();
    Serial.print("input value (print) : ");
    Serial.println(c);
    Serial.print("input value (write) : ");
    Serial.write(c);
    taekyun.write(c);
  }
}
