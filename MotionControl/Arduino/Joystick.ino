int Forward = 1;
int Turn = 2 ;
int Thr = 2;

int FSpeed = 0;
int TSpeed = 0;
int Pressed = 0;
int AccX = 0;
int AccY = 0;

void setup() {
  pinMode(Forward, INPUT);
  pinMode(Turn, INPUT);
  pinMode(Thr, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  FSpeed = analogRead(Forward);
  TSpeed = analogRead(Turn);
  Pressed = digitalRead(Thr);
  AccX = (FSpeed - FSpeed % 100) / 100;
  AccY = (TSpeed - TSpeed % 100) / 100;
  Serial.print(AccX);
  Serial.print(",");
  Serial.print(AccY);
  Serial.print(",");
  Serial.println(Pressed);
  delay(100);

}
