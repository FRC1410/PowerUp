#ifndef AutoRightScoreSwitchRightRotateClaw_H
#define AutoRightScoreSwitchRightRotateClaw_H

#include <Commands/CommandGroup.h>
#include <Timer.h>
#include "WPILib.h"

class AutoRightScoreSwitchRightRotateClaw : public CommandGroup {
public:
	AutoRightScoreSwitchRightRotateClaw();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	frc::Timer * timer;
};

#endif  // AutoRightScoreSwitchRightRotateClaw_H
