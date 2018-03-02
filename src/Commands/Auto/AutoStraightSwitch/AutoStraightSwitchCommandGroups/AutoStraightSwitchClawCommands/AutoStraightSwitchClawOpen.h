#ifndef AutoStraightSwitchClawOpen_H
#define AutoStraightSwitchClawOpen_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoStraightSwitchClawOpen : public CommandGroup {
public:
	AutoStraightSwitchClawOpen();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoStraightSwitchClawOpen_H
