#ifndef AutoStraightSwitchRotateClimber_H
#define AutoStraightSwitchRotateClimber_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoStraightSwitchRotateClimber : public CommandGroup {
public:
	AutoStraightSwitchRotateClimber();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoStraightSwitchRotateClimber_H
