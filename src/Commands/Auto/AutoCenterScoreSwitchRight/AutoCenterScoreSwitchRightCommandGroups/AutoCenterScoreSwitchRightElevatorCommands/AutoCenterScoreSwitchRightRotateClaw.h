#ifndef AutoCenterScoreSwitchRightRotateClaw_H
#define AutoCenterScoreSwitchRightRotateClaw_H

#include <Commands/CommandGroup.h>
#include <timer.h>
#include "WPILib.h"

class AutoCenterScoreSwitchRightRotateClaw : public CommandGroup {
public:
	AutoCenterScoreSwitchRightRotateClaw();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	frc::Timer * timer;
};

#endif  // AutoCenterScoreSwitchRightRotateClaw_H
