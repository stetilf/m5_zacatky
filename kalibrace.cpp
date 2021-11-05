#include <M5StickCPlus.h>
float pitch= 0.0F;
float roll= 0.0F;
float yaw= 0.0F;
float max_left=0;
float max_right=0;
float range=0;
float step=0;

int x=0;
int y=0;
int pos=0;

void setup() 
{
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
  M5.update();
  M5.IMU.getAhrsData(&pitch,&roll,&yaw);
  M5.Lcd.setCursor(0, 60);
  M5.Lcd.printf(" %5.2f   %5.2f   %5.2f\n", pitch, roll, yaw);

  M5.Lcd.setCursor(0, 10);
  M5.Lcd.println("setting left max..");
  //M5.Lcd.drawCircle(x,y,1,RED);
  M5.Lcd.println(max_left);
  //M5.Lcd.drawCircle(max_left,y+10,1,RED);
  
if (M5.BtnA.isPressed()==true) 
   {
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0,0);
    M5.Lcd.print("max_left set to");
    M5.Lcd.println(max_left);
    max_left=pitch;
   }

if (M5.BtnB.isPressed()==true)
   {
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0,0);
    M5.Lcd.print("max_right set to");
    M5.Lcd.println(max_right);
    max_right=pitch;
   }
  
range=abs(max_left)+max_right;
step=range/135;

M5.Lcd.setCursor(0, 120);
M5.Lcd.print("range");
M5.Lcd.println(range);
M5.Lcd.print("step");
M5.Lcd.println(step);

M5.Lcd.drawCircle(0,80,2,RED);

delay(200);
}


