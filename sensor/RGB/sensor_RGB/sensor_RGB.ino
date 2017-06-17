#include "RGB.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initRgb(3, 5, 9);
}

void loop() {

  // 45도 이상 R,24도이상 45도 이하 G, 24도이하 B 키기
  readTemp(50, 45, 24);     // R 켜짐
  delay(1000);
  readTemp(30.5, 45, 24);    // G 켜짐
  delay(1000);
  readTemp(20, 45, 24);     // B 켜짐
  delay(1000);

}

