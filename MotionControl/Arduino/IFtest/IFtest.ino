#include <IRremoteInt.h>
#include <IRremote.h>

int rcv = 10;

unsigned long volup = 16736925;
unsigned long voldown = 16754775;
unsigned long goleft= 1386468383;
unsigned long goright = 16761405;
unsigned long startstop = 16712445;


IRrecv irrecv(rcv);

decode_results results;

void setup(){
 Serial.begin(9600);
 irrecv.enableIRIn();
}

void loop(){
  if(irrecv.decode(&results)){
    //if(results.value == volplus)
    switch(results.value)
    {
    case 16736925:
      {
      Serial.println("Go Straight");
      break;
      }
    case 16754775:
      {
      Serial.println("Go Back");
      break;
      }
    case 1386468383:
      {
      Serial.println("Turn Left");
      break;
      }
    case 16761405:
      {
      Serial.println("Turn Right");
      break;
      }
    case 16712445:
      {
      Serial.println("Stop");
      break;
      }
    case 4294967295:
      {
      Serial.println("Keep");
      break;
      }      
    }
     
 // Serial.println(results.value);
  
  irrecv.resume();
  }
}


