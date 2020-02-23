 /************************
ShipController V2 Prototype
Remote controller for 2 DC motors
Use a L293D chip and an IR receiver
Programmed by Haoyang.Li in 18/02/2020
************************/
#include "IRremote.h"

#define LENABLE 5 // Define pins of left motor
#define LDIRA 3
#define LDIRB 4
#define RENABLE 6 // Define pins of right motor
#define RDIRA 7
#define RDIRB 2
int receiver = 11; // Set signal Pin of IR receiver as Digital Pin 11

/*--- Declare objects ---*/
IRrecv irrecv(receiver);    // create instance of 'irrecv'
decode_results results;     // create instance of 'decode_results'

void setup() {
  pinMode(LENABLE,OUTPUT); // Set the mode of the pins
  pinMode(LDIRA,OUTPUT);
  pinMode(LDIRB,OUTPUT);
  pinMode(RENABLE,OUTPUT);
  pinMode(RDIRA,OUTPUT);
  pinMode(RDIRB,OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() 
{
  if (irrecv.decode(&results))// if receives an IR signal
  {
    switch(results.value)
    {
      case 0xFFA25D: // Power button pressed
      digitalWrite(LENABLE,HIGH); //Open both motors
      digitalWrite(LDIRA,HIGH);
      digitalWrite(LDIRB,LOW);
      digitalWrite(RENABLE,HIGH);
      digitalWrite(RDIRA,HIGH);
      digitalWrite(RDIRB,LOW);
      delay(200); 
      break;
      
      case 0xFFC23D: // >>| button pressed
      digitalWrite(LENABLE,HIGH); // Turn right
      digitalWrite(LDIRA,HIGH);
      digitalWrite(LDIRB,LOW);
      digitalWrite(RENABLE,LOW);
      delay(3000); 
      digitalWrite(RENABLE,HIGH);
      digitalWrite(RDIRA,HIGH);
      digitalWrite(RDIRB,LOW);
      delay(200);
      break;
      
      case 0xFF22DD: // |<< button pressed
      digitalWrite(RENABLE,HIGH); // Turn left
      digitalWrite(RDIRA,HIGH);
      digitalWrite(RDIRB,LOW);
      digitalWrite(LENABLE,LOW);
      delay(3000); 
      digitalWrite(LENABLE,HIGH);
      digitalWrite(LDIRA,HIGH);
      digitalWrite(LDIRB,LOW);
      delay(200);
      break;
      
      case 0xFFE21D: // FUNC/STOP pressed
      digitalWrite(LENABLE,LOW);// Stop both motors
      digitalWrite(RENABLE,LOW);
      delay(200); 
      break;
    }
    delay(500); // Do not get immediate repeat
    irrecv.resume(); // receive the next value
    digitalWrite(11, LOW); //reset the IR signal
  }
}
   
