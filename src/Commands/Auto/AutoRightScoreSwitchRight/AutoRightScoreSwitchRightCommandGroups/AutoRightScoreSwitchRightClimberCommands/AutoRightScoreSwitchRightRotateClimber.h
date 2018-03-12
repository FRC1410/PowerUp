#ifndef AutoRightScoreSwitchRightRotateClimber_H
#define AutoRightScoreSwitchRightRotateClimber_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoRightScoreSwitchRightRotateClimber : public CommandGroup {
public:
	AutoRightScoreSwitchRightRotateClimber();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoRightScoreSwitchRightRotateClimber_H
