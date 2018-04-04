#ifndef AutoCrossBaselineRobonautsDelayTen_H
#define AutoCrossBaselineRobonautsDelayTen_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"
#include <Timer.h>

class AutoCrossBaselineRobonautsDelayTen : public CommandGroup {
public:
	AutoCrossBaselineRobonautsDelayTen();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	frc::Timer * timer;
};

#endif  // AutoCrossBaselineRobonautsDelayTen_H
