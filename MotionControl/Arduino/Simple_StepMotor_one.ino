int Motor1S = 2;
int Motor1D = 3;

void setup() {
  pinMode(Motor1S, OUTPUT);
  pinMode(Motor1D, OUTPUT);
  
  digitalWrite(Motor1S, LOW);
  digitalWrite(Motor1D, LOW);
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(Motor1S, HIGH);
  delay(1);
  digitalWrite(Motor1S,LOW);
  delay(1);

}
