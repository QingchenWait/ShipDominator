 /************************
ShipController Final Version
Remote controller for 4 motors
************************/

#define LENABLE 5 // Define pins of left movement motor
#define LDIRA 31
#define RENABLE 6 // Define pins of right movement motor
#define RDIRA 35
#define M1ENABLE 3 // Define pins of belt motor 1
#define M1A 39
#define M1B 41
#define M2ENABLE 4 // Define pins of belt motor 2
#define M2A 43
#define M2B 45

int MotorSpeed = 0; // Store and control the speed
boolean Key_Pressing; // Record if the key is being pressed
char InfoRecv; // Information received by bluetooth module

void setup() 
{
  pinMode(LENABLE,OUTPUT); // Set the mode of the pins
  pinMode(LDIRA,OUTPUT);
  pinMode(RENABLE,OUTPUT);
  pinMode(RDIRA,OUTPUT);
  pinMode(M1ENABLE,OUTPUT);
  pinMode(M1A,OUTPUT);
  pinMode(M1B,OUTPUT);
  pinMode(M2ENABLE,OUTPUT);
  pinMode(M2A,OUTPUT);
  pinMode(M2B,OUTPUT);
  Serial.begin(9600);
  Serial.println("BT is ready!"); // Start the bluetooth
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
      MotorSpeed = 255;
      analogWrite(LENABLE,MotorSpeed); // Open all the motors
      digitalWrite(LDIRA,LOW);
      analogWrite(RENABLE,MotorSpeed);
      digitalWrite(RDIRA,LOW);
      digitalWrite(M1ENABLE,HIGH);
      digitalWrite(M1A,HIGH);
      digitalWrite(M1B,LOW);
      digitalWrite(M2ENABLE,HIGH);
      digitalWrite(M2A,HIGH);
      digitalWrite(M2B,LOW);
      delay(100); 
      break;
      
      case 'R': // "Right" button pressed
      Serial.println("Turn right");
      digitalWrite(LENABLE,HIGH); // Turn right
      digitalWrite(LDIRA,LOW);
      digitalWrite(RENABLE,LOW);
      delay(3000); 
      digitalWrite(RENABLE,HIGH);
      digitalWrite(RDIRA,LOW);
      delay(100);
      break;

      case 'L': // "Left" button pressed
      Serial.println("Turn left");
      digitalWrite(RENABLE,HIGH); // Turn left
      digitalWrite(RDIRA,LOW);
      digitalWrite(LENABLE,LOW);
      delay(3000); 
      digitalWrite(LENABLE,HIGH);
      digitalWrite(LDIRA,LOW);
      delay(100);
      break;

      case 'D': // "Turning R" button pressed
      {
        if(Key_Pressing == false)
        {
          Key_Pressing = true; // Keep turning right until button "Turning R" released
          Serial.println("Keep Turning right"); // Show condition in bluetooth controller
          digitalWrite(LENABLE,HIGH); 
          digitalWrite(LDIRA,LOW);
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
          digitalWrite(RENABLE,HIGH); 
          digitalWrite(RDIRA,LOW);
          digitalWrite(LENABLE,LOW);
        }
        else {Serial.println("Invalid"); break;}
      }
      delay(100);
      break;

      case 'T': // Release "Turning L" or "Turning R" button
      Key_Pressing = false;
      Serial.println("Stop turning"); // Show condition in bluetooth controller
      digitalWrite(LENABLE,HIGH); // Reset the motors
      digitalWrite(LDIRA,LOW);
      digitalWrite(RENABLE,HIGH);
      digitalWrite(RDIRA,LOW);
      delay(100);
      break;
      
      case 'S': // "SpeedDown" button Pressed
      MotorSpeed = MotorSpeed - 64;
      delay(100);
      {
        if (MotorSpeed < 127) {MotorSpeed = 127;} // Avoid negative number or idle running
      }
      Serial.print("Speed = "); Serial.println(MotorSpeed); // Show condition in bluetooth controller
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
      analogWrite(LENABLE,MotorSpeed); // Increase the speed of motors
      analogWrite(RENABLE,MotorSpeed);
      delay(100); 
      break;

      case 'B': // "Belt On" button pressed
      Serial.println("Belt ON");
      digitalWrite(M1ENABLE,HIGH);
      digitalWrite(M1A,HIGH);
      digitalWrite(M1B,LOW);
      digitalWrite(M2ENABLE,HIGH);
      digitalWrite(M2A,HIGH);
      digitalWrite(M2B,LOW);

      case 'E': // "Belt Off" button pressed
      Serial.println("Belt OFF");
      digitalWrite(M1ENABLE,LOW);
      digitalWrite(M1A,LOW);
      digitalWrite(M1B,LOW);
      digitalWrite(M2ENABLE,LOW);
      digitalWrite(M2A,LOW);
      digitalWrite(M2B,LOW);

      case 'O': // "Power Off" button pressed
      Serial.println("Power Off");
      digitalWrite(LENABLE,LOW); // Completely Stop both motors
      digitalWrite(LDIRA,LOW);
      digitalWrite(RENABLE,LOW);
      digitalWrite(RDIRA,LOW);
      digitalWrite(M1ENABLE,LOW);
      digitalWrite(M1A,LOW);
      digitalWrite(M1B,LOW);
      digitalWrite(M2ENABLE,LOW);
      digitalWrite(M2A,LOW);
      digitalWrite(M2B,LOW);
      MotorSpeed = 0;
      delay(100); 
      break;
    }
  }
}
   
