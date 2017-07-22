#include <AddicoreRFID.h>
#include <SPI.h>
#include "NFC.h"
#include "Arduino.h"
 
#define uchar   unsigned char
#define uint    unsigned int
#define MAX_LEN 16

uchar serNumA[5];
uchar fifobytes;
uchar fifoValue;

AddicoreRFID myRFID;

void setup()
{               
  Serial.begin(9600);                         
 
  SPI.begin();

  digitalWrite(initChipSelectPin(10), LOW);
  
  digitalWrite(initNRSTPD(9), HIGH);
 
  digitalWrite(initBuzzer(8), LOW);

  myRFID.AddicoreRFID_Init(); 
}
 
void loop()
{
  uchar i, tmp, checksum1;
  uchar status;
  uchar str[MAX_LEN];
  uchar RC_size;
  uchar blockAddr;
  String mynum = "";
  str[1] = 0x4400;
   
 
    status = myRFID.AddicoreRFID_Request(PICC_REQIDL, str);
    if (status == MI_OK)
    {
          Serial.println("RFID tag detected");
            Serial.print(str[0],BIN);
          Serial.print(" , ");
            Serial.print(str[1],BIN);
          Serial.println(" ");
          digitalWrite(initBuzzer(8), HIGH);
            delay(50);
          digitalWrite(initBuzzer(8), LOW);
            delay(50);
    }
 
    status = myRFID.AddicoreRFID_Anticoll(str);
    if (status == MI_OK)
    {
      checksum1 = str[0] ^ str[1] ^ str[2] ^ str[3];
      Serial.println("The tag's number is  : ");
      Serial.print(str[0]);
      Serial.print(" , ");
      Serial.print(str[1],BIN);
      Serial.print(" , ");
      Serial.print(str[2],BIN);
      Serial.print(" , ");
      Serial.print(str[3],BIN);
      Serial.print(" , ");
      Serial.print(str[4],BIN);
      Serial.print(" , ");
      Serial.println(checksum1,BIN);
      

      if(str[0] == 48)
      {               
        Serial.print("Hello taekyun!\n");
      } else if(str[0] == 208) {           
        Serial.print("Hello byungsin!\n");
      }
      Serial.println();
      delay(1000);
    }
         
        myRFID.AddicoreRFID_Halt();             
 
}
