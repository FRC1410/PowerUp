#ifndef AutoLeftScoreSwitchLeftRotateClaw_H
#define AutoLeftScoreSwitchLeftRotateClaw_H

#include <Commands/CommandGroup.h>
#include <Timer.h>
#include "WPILib.h"

class AutoLeftScoreSwitchLeftRotateClaw : public CommandGroup {
public:
	AutoLeftScoreSwitchLeftRotateClaw();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	frc::Timer * timer;
};

#endif  // AutoLeftScoreSwitchLeftRotateClaw_H
