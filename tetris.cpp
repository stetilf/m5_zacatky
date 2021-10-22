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
int canvasX=12;
int canvasY=2;
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


for(j=0;j<22; j++)
   {
   

   for(i=0;i<11; i++)
   {
    
    if(j%2==0)
    {
    if (i%2==0)
    {
    M5.Lcd.drawRect(canvasX+(rect_size*i),canvasY+10,rect_size,rect_size,RED);
    } else M5.Lcd.drawRect(canvasX+(rect_size*i),canvasY+10,rect_size,rect_size,BLUE);
    } else 
    if (i%2!=0)
    {  
    M5.Lcd.drawRect(canvasX+(rect_size*i),canvasY+10,rect_size,rect_size,GREEN);
    } else 
    M5.Lcd.drawRect(canvasX+(rect_size*i),canvasY+10,rect_size,rect_size,WHITE);
    


    delay(10);
   }
   canvasY=canvasY+10;
  }
}

int cekam=50;
int spriteX=0;
int spriteY=0;

void loop() {
  M5.Imu.getAccelData(&accX,&accY,&accZ);
}
