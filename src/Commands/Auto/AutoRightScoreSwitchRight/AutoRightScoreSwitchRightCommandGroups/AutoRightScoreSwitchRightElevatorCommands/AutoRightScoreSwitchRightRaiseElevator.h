#ifndef AutoRightScoreSwitchRightRaiseElevator_H
#define AutoRightScoreSwitchRightRaiseElevator_H

#include <Commands/CommandGroup.h>
#include <Timer.h>
#include "WPILib.h"

class AutoRightScoreSwitchRightRaiseElevator : public CommandGroup {
public:
	AutoRightScoreSwitchRightRaiseElevator();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	frc::Timer * timer;
};

#endif  // AutoRightScoreSwitchRightRaiseElevator_H
