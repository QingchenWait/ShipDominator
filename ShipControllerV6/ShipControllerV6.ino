 /************************
ShipController V6 Prototype
Remote controller for 2 DC motors
Use a L293D chip and a bluetooth receiver
Programmed by Haoyang.Li
************************/
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define LENABLE 5 // Define pins of left motor
#define LDIRA 3
#define LDIRB 4
#define RENABLE 6 // Define pins of right motor
#define RDIRA 7
#define RDIRB 2

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

int MotorSpeed = 0; // Store and control the speed
boolean Key_Pressing; // Record if the key is being pressed
char InfoRecv; // Information received by bluetooth module

void setup() 
{
  pinMode(LENABLE,OUTPUT); // Set the mode of the pins
  pinMode(LDIRA,OUTPUT);
  pinMode(LDIRB,OUTPUT);
  pinMode(RENABLE,OUTPUT);
  pinMode(RDIRA,OUTPUT);
  pinMode(RDIRB,OUTPUT);
  Serial.begin(9600);
  delay(500);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3c (for the 128x64)
  Serial.println("BT is ready!"); // Start the bluetooth
  display.clearDisplay();   // clears the screen and buffer
  display.setTextSize(2); // Select the size of font
  display.setTextColor(WHITE);  // Select the color of font
  display.setCursor(0,0);   // Select the X-Y coordinate of starting point
  display.println("Bluetooth is ready!");
  display.display();
  Key_Pressing = false;
}

void loop() 
{
  if (Serial.available()) // if receives bluetooth signal
  {
    InfoRecv = Serial.read();
    switch(InfoRecv)
    {
      case 'P': // "PowerOn" button pressed
      Serial.println("Power On");
      display.clearDisplay();   // clears the screen and buffer
      display.setTextSize(2); // Select the size of font
      display.setTextColor(WHITE);  // Select the color of font
      display.setCursor(0,0);   // Select the X-Y coordinate of starting point
      display.println("Status:");
      display.println("Power On");
      display.display();
      MotorSpeed = 255;
      analogWrite(LENABLE,MotorSpeed); // Open both motors
      digitalWrite(LDIRA,HIGH);
      digitalWrite(LDIRB,LOW);
      analogWrite(RENABLE,MotorSpeed);
      digitalWrite(RDIRA,HIGH);
      digitalWrite(RDIRB,LOW);
      delay(100); 
      break;
      
      case 'R': // "Right" button pressed
      Serial.println("Turn right");
      display.clearDisplay();   // clears the screen and buffer
      display.setTextSize(2); // Select the size of font
      display.setTextColor(WHITE);  // Select the color of font
      display.setCursor(0,0);   // Select the X-Y coordinate of starting point
      display.println("Status:");
      display.println("Turn right");
      display.display();
      digitalWrite(LENABLE,HIGH); // Turn right
      digitalWrite(LDIRA,HIGH);
      digitalWrite(LDIRB,LOW);
      digitalWrite(RENABLE,LOW);
      delay(3000); 
      digitalWrite(RENABLE,HIGH);
      digitalWrite(RDIRA,HIGH);
      digitalWrite(RDIRB,LOW);
      Serial.println("Turn End");
      display.clearDisplay();   // clears the screen and buffer
      display.setTextSize(2); // Select the size of font
      display.setTextColor(WHITE);  // Select the color of font
      display.setCursor(0,0);   // Select the X-Y coordinate of starting point
      display.println("Status:");
      display.println("Turn End");
      display.display();
      delay(100);
      break;

      case 'L': // "Left" button pressed
      Serial.println("Turn left");
      display.clearDisplay();   // clears the screen and buffer
      display.setTextSize(2); // Select the size of font
      display.setTextColor(WHITE);  // Select the color of font
      display.setCursor(0,0);   // Select the X-Y coordinate of starting point
      display.println("Status:");
      display.println("Turn left");
      display.display();
      digitalWrite(RENABLE,HIGH); // Turn left
      digitalWrite(RDIRA,HIGH);
      digitalWrite(RDIRB,LOW);
      digitalWrite(LENABLE,LOW);
      delay(3000); 
      digitalWrite(LENABLE,HIGH);
      digitalWrite(LDIRA,HIGH);
      digitalWrite(LDIRB,LOW);
      Serial.println("Turn End");
      display.clearDisplay();   // clears the screen and buffer
      display.setTextSize(2); // Select the size of font
      display.setTextColor(WHITE);  // Select the color of font
      display.setCursor(0,0);   // Select the X-Y coordinate of starting point
      display.println("Status:");
      display.println("Turn End");
      display.display();
      delay(100);
      break;

      case 'D': // "Turning R" button pressed
      {
        if(Key_Pressing == false)
        {
          Key_Pressing = true; // Keep turning right until button "Turning R" released
          Serial.println("Keep Turning right"); // Show condition in bluetooth controller
          display.clearDisplay();   // clears the screen and buffer
          display.setTextSize(2); // Select the size of font
          display.setTextColor(WHITE);  // Select the color of font
          display.setCursor(0,0);   // Select the X-Y coordinate of starting point
          display.println("Status:");
          display.println("Keep Turning right");
          display.display();
          digitalWrite(LENABLE,HIGH); 
          digitalWrite(LDIRA,HIGH);
          digitalWrite(LDIRB,LOW);
          digitalWrite(RENABLE,LOW);
        }
        else {Serial.println("Invalid"); break;}
      }
      delay(100);
      break;

      case 'A': // "Turning L" button pressed
      {
        if(Key_Pressing == false) 
        {
          Key_Pressing = true; // Keep turning left until button "Turning L" released
          Serial.println("Keep Turning left"); // Show condition in bluetooth controller
          display.clearDisplay();   // clears the screen and buffer
          display.setTextSize(2); // Select the size of font
          display.setTextColor(WHITE);  // Select the color of font
          display.setCursor(0,0);   // Select the X-Y coordinate of starting point
          display.println("Status:");
          display.println("Keep Turning left");
          display.display();
          digitalWrite(RENABLE,HIGH); 
          digitalWrite(RDIRA,HIGH);
          digitalWrite(RDIRB,LOW);
          digitalWrite(LENABLE,LOW);
        }
        else {Serial.println("Invalid"); break;}
      }
      delay(100);
      break;

      case 'T': // Release "Turning L" or "Turning R" button
      Key_Pressing = false;
      Serial.println("Stop turning"); // Show condition in bluetooth controller
      display.clearDisplay();   // clears the screen and buffer
      display.setTextSize(2); // Select the size of font
      display.setTextColor(WHITE);  // Select the color of font
      display.setCursor(0,0);   // Select the X-Y coordinate of starting point
      display.println("Status:");
      display.println("Stop turning");
      display.display();
      digitalWrite(LENABLE,HIGH); // Reset the motors
      digitalWrite(LDIRA,HIGH);
      digitalWrite(LDIRB,LOW);
      digitalWrite(RENABLE,HIGH);
      digitalWrite(RDIRA,HIGH);
      digitalWrite(RDIRB,LOW);
      delay(100);
      break;
      
      case 'S': // "SpeedDown" button Pressed
      MotorSpeed = MotorSpeed - 64;
      delay(100);
      {
        if (MotorSpeed < 127) {MotorSpeed = 127;} // Avoid negative number or idle running
      }
      Serial.print("Speed = "); Serial.println(MotorSpeed); // Show condition in bluetooth controller
      display.clearDisplay();   // clears the screen and buffer
      display.setTextSize(2); // Select the size of font
      display.setTextColor(WHITE);  // Select the color of font
      display.setCursor(0,0);   // Select the X-Y coordinate of starting point
      display.println("Status:");
      display.print("Speed- ");
      display.println(MotorSpeed);
      display.display();
      analogWrite(LENABLE,MotorSpeed); // Decrease the speed of motors
      analogWrite(RENABLE,MotorSpeed);
      delay(100); 
      break;

      case 'W': // "SpeedUp" button pressed
      MotorSpeed = MotorSpeed + 64;
      delay(100);
      {
        if (MotorSpeed > 255) {MotorSpeed = 255;} // Avoid >255
      }
      Serial.print("Speed = "); Serial.println(MotorSpeed); // Show condition in bluetooth controller
      display.clearDisplay();   // clears the screen and buffer
      display.setTextSize(2); // Select the size of font
      display.setTextColor(WHITE);  // Select the color of font
      display.setCursor(0,0);   // Select the X-Y coordinate of starting point
      display.println("Status:");
      display.print("Speed+ ");
      display.println(MotorSpeed);
      display.display();
      analogWrite(LENABLE,MotorSpeed); // Increase the speed of motors
      analogWrite(RENABLE,MotorSpeed);
      delay(100); 
      break;
      
      case 'O': // "Power Off" button pressed
      Serial.println("Power Off");
      display.clearDisplay();   // clears the screen and buffer
      display.setTextSize(2); // Select the size of font
      display.setTextColor(WHITE);  // Select the color of font
      display.setCursor(0,0);   // Select the X-Y coordinate of starting point
      display.println("Status:");
      display.println("Power Off");
      display.display();
      digitalWrite(LENABLE,LOW); // Completely Stop both motors
      digitalWrite(LDIRA,LOW);
      digitalWrite(LDIRB,LOW);
      digitalWrite(RENABLE,LOW);
      digitalWrite(RDIRA,LOW);
      digitalWrite(RDIRB,LOW);
      MotorSpeed = 0;
      delay(100); 
      break;
    }
  }
}
   
