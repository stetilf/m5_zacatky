#include <M5StickCPlus.h>

uint16_t canvas[300];
int canvasX=12;
int canvasY=2;
int i=0;
int j=0;
int rect_size=10;
int position=0;
int falling=22;

void setup() 
{

  for (int pos=0;pos<300;pos++)
  {
    canvas[pos]=0x0000;
  }
  

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
    } else if (canvas[position]==0x0ff0)
          M5.Lcd.drawRect(canvasX+(rect_size*i),canvasY+10,rect_size,rect_size,0x0ff0);
          else 
          M5.Lcd.drawRect(canvasX+(rect_size*i),canvasY+10,rect_size,rect_size,0x0000);
    
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



  for (int pos=300;pos>=0;pos--)
  {
    if (canvas[pos]==0xffff)
     {
      if (pos>230) 
       {
        canvas[pos]=0x0ff0;
        break;  
       } else {
                canvas[pos]=0x0000;
                canvas[pos+11]=0xffff;
                //break;
              }  
    } 
  }

  if(falling>22)
  {
  int rnd=random(0,3); //vybere typ
  int rnd2=random(1,10); //vybere pozici 
   if (rnd==0)
   {
    canvas[rnd2]=0xffff;
    canvas[rnd2-1]=0xffff;
    canvas[rnd2+1]=0xffff;
    canvas[rnd2+11]=0xffff;
   } 
   if (rnd==1)
   {
    canvas[rnd2]=0xffff;
    canvas[rnd2+1]=0xffff;
    canvas[rnd2+11]=0xffff;
    canvas[rnd2+12]=0xffff;
   }
   if (rnd==2)
   {
    canvas[rnd2-1]=0xffff;
    canvas[rnd2]=0xffff;
    canvas[rnd2+1]=0xffff;
   }
   if (rnd==3)
   {
    canvas[rnd2]=0xffff;
    canvas[rnd2+1]=0xffff;
   }


  falling=0;
  }
  falling++;

  delay(100);
}


