#ifndef Drive_H
#define Drive_H

#include "WPILib.h"
#include "RobotMap.h"

class Drive : public frc::Command {
public:
	Drive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double deadzone = default_driver_deadzone;
	int exponent = 1;
	int driving_mode = 1;
	int invert_driving = 1; //1 is normal, -1 is inverted
	bool lWasPressed = false;
	bool rWasPressed = false;
	bool xWasPressed = false;
	double x = 0;
	double y = 0;
	double d = 0;
	double m = 0;
	double triggers = 0;
};

#endif  // Drive_H
