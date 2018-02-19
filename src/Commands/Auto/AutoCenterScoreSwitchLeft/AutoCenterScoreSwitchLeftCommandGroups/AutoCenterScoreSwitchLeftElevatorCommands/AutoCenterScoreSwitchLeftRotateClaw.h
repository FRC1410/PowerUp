#ifndef AutoCenterScoreSwitchLeftRotateClaw_H
#define AutoCenterScoreSwitchLeftRotateClaw_H

#include <Commands/CommandGroup.h>
#include <timer.h>
#include "WPILib.h"

class AutoCenterScoreSwitchLeftRotateClaw : public CommandGroup {
public:
	AutoCenterScoreSwitchLeftRotateClaw();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	frc::Timer * timer;
};

#endif  // AutoCenterScoreSwitchLeftRotateClaw_H
