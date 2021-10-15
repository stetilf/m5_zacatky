#include <M5StickCPlus.h>
#include <pgmspace.h>  // PROGMEM support header
#include "mfiles.h"

//135*240
void setup() {
   M5.begin();
   M5.Lcd.fillScreen(BLACK);
   //M5.Lcd.setRotation(1);
   //delay(20000);
   //M5.Imu.getAccelAdc(ax,ay,az);
}

int cekam=100;

void loop() {

M5.Lcd.drawBitmap(0, 0, 22, 29, ma1);
delay(cekam);
M5.Lcd.drawBitmap(0, 0, 22, 29, ma2);
delay(cekam);
M5.Lcd.drawBitmap(0, 0, 22, 29, ma3);
delay(cekam);
M5.Lcd.drawBitmap(0, 0, 22, 29, ma4);
delay(cekam);
M5.Lcd.drawBitmap(0, 0, 22, 29, ma5);
delay(cekam);
M5.Lcd.drawBitmap(0, 0, 22, 29, ma6);
delay(cekam);
M5.Lcd.drawBitmap(0, 0, 22, 29, ma7);
delay(cekam);
M5.Lcd.drawBitmap(0, 0, 22, 29, ma8);

//.Lcd.drawBitmap()

//M5.Lcd.drawXBitmap(10, 10, image_data_61x61,61, 61);
// M5.Lcd.drawRect(mx,my,mx+10,my+10,RED);
// M5.Lcd.drawRect(mx,my,mx+10,my+10,RED);
//delay(10000);
//M5.Lcd.fillScreen(BLACK);
}
