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
			digitalWrite(R_D, LOW);
			digitalWrite(L_D, HIGH);
			break;
		}
		case Backward: 
		{
			digitalWrite(R_D, HIGH);
			digitalWrite(L_D, LOW);
			break;
		}
		case LeftTurn: 
		{
			digitalWrite(R_D, LOW);
			digitalWrite(L_D, LOW);
			break;
		}
		case RightTurn: 
		{
			digitalWrite(R_D, HIGH);
			digitalWrite(L_D, HIGH);
			break;
		}
		default:
		{
			digitalWrite(R_D, LOW);
			digitalWrite(L_D, HIGH);
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
		int AccK, A,ActualDelay=init_dly;
		AccK = (init_dly - target_dly)<0?-1:1;		
		A = (init_dly - target_dly)/pulse;
		AccK = A==0?AccK:A;
		while(pulse > 0)
		{
			send_pulse(R_P);
			send_pulse(L_P);
			delayMicroseconds(ActualDelay);
			ActualDelay -= AccK;
			pulse--;
			if((ActualDelay-init_dly)*(ActualDelay-target_dly) > 0) break;
		}
		while(pulse > 0)
		{
			send_pulse(R_P);
			send_pulse(L_P);
			delayMicroseconds(target_dly);
			pulse--;
		}
			
	}
	void Run_Mode::send_pulse(int wheels)
	{
		digitalWrite(wheels, HIGH);
		digitalWrite(wheels, LOW);
	}

	void Run_Mode::Turn(int left_times, int right_times, int totaltimes)
	{
		int N;
		int l_N = left_times;
		int r_N = right_times;
		for(N = 1; N < totaltimes +1; N++)
		{
			if(N % l_N == 0)
				{send_pulse(L_P);
				Serial.println("Left");}
			if(N % r_N == 0)
				{send_pulse(R_P);
				Serial.println("Right");}
			delayMicroseconds(Base_Delay);
		}
	}

float Angle_to_Radius(float agl)
{
	
	return agl*myPi/180;
}
