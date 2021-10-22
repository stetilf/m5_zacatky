#include <M5StickCPlus.h>
#include <pgmspace.h>  // PROGMEM support header
#include "mfiles.h"

float accX = 0.0F;
float accY = 0.0F;
float accZ = 0.0F;

float gyroX = 0.0F;
float gyroY = 0.0F;
float gyroZ = 0.0F;

float pitch = 0.0F;
float roll  = 0.0F;
float yaw   = 0.0F;

int canvas[200];
int canvasX=10;
int canvasY=0;
int i=0;
int j=0;
int rect_size=10;

//135*240
void setup() {
   M5.begin();
   M5.Lcd.fillScreen(BLACK);
   M5.Lcd.setRotation(0);
   //delay(20000);
   //M5.Imu.getAccelAdc(ax,ay,az);
   Serial.begin(115200);
   M5.Imu.Init();

 //M5.Lcd.drawRect(10,10,20,20,RED);
 //M5.Lcd.drawRect(20,20,30,30,BLUE);
M5.Lcd.setCursor(0,0);
 
M5.Lcd.setTextColor(WHITE);
M5.Lcd.setTextSize(5);
 
M5.Lcd.println("TEST");  
/*M5.Lcd.drawRect(0,0,10,10,RED);  
M5.Lcd.drawRect(1,1,98,98,GREEN);  
M5.Lcd.drawRect(2,2,97,97,BLUE);  */
//M5.Lcd.drawRect(50,50,0,60,WHITE);  


for(j=0;j<21; j++)
   {
   

   for(i=0;i<11; i++)
   {
    M5.Lcd.drawRect(canvasX+(rect_size*i),canvasY+10,rect_size,rect_size,RED);
    delay(500);
   }
   canvasY=canvasY+10;
  }
  

   /*
   {
     M5.Lcd.drawRect(canvasX+1,canvasY+1,canvasX+rect_size,canvasY+rect_size,RED);
    canvasX+=10;
    if (i%10==0) 
    {
      canvasY+=10;
      canvasX+=0;
    }
    delay(1000);
   }*/
}



int cekam=50;
int spriteX=0;
int spriteY=0;

void loop() {

  //M5.Imu.getGyroData(&gyroX,&gyroY,&gyroZ);
  M5.Imu.getAccelData(&accX,&accY,&accZ);
  //M5.Imu.getAhrsData(&pitch,&roll,&yaw);
  
  
  //Serial.printf("%6.2f  %6.2f  %6.2f o/s\n", gyroX, gyroY, gyroZ);
  //Serial.printf(" %5.2f   %5.2f   %5.2f G\n\n\n\n", accX, accY, accZ);
  //Serial.printf(" %5.2f   %5.2f   %5.2f\n", pitch, roll, yaw);

/*spriteX=round((accX*100)+100);
spriteY=100;
Serial.println(spriteX);
  */

//M5.Lcd.printf(0,50,accX);

/*
M5.Lcd.drawBitmap(spriteX, spriteY, 22, 29, ma1);
delay(cekam);
M5.Lcd.drawBitmap(spriteX, spriteY, 22, 29, ma2);
delay(cekam);
M5.Lcd.drawBitmap(spriteX, spriteY, 22, 29, ma3);
delay(cekam);
M5.Lcd.drawBitmap(spriteX, spriteY, 22, 29, ma4);
delay(cekam);
M5.Lcd.drawBitmap(spriteX, spriteY, 22, 29, ma5);
delay(cekam);
M5.Lcd.drawBitmap(spriteX, spriteY, 22, 29, ma6);
delay(cekam);
M5.Lcd.drawBitmap(spriteX, spriteY, 22, 29, ma7);
delay(cekam);
M5.Lcd.drawBitmap(spriteX, spriteY, 22, 29, ma8);
M5.Lcd.fillScreen(WHITE);*/


//Serial.println(ax);


//.Lcd.drawBitmap()

//M5.Lcd.drawXBitmap(10, 10, image_data_61x61,61, 61);
// M5.Lcd.drawRect(mx,my,mx+10,my+10,RED);
// M5.Lcd.drawRect(mx,my,mx+10,my+10,RED);
//delay(10000);
//M5.Lcd.fillScreen(BLACK);
}
