#ifndef AutoCenterScoreSwitchRightTurnLeftCommand_H
#define AutoCenterScoreSwitchRightTurnLeftCommand_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoCenterScoreSwitchRightTurnLeftCommand : public CommandGroup {
public:
	AutoCenterScoreSwitchRightTurnLeftCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoCenterScoreSwitchRightTurnLeftCommand_H
