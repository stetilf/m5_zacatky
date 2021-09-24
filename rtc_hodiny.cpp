#include <M5StickCPlus.h>
//BluetoothSerial SerialBT;
//#include "BluetoothSerial.h"

RTC_TimeTypeDef TimeStruct;

void setup() {
   //SerialBT.begin("FIX"); //Bluetooth device name
   M5.begin();
   M5.Lcd.setRotation(2);
   M5.Lcd.fillScreen(BLACK);

   TimeStruct.Hours   = 12;
   TimeStruct.Minutes = 50;
   TimeStruct.Seconds = 10;
   M5.Rtc.SetTime(&TimeStruct);
   
}

void loop() {
  M5.Rtc.GetTime(&TimeStruct);
  M5.Lcd.setCursor(0, 15);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.printf("Time: %02d : %02d : %02d\n",TimeStruct.Hours, TimeStruct.Minutes, TimeStruct.Seconds);
  delay(500);
}
