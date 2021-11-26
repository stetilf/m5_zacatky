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
   
          if (ballDir==0 && ballX>130) //směr doprava nahoru && kolize vpravo
   {
     ballDir=3;
     ballDir+=10;                        //změna směru na vlevo nahoru
   } else if (ballDir==0 && ballY<5)   //směr doprava nahoru && kolize nahoře
   {
     ballDir=1;
     ballDir+=10;                        //změna směru na vpravo dolů
   } else if (ballDir==1 && ballY>235) //směr doprava dolů && kolize dole
   {  
     ballDir=0;
     ballDir+=10;                        //změna směru na vpravo nahoru
   } else if (ballDir==1 && ballX>130) //směr doprava dolů && kolize vpravo
   {
     ballDir=2;
     ballDir+=10;                        //změna směru na vlevo dolů
   } else if (ballDir==2 && ballY>235) //směr vlevo dolů && kolize dole
   {
     ballDir=3;
     ballDir+=10;                        //změna směru na vlevo nahoru
     Serial.println("směr vlevo dolů && kolize dole => změna směru na vpravo nahoru");
   } else if (ballDir==2 && ballX<5)   //směr vlevo dolů && kolize vlevo
   {
     ballDir=1;
     ballDir+=10;                        //změna směru na vlevo nahoru
     Serial.println("směr vlevo dolů && kolize dole => změna směru na vpravo dolů");
   } else if (ballDir==3 && ballY<5)   //směr vlevo nahoru && kolize nahoře
   {
     ballDir=2;
     ballDir+=10;                        //změna směru na vlevo dolů
     Serial.println("směr vlevo nahoru && kolize nahoře => změna směru na vlevo dolů");
   } else if (ballDir==3 && ballX<5)   //směr vlevo nahoru && kolize vlevo
   {
     ballDir=0;
     ballDir+=10;                        //změna směru na vpravo nahoru
     Serial.println("směr vlevo nahoru && kolize vlevo => změna směru na vpravo nahoru");
   }

  if (ballDir>=10) ballDir-=10;

  Serial.println(ballX);
  Serial.println(ballY);
  Serial.println(ballDir);
  Serial.println("");

   M5.Lcd.drawCircle(ballX,ballY,3,WHITE);
   M5.update();   // update button state
   if(M5.BtnA.isPressed()) {
      pX+=1;
      Serial.println("Key A");
   }
   if(M5.BtnB.isPressed()) {
      pX-=1;
      Serial.println("Key B");
      delay(10000);
   }
    M5.Lcd.drawRect(pX,pY,40,8,WHITE);
   delay(5);
   M5.Lcd.fillScreen(BLACK);
}
