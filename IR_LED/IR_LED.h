void initLED(int _LEDPinNum);          // LED VCC 포트 번호
void ledOutput();                      // LED 출력 함수
void led(int ledDefault);
uint16_t IRInt(uint16_t resultCode);   // 어느 버튼이 눌렸는지 시리얼에서 확인 함수
int ir_ledBright(uint16_t resultCode); // +/-버튼에 따라서 LED밝기 조절하는 함수
