#include <M5StickCPlus.h>
#include <pgmspace.h>  // PROGMEM support header
#include "image.h"
#include "142x106.h"


//135*240
void setup() {
   M5.begin();
   M5.Lcd.fillScreen(WHITE);
   //M5.Lcd.setRotation(1);
   //delay(20000);
   //M5.Imu.getAccelAdc(ax,ay,az);
}

void loop() {
  M5.Lcd.drawBitmap(0, 0, 142, 106, image_data_142x106);

  delay(10000);
  M5.Lcd.fillScreen(BLACK);
}
