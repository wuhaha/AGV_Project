 #include <Robot_Motion_Control.h>

const int Condition_Flag = 4;

Motor_Mode motormode;

enum run_modes
{
  MOTOR_IDLE,
  LEFT_TURN,
  RIGHT_TURN,
  FORWARD,
  BACKWARD  
} runmode = MOTOR_IDLE;

int motor_speed = Idle_Delay;
int motor_steps = 0;

void setup() {
  pinMode(L_D, OUTPUT);
  pinMode(L_P, OUTPUT);
  pinMode(R_D, OUTPUT);
  pinMode(R_P, OUTPUT);

  pinMode(Condition_Flag, OUTPUT);

  Serial.begin(115200);

  digitalWrite(Condition_Flag, LOW);

  runmode = MOTOR_IDLE;
  
}

void loop() {

  if (runmode == MOTOR_IDLE)
  {
      runmode = ParseSerial();
      STM_mode(runmode);  
      //Serial.println(runmode);  
  }

}

void STM_mode(enum run_modes runmode)
{
  switch(runmode)
  {
    case MOTOR_IDLE :
    {
      digitalWrite(Condition_Flag, LOW);
      //Serial.println('i');
      break;  
    }
    case FORWARD : 
    {
      motormode.Go_Straight(motor_speed,motor_steps);
      Serial.println('f');
      break;
    }  
    case BACKWARD : 
    {
      motormode.Go_Backward(motor_speed,motor_steps);
      Serial.println('b');
      break;
    } 
    case LEFT_TURN : 
    {
      motormode.Turn_Left(motor_speed,motor_steps);
            Serial.println('l');
      break;
    } 
    case RIGHT_TURN : 
    {
      motormode.Turn_Right(motor_speed,motor_steps);
            Serial.println('r');
      break;
    } 
    default: break;
  }
  runmode = MOTOR_IDLE;
}

run_modes ParseSerial()
{
  int picmd[3]={0,0,0};
  unsigned int inbyte = 0;
  while(Serial.available())
  {
    picmd[inbyte] = Serial.read();
    inbyte++;
  }
  motor_speed = picmd[1];
  motor_steps = picmd[2];
  
  return picmd[0];
  
}


