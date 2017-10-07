#include <Robot_Motion_Control.h>

const int Condition Flag = 4

Motor_Mode motormode;

enum run_modes
{
  MOTOR_IDLE,
  LEFT_TURN,
  RIGHT_TURN,
  FORWARD,
  BACKWARD  
} run_modes = MOTOR_IDLE;

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
}

void loop() {

  if (runmode == MOTOR_IDLE)
  {
    while(Serial.avaliable())
    {
      ParseSerial();  
    }  
  }

}

void STM_mode(run_modes runmode)
{
  switch(runmode)
  {
    case MOTOR_IDLE :
    {
      digitalWrite(Condition_Flag, LOW)
      break;  
    }
    case FORWARD : 
    {
      motormode.Go_Straight(motor_speed,motor_steps);
      break;
    }  
    case BACKWARD : 
    {
      motormode.Go_Backward(motor_speed,motor_steps);
      break;
    } 
    case LEFT_TURN : 
    {
      motormode.Turn_Left(motor_speed,motor_steps);
      break;
    } 
    case RIGHT_TURN : 
    {
      motormode.Turn_Right(motor_speed,motor_steps);
      break;
    } 
    default: break;
  }
}


