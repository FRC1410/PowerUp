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
	double deadzone = default_deadzone;
	int exponent = 1;
	int driving_mode = 1;
	bool lWasPressed = false;
	bool rWasPressed = false;
	double x = 0;
	double y = 0;
	double d = 0;
	double m = 0;
};

#endif  // Drive_H
