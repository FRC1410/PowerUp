#ifndef AutoRightScoreSwitchRightTurnLeft_H
#define AutoRightScoreSwitchRightTurnLeft_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoRightScoreSwitchRightTurnLeft : public CommandGroup {
public:
	AutoRightScoreSwitchRightTurnLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoRightScoreSwitchRightTurnLeft_H
