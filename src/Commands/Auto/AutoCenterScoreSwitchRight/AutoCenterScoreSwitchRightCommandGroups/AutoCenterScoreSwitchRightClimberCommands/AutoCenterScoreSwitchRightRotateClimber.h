#ifndef AutoCenterScoreSwitchRightRotateClimber_H
#define AutoCenterScoreSwitchRightRotateClimber_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoCenterScoreSwitchRightRotateClimber : public CommandGroup {
public:
	AutoCenterScoreSwitchRightRotateClimber();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoCenterScoreSwitchRightRotateClimber_H
