#define Pulse_Rev 1600
#define Wheel_Diameter 4
#define myPi 3.14
#define Wheel_Dist 10

#define R_P 2
#define R_D 12
#define L_P 3
#define L_D 13

#define AccCoef 10

const int Basic_Delay = 500;
const int Idle_Delay = Basic_Delay * 2;

enum Wheel_Mode {Forward, Backward, LeftTurn, RightTurn};

class Motor_Mode
{
	public: 
	void Turn_Left(int, int);
	void Turn_Right(int, int);
	void Go_Straight(int, int);
	void Go_Backward(int, int);
	void set_wheel_mode(Wheel_Mode);	
	void Motor_Run(int, int);
};

class Run_Mode
{
	public:	
	void Speed_Control(int, int, int);	
	void send_pulse();
};

