void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

void loop() {
  //  기존 코드
//  int outLux = analogRead(A0);
//  int bias = 130;
//  int ledLux = 255-bias-outLux/4;
//  if (ledLux < 0){
//    ledLux=0;
//  }
//  Serial.println(ledLux);
//  //Serial.println(outLux);
//  analogWrite(3, ledLux);

  // 함수 사용
  analogWrite(3, sensor_lux(0,130));

}

int sensor_lux(int _sensor_pin, int _bias) {
  int outLux = analogRead(_sensor_pin);
  int bias = _bias;
  int ledLux = 255-bias-outLux/4;
  if (ledLux < 0){
    ledLux=0;
  }
  Serial.println(ledLux);
  //Serial.println(outLux);
  return ledLux;
}

