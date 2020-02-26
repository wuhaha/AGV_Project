//Motor A
const int motorL1  = 9;
const int motorL2  = 10;
//Motor B
const int motorR1  = 6;
const int motorR2  = 5;

const int motorLS = 3;
const int motorRS = 11;

const int motorMode1 = 7;
const int motorMode2 = 8;

int Spd = 125;
int Duration = 100;


void setup() {

  pinMode(motorL1, OUTPUT);
  pinMode(motorL2, OUTPUT);
  pinMode(motorR1, OUTPUT);
  pinMode(motorR2, OUTPUT);
  pinMode(motorLS, OUTPUT);
  pinMode(motorRS, OUTPUT);
  pinMode(motorMode1, INPUT);
  pinMode(motorMode2, INPUT);

  Serial.begin(9600);

  Stop();

}

void Turn_Left(int degree) {
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, HIGH);
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  SetSpeed(255);
  delay(degree);
}

void Turn_Right(int degree) {
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, HIGH);
  SetSpeed(255);
  delay(degree);
}
void Forward(int spd, int t) {
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  SetSpeed(spd);
  delay(t);
}

void Backward(int spd, int t) {
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, HIGH);
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, HIGH);
  SetSpeed(spd);
  delay(t);
}

void Stop() {
  SetSpeed(0);

  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, LOW);
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, LOW);
}

void SetSpeed(int spd) {
  analogWrite(motorLS, spd);
  analogWrite(motorRS, spd);
}

char read_mode() {
  int mode1, mode2, modea;
  mode1 = digitalRead(motorMode1) * 2;
  mode2 = digitalRead(motorMode2);
  modea = mode1 + mode2;
  switch (modea)
  {
    case 0: Forward(Spd, Duration); return ('F');
    case 1: Turn_Left(90); return ('L');
    case 2: Turn_Right(90); return ('R');
    case 3: Backward(Spd, Duration); return ('B');
    default: Forward(0, Duration);
  }
}

int getSerial() {
  if (Serial.available()) {
    char serialin;
    serialin = Serial.read();

  } }

  void loop() {
    char a;
    a = read_mode();
    Serial.print(read_mode());
    delay(1000);
  }
