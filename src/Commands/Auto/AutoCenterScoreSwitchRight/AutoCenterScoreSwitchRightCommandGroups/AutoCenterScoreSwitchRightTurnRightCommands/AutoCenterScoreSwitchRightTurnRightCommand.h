#ifndef AutoCenterScoreSwitchRightTurnRightCommand_H
#define AutoCenterScoreSwitchRightTurnRightCommand_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoCenterScoreSwitchRightTurnRightCommand : public CommandGroup {
public:
	AutoCenterScoreSwitchRightTurnRightCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoCenterScoreSwitchRightTurnRightCommand_H
