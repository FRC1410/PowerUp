#ifndef AutoCenterScoreSwitchRightRaiseElevator_H
#define AutoCenterScoreSwitchRightRaiseElevator_H

#include <Commands/CommandGroup.h>
#include <Timer.h>
#include "WPILib.h"

class AutoCenterScoreSwitchRightRaiseElevator : public CommandGroup {
public:
	AutoCenterScoreSwitchRightRaiseElevator();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	frc::Timer * timer;
};

#endif  // AutoCenterScoreSwitchRightRaiseElevator_H
