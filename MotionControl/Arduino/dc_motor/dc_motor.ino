//Motor A
const int motorL1  = 9;  
const int motorL2  = 10;  
//Motor B
const int motorR1  = 6; 
const int motorR2  = 5; 

const int motorLS = 3;
const int motorRS = 11;

int Spd = 125;
int Duration = 100;


void setup(){

    pinMode(motorL1, OUTPUT);
    pinMode(motorL2, OUTPUT);
    pinMode(motorR1, OUTPUT);
    pinMode(motorR2, OUTPUT);
    pinMode(motorLS, OUTPUT);
    pinMode(motorRS, OUTPUT);

    Serial.begin(9600);
    
    Stop();

}
     
   void Turn_Left(int degree){ 
    digitalWrite(motorL1, LOW);
    digitalWrite(motorL2, HIGH);
    digitalWrite(motorR1, HIGH);
    digitalWrite(motorR2, LOW);
    Speed(255);
    delay(degree);
    }
    
   void Turn_Right(int degree){
    digitalWrite(motorL1, HIGH);
    digitalWrite(motorL2, LOW);
    digitalWrite(motorR1, LOW);
    digitalWrite(motorR2, HIGH);
    Speed(255);
    delay(degree);  
   }  
   void Forward(int spd, int t){
    digitalWrite(motorL1, HIGH);
    digitalWrite(motorL2, LOW);
    digitalWrite(motorR1, HIGH);
    digitalWrite(motorR2, LOW);
    Speed(spd);
    delay(t); 
    }

    void Backward(int spd, int t){
    digitalWrite(motorL1, LOW);
    digitalWrite(motorL2, HIGH);
    digitalWrite(motorR1, LOW);
    digitalWrite(motorR2, HIGH);
    Speed(spd);
    delay(t); 
    }
   
  void Stop(){
    Speed(0);
    
    digitalWrite(motorL1, LOW);
    digitalWrite(motorL2, LOW);
    digitalWrite(motorR1, LOW);
    digitalWrite(motorR2, LOW);
    }
  


  void Speed(int spd){
    analogWrite(motorLS, spd);
    analogWrite(motorRS, spd);
    }

void loop(){
  if(Serial.available()){
    char serialin;
    serialin = Serial.read();

    switch(serialin){
    case 'F' :
      Forward(Spd,Duration);
      break;
    case 'B' :
      Backward(Spd,Duration);
      break;
    case 'L' :
      Turn_Left(Duration);
      break;
    case 'R' :
      Turn_Right(Duration);
      break;
    default:
      Stop();
      }
    }

}

