int Motor1S = 2;
int Motor1D = 3;
int Motor2S = 8;
int Motor2D = 9;

void setup() {
  pinMode(Motor1S, OUTPUT);
  pinMode(Motor1D, OUTPUT);
  pinMode(Motor2S, OUTPUT);
  pinMode(Motor2D, OUTPUT);
  
  digitalWrite(Motor1S, LOW);
  digitalWrite(Motor2S, LOW);
  digitalWrite(Motor1D, LOW);
  digitalWrite(Motor2D, LOW);
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(Motor1S, HIGH);
  digitalWrite(Motor2S,HIGH);
  delay(100);

}
