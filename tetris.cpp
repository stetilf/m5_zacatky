#include <M5StickCPlus.h>

uint16_t canvas[300];
int canvasX=12;
int canvasY=2;
int i=0;
int j=0;
int rect_size=10;
int position=0;

void setup() 
{

  for (int pos=0;pos<300;pos++)
  {
    canvas[pos]=0x0000;
  }
  
  canvas[10]=0xffff;
  canvas[21]=0xffff;
  canvas[20]=0xffff;
  canvas[31]=0xffff;

canvas[6]=0xffff;
canvas[17]=0xffff;
canvas[28]=0xffff;
canvas[39]=0xffff;



  M5.begin();
  M5.Lcd.fillScreen(BLACK);
  pinMode(10, OUTPUT);
  pinMode(37, INPUT);
  pinMode(39, INPUT);
  M5.Lcd.setRotation(0);
  Serial.begin(115200);
  M5.Imu.Init();
}

void loop() {

for(j=0;j<22; j++)
   {
   for(i=0;i<11; i++)
   {
    
    M5.update();
    
    if(M5.BtnB.isPressed()) {
    ESP.restart();
    }
    
    if(M5.BtnA.isPressed()) {
    Serial.println("button A pressed");
    i=0;
    j=0;
    position=0;
    canvasX=12;
    canvasY=2;
    M5.Lcd.fillScreen(BLACK);
    }
    
    if (canvas[position]==0xffff)
    {
    M5.Lcd.drawRect(canvasX+(rect_size*i),canvasY+10,rect_size,rect_size,0xffff);
    } else M5.Lcd.drawRect(canvasX+(rect_size*i),canvasY+10,rect_size,rect_size,0x0000);
    
    //Serial.print(i);
    //Serial.print(" ");
    //Serial.println(j);
    position++;
   }
   canvasY=canvasY+10;
  }

    i=0;
    j=0;
    position=0;
    canvasX=12;
    canvasY=2;



  for (int pos=300;pos>0;pos--)
  {
    if (canvas[pos]==0xffff)
    {
    canvas[pos]=0x0000;
    canvas[pos+11]=0xffff;
    //break;
    } 
  }

  delay(200);

}


