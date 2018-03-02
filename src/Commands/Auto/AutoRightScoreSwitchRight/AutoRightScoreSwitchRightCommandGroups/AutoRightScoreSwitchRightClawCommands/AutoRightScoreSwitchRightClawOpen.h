#ifndef AutoRightScoreSwitchRightClawOpen_H
#define AutoRightScoreSwitchRightClawOpen_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoRightScoreSwitchRightClawOpen : public CommandGroup {
public:
	AutoRightScoreSwitchRightClawOpen();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoRightScoreSwitchRightClawOpen_H
