#ifndef AutoStraightSwitchRotateClaw_H
#define AutoStraightSwitchRotateClaw_H

#include <Commands/CommandGroup.h>
#include <Timer.h>
#include "WPILib.h"

class AutoStraightSwitchRotateClaw : public CommandGroup {
public:
	AutoStraightSwitchRotateClaw();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	frc::Timer * timer;
};

#endif  // AutoStraightSwitchRotateClaw_H
