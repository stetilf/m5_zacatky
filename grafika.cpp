#include <M5StickCPlus.h>
#include "BluetoothSerial.h"
#include "xbm.h"

BluetoothSerial SerialBT;

//int ax,ay,az=0;
int mx=0,my=0;
int x,y=0;

void setup() {
   SerialBT.begin("PANUCITEL"); //Bluetooth device name
   M5.begin();
   M5.Lcd.fillScreen(0xdcc4);
   //M5.Lcd.setRotation(1);
   delay(20000);
   //M5.Imu.getAccelAdc(ax,ay,az);
}
void loop() {
   //254x63

   M5.Lcd.drawRect(10,10,10,20, RED);
   delay(1000);
   M5.Lcd.drawRect(10,10,10,20, GREEN);
   delay(1000);
   M5.Lcd.fillScreen(BLACK);
   
   

   //M5.Lcd.drawXBitmap(10, 10, logo,50, 50, BLACK);
  // M5.Lcd.drawRect(mx,my,mx+10,my+10,RED);
  // M5.Lcd.drawRect(mx,my,mx+10,my+10,RED);
   //delay(10000);
   //M5.Lcd.fillScreen(WHITE);
   delay(2000);   
   }
