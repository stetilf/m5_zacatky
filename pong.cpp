#include <M5StickCPlus.h>
void setup() {
   M5.begin();
}
int pX=60; 
int pY=230;
int ballX=100;
int ballY=100;
int ballDir=0;

void loop() {
  if (ballDir==0) //směr je vpravo nahoru
   {
     ballX++;
     ballY--;
   } else if (ballDir==1) //směr je vpravo dolů
   {
     ballX++;
     ballY++;
   } else if (ballDir==2) //směr je vlevo dolů
   {
     ballX--;
     ballY++;
   }else if (ballDir==3) //směr je vlevo nahoru
   {
     ballX--;
     ballY--;
   }
//řešení kolize balonu s okrajem obrazovky
  if (ballDir==0 && ballX>130) //směr je vpravo nahoru
   {
     ballDir=3;
   }
   M5.Lcd.drawCircle(ballX,ballY,3,WHITE);
   M5.update();   // update button state
   if(M5.BtnA.isPressed()) {
      pX+=1;
      Serial.println("Key A");
   }
   if(M5.BtnB.isPressed()) {
      pX-=1;
      Serial.println("Key B");
   }
    M5.Lcd.drawRect(pX,pY,40,8,WHITE);
   delay(50);
   M5.Lcd.fillScreen(BLACK);
}
