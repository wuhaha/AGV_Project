#include "Robot_Motion_Control.h"

#include <IRremoteInt.h>
#include <IRremote.h>

int ControlMode = 1;

int rcv = 10;

unsigned long volup = 16736925;
unsigned long voldown = 16754775;
unsigned long goleft= 1386468383;
unsigned long goright = 16761405;
unsigned long startstop = 16712445;

IRrecv irrecv(rcv);

decode_results results;

Motor_Mode test;
void setup()
{
Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
irrecv.enableIRIn();
//test.Turn_Left(500,6400);

}

void loop(){
 if(ControlMode == 1)
 {
  if(irrecv.decode(&results)){
    //if(results.value == volplus)
    switch(results.value)
    {
    case 16736925:
      {
      //Serial.println("Go Straight");
      test.set_wheel_mode(Forward);
      test.Motor_Run(500,800);
      break;
      }
    case 16754775:
      {
      //Serial.println("Go Back");
      test.set_wheel_mode(Backward);
      test.Motor_Run(500,800);
      break;
      }
    case 16720605:
      {
      //Serial.println("Turn Left");
      test.set_wheel_mode(LeftTurn);
      test.Motor_Run(500,800);
      break;
      }
    case 16761405:
      {
      //Serial.println("Turn Right");
      test.set_wheel_mode(RightTurn);
      test.Motor_Run(500,800);
      break;
      }
    case 16712445:
      {
      //Serial.println("Stop");

      break;
      }
    case 4294967295:
      {
      //Serial.println("Keep");
      //test.Motor_Run(500,800);
      break;
      }      
    }
     
 // Serial.println(results.value);
  
  irrecv.resume();
  }
 }
}
