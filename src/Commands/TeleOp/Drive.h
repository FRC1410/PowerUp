#ifndef Drive_H
#define Drive_H

#include "WPILib.h"
class Drive : public frc::Command {
public:
	Drive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool singleStick = false;
	//Exponential

	double d = 0;
	double m = 0;
	double x = 0;
	double y = 0;

	//double l = 0;
	//double r = 0;
};

#endif  // Drive_H
