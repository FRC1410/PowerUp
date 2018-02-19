#ifndef AutoCenterScoreSwitchLeftRaiseElevator_H
#define AutoCenterScoreSwitchLeftRaiseElevator_H

#include <Commands/CommandGroup.h>
#include <Timer.h>
#include "WPILib.h"

class AutoCenterScoreSwitchLeftRaiseElevator : public CommandGroup {
public:
	AutoCenterScoreSwitchLeftRaiseElevator();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	frc::Timer * timer;
};

#endif  // AutoCenterScoreSwitchLeftRaiseElevator_H
