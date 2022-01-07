#include <M5StickCPlus.h>
#include <WiFiMulti.h>
#include <ESPAsyncWebServer.h>
//library doc: https://platformio.org/lib/show/6758/ESPAsyncWebServer-esphome


// Set the name and password of the wifi to be connected.  配置所连接wifi的名称和密码

const char *ssid = "nazevsite";
const char *password = "heslo";


WiFiMulti WiFiMulti;


AsyncWebServer server(80);
const char* PARAM_MESSAGE = "message";
void notFound(AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "Not found");
}


String message;
//String localIP;

#ifndef _ROVERC_H_
#define _ROVERC_H_
#define ROVER_ADDRESS	0X38
void RoverC_Init(void);	//sda  0     scl  26
void Move_forward(int8_t Speed);
void Move_back(int8_t Speed);
void Move_turnleft(int8_t Speed);
void Move_turnright(int8_t Speed);
void Move_left(int8_t Speed);
void Move_right(int8_t Speed);
void Move_stop(int8_t Speed);
void Send_iic(uint8_t Register, uint8_t Speed);
#endif

void RoverC_Init(void)    //sda  0     scl  26
{
    Wire.begin(0,26,100);
}

void Send_iic(uint8_t Register, uint8_t Speed)
{
  Wire.beginTransmission(ROVER_ADDRESS);
  Wire.write(Register);
  Wire.write(Speed);
  Wire.endTransmission();
}

void Move_forward(int8_t Speed)
{
  Send_iic(0x00, Speed );
  Send_iic(0x01, Speed );
  Send_iic(0x02, Speed );
  Send_iic(0x03, Speed );
}

void Move_back(int8_t Speed)
{
  Send_iic(0x00, (-1) * Speed );
  Send_iic(0x01, (-1) * Speed );
  Send_iic(0x02, (-1) * Speed );
  Send_iic(0x03, (-1) * Speed );
}

void Move_turnleft(int8_t Speed)
{
  Send_iic(0x00, Speed );
  Send_iic(0x01, (-1) * Speed );
  Send_iic(0x02, Speed );
  Send_iic(0x03, (-1) * Speed );
}

void Move_turnright(int8_t Speed)
{
  Send_iic(0x00, (-1) * Speed );
  Send_iic(0x01, Speed );
  Send_iic(0x02, (-1) * Speed );
  Send_iic(0x03, Speed );
}

void Move_left(int8_t Speed)
{
  Send_iic(0x00, (-1) * Speed );
  Send_iic(0x01, Speed );
  Send_iic(0x02, Speed );
  Send_iic(0x03, (-1) * Speed );
}

void Move_right(int8_t Speed)
{
  Send_iic(0x00, Speed );
  Send_iic(0x01, (-1) * Speed );
  Send_iic(0x02, (-1) * Speed );
  Send_iic(0x03, Speed );
}


void Move_stop(int8_t Speed)
{
  Send_iic(0x00, 0 );
  Send_iic(0x01, 0 );
  Send_iic(0x02, 0 );
  Send_iic(0x03, 0 );
}

void Set_servo_1(int8_t Angle)
{
  Send_iic(0x10, Angle);
}


// the setup routine runs once when M5StickC starts up
void setup(){ 
  Serial.begin(115200);

  // Initialize the M5StickC object
  M5.begin();
  
  M5.Lcd.setRotation(1);
  M5.Lcd.setTextColor(BLUE);
  M5.Lcd.setCursor(0,0);
  M5.Lcd.setTextSize(2);
  M5.Lcd.printf("Rover\n");

  int sum=0;
  WiFiMulti.addAP(ssid, password);  //Add wifi configuration information.  添加wifi配置信息
  M5.lcd.printf("Waiting connect to WiFi: %s \n",ssid); //Serial port output format string.  串口输出格式化字符串
  while(WiFiMulti.run() != WL_CONNECTED) {  //If the connection to wifi is not established successfully.  如果没有与wifi成功建立连接
    M5.lcd.print(".");
    delay(1000);
    sum+=1;
    if(sum==10) M5.lcd.print("Conncet failed!");
  }
  M5.lcd.println("\nWiFi connected");

  IPAddress ipAddress = WiFi.localIP();
  String localIP = String(ipAddress[0]) + String(".") +\
  String(ipAddress[1]) + String(".") +\
  String(ipAddress[2]) + String(".") +\
  String(ipAddress[3]); 


  Serial.print("IP Address: ");
  Serial.println(localIP);
  M5.lcd.print("IP address:\n");
  M5.lcd.println(localIP); //The serial port outputs the IP address of the M5StickC.  串口输出M5StickC的IP地址
  delay(500);
  
  
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/plain", "Hello, world");
    });

    // Send a GET request to <IP>/get?message=<message>
    server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {
        
        if (request->hasParam(PARAM_MESSAGE)) {
            message = request->getParam(PARAM_MESSAGE)->value();
        } else {
            message = "No message sent";
        }
        request->send(200, "text/html", "Hello, GET: " + message + "<br>" + \
         "<a href=/get?message=w>FORWARD</a><br><br>" + \
         "<a href=/get?message=s>BACKWARD</a><br><br>" + \
         "<a href=/get?message=q>TURL_LEFT</a><br><br>" + \
         "<a href=/get?message=e>TURN_RIGHT</a><br><br>" + \
         "<a href=/get?message=a>LEFT</a><br><br>" + \
         "<a href=/get?message=d>RIGHT</a><br><br>" + \
         "<a href=/get?message=r>CLAMP_OPEN</a><br><br>" + \
         "<a href=/get?message=t>CLAMP_CLOSE</a>"
         );
        
       
        Serial.println("GET:");
        Serial.println(message);
    });

    // Send a POST request to <IP>/post with a form field message set to <message>
    server.on("/post", HTTP_POST, [](AsyncWebServerRequest *request){
        if (request->hasParam(PARAM_MESSAGE, true)) {
            message = request->getParam(PARAM_MESSAGE, true)->value();
        } else {
            message = "No message sent";
        }
        request->send(200, "text/plain", "Hello, POST: " + message);
    });

    server.onNotFound(notFound);

    server.begin();

  
  RoverC_Init();
  Move_stop(0);
}

// the loop routine runs over and over again forever
void loop() {
 int step=50;

 if(message=="w")
  {
   Move_forward(100);
   //Set_servo_1(0);
   message="";
  } else if(message=="q")
  {
   Move_turnright(100);
   //Set_servo_1(0);
   message="";
  } else if(message=="e")
  {
   Move_turnleft(100);
   //Set_servo_1(0);
   message="";
  } else if(message=="s")
  {
   Move_back(100);
   //Set_servo_1(0);
   message="";
  } else if(message=="a")
  {
   Move_left(100);
   //Set_servo_1(0);
   message="";
  } else if(message=="d")
  {
   Move_right(100);
   //Set_servo_1(0);
   message="";
  } else if(message=="r")
  {
   Set_servo_1(20);
   message="";
  } else if(message=="t")
  {
   Set_servo_1(80); //closed
   message="";
  } else if(message=="z") //force closed
  {
   Set_servo_1(90);
   message="";
  } else if(message=="u")
  {
   Set_servo_1(40);
   message="";
  } else if(message=="p")
  {
   message="";
   Move_stop(0);
  }
  
   delay(step);



}
