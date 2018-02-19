#ifndef AutoCenterScoreSwitchLeftTurnLeftCommand_H
#define AutoCenterScoreSwitchLeftTurnLeftCommand_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoCenterScoreSwitchLeftTurnLeftCommand : public CommandGroup {
public:
	AutoCenterScoreSwitchLeftTurnLeftCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoCenterScoreSwitchLeftTurnLeftCommand_H
