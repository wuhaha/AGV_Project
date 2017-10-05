// direction class

class Motor_Mode
{
	public: 
	void Turn_Left(int spd, int pls)
	{
		set_wheel_mode(LeftTurn);
		Motor_Run(spd, pls);
	}
	void Turn_Right(int spd, int pls)
	{
		set_wheel_mode(RightTurn);
		Motor_Run(spd, pls);
	}
	void Go_Straight(int spd, int pls)
	{
		set_wheel_mode(Forward);
		Motor_Run(spd, pls);
	}
	void Go_Backward(int spd, int pls)
	{
		set_wheel_mode(Backward);
		Motor_Run(spd, pls);
	}
	void set_wheel_mode(Wheel_Mode motor_mode)
	{
		switch motor_mode:
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
	void motor_run(int spd, int pls)
	{
		
		if ( pls < (Pulse_Rev << 1) )
		{			
			acc(pls >> 1,spd);
			acc(-(pls >> 1),spd);
		}
		else
		{
			acc(Pulse_Rev, spd);
			unispeed(pls - (Pulse_Rev << 1), spd);
			acc(Pulse_Rev, -spd);
		}
		
	}
	private:
	void acc(int pulse)
	{
		while(pulse > 0):
		{
			send_pulse();
		}
	}
}


float Angle_to_Radius(float agl)
{
	
	return agl*myPi/180;
}