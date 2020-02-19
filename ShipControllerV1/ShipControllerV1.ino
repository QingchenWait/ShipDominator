 /************************
ShipController V1 Prototype
Use a L293D chip and an IR receiver
Programmed by Haoyang.Li in 11/02/2020
************************/
#include "IRremote.h"

#define ENABLE 5 // Define the pins of the motor
#define DIRA 3
#define DIRB 4

int receiver = 11; // Set signal Pin of IR receiver as Digital Pin 11

/*--- Declare objects ---*/
IRrecv irrecv(receiver);    // create instance of 'irrecv'
decode_results results;     // create instance of 'decode_results'

void setup() {
  //---set pin direction
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
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
      digitalWrite(ENABLE,HIGH);
      digitalWrite(DIRA,HIGH); //one way
      digitalWrite(DIRB,LOW);
      delay(500); 
      break;
      //case 0xFF22DD: // |<< button pressed
      
      //case 0xFFC23D: // >>| button pressed
      
      case 0xFFE21D: // FUNC/STOP pressed
      digitalWrite(ENABLE,LOW);
      delay(500); 
      break;
    }
    delay(500); // Do not get immediate repeat
    irrecv.resume(); // receive the next value
    digitalWrite(11, LOW); //reset the IR signal
  }
}
   
