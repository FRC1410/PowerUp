#ifndef AutoStraightSwitchRaiseElevator_H
#define AutoStraightSwitchRaiseElevator_H

#include <Commands/CommandGroup.h>
#include <Timer.h>
#include "WPILib.h"

class AutoStraightSwitchRaiseElevator : public CommandGroup {
public:
	AutoStraightSwitchRaiseElevator();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	frc::Timer * timer;
};

#endif  // AutoStraightSwitchRaiseElevator_H
