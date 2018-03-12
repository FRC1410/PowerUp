#ifndef AutoCenterScoreSwitchRightClawOpen_H
#define AutoCenterScoreSwitchRightClawOpen_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoCenterScoreSwitchRightClawOpen : public CommandGroup {
public:
	AutoCenterScoreSwitchRightClawOpen();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoCenterScoreSwitchRightClawOpen_H
