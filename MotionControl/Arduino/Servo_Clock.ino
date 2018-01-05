#include<SoftwareSerial.h>
#include <Servo.h>

Servo servo1;
char angles[3];
int index = 0;
int angle;

void setup() {
  Serial.begin(9600);
  servo1.attach(9);
  servo1.write(0);
}

void loop() {}

void serialEvent(){
  while(Serial.available())
  {
    char c = Serial.read();
    if(isDigit(c))
    {
     angles[index++] = c; 
    }
    else
    {
     angle = atoi(angles);
     servo1.write(angle);
     index = 0;
     angles;
    }
  }
}
