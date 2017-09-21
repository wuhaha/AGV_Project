#include <IRremoteInt.h>
#include <IRremote.h>

int rcv = 13;

IRrecv irrecv(rcv);

decode_results results;

void setup(){
 Serial.begin(9600);
 irrecv.enableIRIn();
}

void loop(){
  if(irrecv.decode(&results)){
  Serial.println(results.value, HEX);
  irrecv.resume();
  }
}


