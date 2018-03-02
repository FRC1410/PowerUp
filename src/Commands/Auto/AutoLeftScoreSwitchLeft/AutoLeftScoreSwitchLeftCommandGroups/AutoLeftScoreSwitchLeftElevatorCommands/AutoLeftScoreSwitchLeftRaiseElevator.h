#ifndef AutoLeftScoreSwitchLeftRaiseElevator_H
#define AutoLeftScoreSwitchLeftRaiseElevator_H

#include <Commands/CommandGroup.h>
#include <Timer.h>
#include "WPILib.h"

class AutoLeftScoreSwitchLeftRaiseElevator : public CommandGroup {
public:
	AutoLeftScoreSwitchLeftRaiseElevator();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	frc::Timer * timer;
};

#endif  // AutoLeftScoreSwitchLeftRaiseElevator_H
