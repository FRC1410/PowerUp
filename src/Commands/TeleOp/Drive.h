#ifndef Drive_H
#define Drive_H

#include "WPILib.h"
class Drive : public frc::Command {
public:
	Drive();
	void Initialize();
	void Execute(double l, double r /*double d, double m*/ /*double x, double y, double d, double m*/);
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Drive_H
