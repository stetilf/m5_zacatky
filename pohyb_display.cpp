#include <M5StickCPlus.h>
#include "BluetoothSerial.h"


BluetoothSerial SerialBT;

//int ax,ay,az=0;
int x,y=0;

int Px=20,Py=20;
int dir=0;

//135*240
void setup() {
   SerialBT.begin("PAN_STUDENT"); //Bluetooth device name
   M5.begin();
   M5.Lcd.fillScreen(BLACK);
   //M5.Lcd.setRotation(1);
   //delay(20000);
   //M5.Imu.getAccelAdc(ax,ay,az);
}
void loop() {
   //254x63

   M5.Lcd.drawCircle(Px,Py,20, RED);

//   M5.Lcd.fillRect(10,10,10,20, RED);
//   M5.Lcd.fillRect(10+3,10+3,10-3,20-3, BLACK);
   
   delay(100);
   if (dir==0) Px+=10;
   if (dir==0) if (Px>=100) dir=1;
   if (dir==1) Py+=10;
   if (dir==1) if (Py>=200) dir=2;
   
   
  //M5.Lcd.drawXBitmap(10, 10, logo,50, 50, BLACK);
  // M5.Lcd.drawRect(mx,my,mx+10,my+10,RED);
  // M5.Lcd.drawRect(mx,my,mx+10,my+10,RED);
   //delay(10000);
   M5.Lcd.fillScreen(BLACK);
   }
