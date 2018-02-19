#ifndef AutoCenterScoreSwitchLeftTurnRightCommand_H
#define AutoCenterScoreSwitchLeftTurnRightCommand_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoCenterScoreSwitchLeftTurnRightCommand : public CommandGroup {
public:
	AutoCenterScoreSwitchLeftTurnRightCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoCenterScoreSwitchLeftTurnRightCommand_H
