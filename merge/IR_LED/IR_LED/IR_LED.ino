// IR 리코먼 수신 센서 통신을 위해 IRremote.h 헤더 파일을 include 한다.
#include "IRremote.h"
#include "IR_LED.h"


// 각 핀(Pin) 정의
int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;       // IR 수신 코드를 저장
uint16_t lastCode = 0;          // RX'd 마지막 코드 유지

void setup() {                  
  Serial.begin(9600);
  initLED(11);                  // LED 전원부 핀
  irrecv.enableIRIn();          // 수신 센서 감지 시작(Start the receiver)
}

// IR 리모컨 버튼을 누르면 적외선 신호를 IR 리모컨 수신 센서가 감지하며, 수신된 데이터 값을 분석 한 후 
// 수신 값을 시리얼 통신을 이용해 전송하여 PC에서 확인하도록 한다.
void loop() {
  if(irrecv.decode(&results)) {
    // RX'd IR을 16bit으로 함
    uint16_t resultCode = (results.value & 0xFFFF);
    if(resultCode == 0xFFFF) {
      resultCode = lastCode;
    } else {
      lastCode = resultCode;
    }
    
    IRInt(resultCode);
    ir_ledBright(resultCode);
    ledOutput();
    irrecv.resume();    // 다음 값 수신(Receive the next value)
  }
}

