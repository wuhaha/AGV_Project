#define spdA 625
#define spdB 312
#define spdC 1

int Motor1S = 2;
int Motor1D = 3;
int Motor2S = 13;
int Motor2D = 12;

int DIR = 8;
int LEFT = 9;
int RIGHT = 10;

int spdfct = 1;

int S1 = 5;
int S2 = 6;

int s1,s2;

int D;
int L;
int R;

void setup() {
  pinMode(Motor1S, OUTPUT);
  pinMode(Motor1D, OUTPUT);
  pinMode(Motor2D, OUTPUT);
  pinMode(Motor2S, OUTPUT);
  
  pinMode(DIR, INPUT);
  pinMode(LEFT, INPUT);
  pinMode(RIGHT, INPUT);
  
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  
  digitalWrite(Motor1S, LOW);
  digitalWrite(Motor1D, LOW);
  digitalWrite(Motor2S, LOW);
  digitalWrite(Motor2D, LOW);
  
  //Serial.begin(9600);
}

void loop() {
  D = digitalRead(DIR);
  L = digitalRead(LEFT);
  R = digitalRead(RIGHT);
  //spdfct = read_from_serial();
  choose_spd();
  if(D == HIGH){
    Backward(spdfct);
    }
  else if(LEFT == HIGH) {
    Leftturn(spdfct);
    }
  else if(RIGHT == HIGH){
    Rightturn(spdfct);
    }
  else if(D == LOW){
    Forward(spdfct);
    }
    //Serial.println(analogRead(A0));
    //Serial.print(spdfct);
}

void choose_spd(){
  s1 = digitalRead(S1);
  s2 = digitalRead(S2);
  
  if(s1 == HIGH && s2 == HIGH){
  spdfct = spdA;
  }
  else if(s1 == HIGH && s2 == LOW){
  spdfct = spdB;
  }
  else if(s1 == LOW && s2 == HIGH){
  spdfct = spdC;
  }
  else {
  spdfct = 1000;
  }
}

int read_from_serial(){
  String spdfctstring;
  if(Serial.available()){
    spdfctstring = Serial.readString();
    spdfct = spdfctstring.toInt();
    }
  return spdfct;
  }

void MotorSpeed(int speedfactor){
 digitalWrite(Motor1S, HIGH);
 digitalWrite(Motor2S, HIGH);
 digitalWrite(Motor1S, LOW);
 digitalWrite(Motor2S, LOW);
 delayMicroseconds(speedfactor);
  }

void Forward(int SpdFct){
  digitalWrite(Motor1D, HIGH);
  digitalWrite(Motor2D, HIGH);
  MotorSpeed(SpdFct);
}

void Backward(int SpdFct){
  digitalWrite(Motor1D, LOW);
  digitalWrite(Motor2D, LOW);
  MotorSpeed(SpdFct);
  }

void Leftturn(int SpdFct){
  digitalWrite(Motor1D, HIGH);
  digitalWrite(Motor2D, LOW);
  MotorSpeed(SpdFct);
  }

void Rightturn(int SpdFct){
  digitalWrite(Motor1D,LOW);
  digitalWrite(Motor2D, HIGH);
  MotorSpeed(SpdFct);
  }
