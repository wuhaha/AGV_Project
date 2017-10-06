#include "Robot_Motion_Control.h"
#include "Arduino.h"


	void Motor_Mode::Turn_Left(int dly, int pls)
	{
		set_wheel_mode(LeftTurn);
		Motor_Run(dly, pls);
	}
	void Motor_Mode::Turn_Right(int dly, int pls)
	{
		set_wheel_mode(RightTurn);
		Motor_Run(dly, pls);
	}
	void Motor_Mode::Go_Straight(int dly, int pls)
	{
		set_wheel_mode(Forward);
		Motor_Run(dly, pls);
	}
	void Motor_Mode::Go_Backward(int dly, int pls)
	{
		set_wheel_mode(Backward);
		Motor_Run(dly, pls);
	}
	void Motor_Mode::set_wheel_mode(Wheel_Mode motor_mode)
	{
		switch (motor_mode)
		{
		case Forward: 
		{
			digitalWrite(R_P, LOW);
			digitalWrite(L_P, LOW);
			break;
		}
		case Backward: 
		{
			digitalWrite(R_P, HIGH);
			digitalWrite(L_P, HIGH);
			break;
		}
		case LeftTurn: 
		{
			digitalWrite(R_P, HIGH);
			digitalWrite(L_P, LOW);
			break;
		}
		case RightTurn: 
		{
			digitalWrite(R_P, LOW);
			digitalWrite(L_P, HIGH);
			break;
		}
		default:
		{
			digitalWrite(R_P, LOW);
			digitalWrite(L_P, LOW);
		}
		}
	}
	void Motor_Mode::Motor_Run(int dly, int pls)
	{
		Run_Mode runmode;
		if ( pls < (Pulse_Rev << 1) )
		{			
			runmode.Speed_Control(pls >> 1,Idle_Delay,dly);
			runmode.Speed_Control(pls >> 1,dly,Idle_Delay);
		}
		else
		{
			runmode.Speed_Control(Pulse_Rev, Idle_Delay, dly);
			runmode.Speed_Control(pls - (Pulse_Rev << 1),dly,dly);
			runmode.Speed_Control(Pulse_Rev, dly,Idle_Delay);
		}
		
	}

	
	void Run_Mode::Speed_Control(int pulse, int init_dly, int target_dly)
	{
		int AccK, ActualDelay=init_dly;		
		AccK = (init_dly - target_dly)/pulse;
		AccK = AccK<0?AccK-1:AccK+1;
		while(pulse > 0)
		{
			send_pulse();
			delayMicroseconds(ActualDelay);
			ActualDelay -= AccK;
			pulse--;
			if((ActualDelay-init_dly)*(ActualDelay-target_dly) > 0) break;
		}
		while(pulse > 0)
		{
			send_pulse();
			delayMicroseconds(target_dly);
			pulse--;
		}
			
	}
	void Run_Mode::send_pulse()
	{
		digitalWrite(R_P, HIGH);
		digitalWrite(L_P, HIGH);
		digitalWrite(R_P, LOW);
		digitalWrite(L_P, LOW);
	}



float Angle_to_Radius(float agl)
{
	
	return agl*myPi/180;
}
