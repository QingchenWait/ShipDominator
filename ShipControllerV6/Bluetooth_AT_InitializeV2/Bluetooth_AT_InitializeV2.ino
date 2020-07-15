#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  Serial.begin(38400);
  delay(500);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}
      
void loop() {
  
  Serial.println("AT");  // 在源码内自动模拟输入串口 AT 命令
  display.clearDisplay();   // clears the screen and buffer
  display.setTextSize(2); //选择字号
  display.setTextColor(WHITE);  //字体颜色
  display.setCursor(0,0);   //起点坐标
  display.println("AT");
  display.display();
  while(Serial.available())
  {
    char ch;
    ch = BT.read();
    Serial.print(ch); // 如果连接成功，蓝牙将发送OK
    display.setTextSize(2); //选择字号
    display.setTextColor(WHITE);  //字体颜色
    display.setCursor(0,48);   //起点坐标
    display.println(ch);
    display.display();
  } 
   delay(2000); // 等待串口监视器中的输出结果
      
  Serial.println("AT+UART=9600,0,0"); // 设置蓝牙通信串口波特率为9600，停止位1位，无校验位
  display.clearDisplay();   // clears the screen and buffer
  display.setTextSize(1); //选择字号
  display.setTextColor(WHITE);  //字体颜色
  display.setCursor(0,0);   //起点坐标
  display.println("AT+UART=9600,0,0");
  display.display();
  while(Serial.available())
  {
    char ch;
    ch = Serial.read();
    Serial.print(ch);
    display.setTextSize(2); //选择字号
    display.setTextColor(WHITE);  //字体颜色
    display.setCursor(0,48);   //起点坐标
    display.println(ch);
    display.display();
  }
  delay(2000);
  
  Serial.println("AT+NAME=MSc MED 07"); // 修改蓝牙名称为 "MSc MED 07"
  display.clearDisplay();   // clears the screen and buffer
  display.setTextSize(1); //选择字号
  display.setTextColor(WHITE);  //字体颜色
  display.setCursor(0,0);   //起点坐标
  display.println("AT+NAME=MSc MED 07");
  display.display();
  while(Serial.available())
  {
    char ch;
    ch = Serial.read();
    Serial.print(ch);
    display.setTextSize(2); //选择字号
    display.setTextColor(WHITE);  //字体颜色
    display.setCursor(0,48);   //起点坐标
    display.println(ch);
    display.display();
  }
  delay(2000);
      
  Serial.println("AT+ROLE=0"); // 设置蓝牙模式为从模式
  display.clearDisplay();   // clears the screen and buffer
  display.setTextSize(1); //选择字号
  display.setTextColor(WHITE);  //字体颜色
  display.setCursor(0,0);   //起点坐标
  display.println("AT+ROLE=0");
  display.display();
  while(Serial.available())
  {
    char ch;
    ch = Serial.read();
    Serial.print(ch);
    display.setTextSize(2); //选择字号
    display.setTextColor(WHITE);  //字体颜色
    display.setCursor(0,48);   //起点坐标
    display.println(ch);
    display.display();
  }
  delay(2000);
      
  Serial.println("AT+PSWD=2007"); // 修改蓝牙配对密码为 2007
  display.clearDisplay();   // clears the screen and buffer
  display.setTextSize(1); //选择字号
  display.setTextColor(WHITE);  //字体颜色
  display.setCursor(0,0);   //起点坐标
  display.println("AT+PSWD=2007");
  display.display();
  while(Serial.available())
  {
    char ch;
    ch = Serial.read();
    Serial.print(ch);
    display.setTextSize(2); //选择字号
    display.setTextColor(WHITE);  //字体颜色
    display.setCursor(0,48);   //起点坐标
    display.println(ch);
    display.display();
  }
  delay(2000);
}
