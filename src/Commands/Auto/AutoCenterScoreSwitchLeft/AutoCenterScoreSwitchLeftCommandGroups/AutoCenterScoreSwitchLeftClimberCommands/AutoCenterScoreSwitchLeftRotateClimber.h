#ifndef AutoCenterScoreSwitchLeftRotateClimber_H
#define AutoCenterScoreSwitchLeftRotateClimber_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoCenterScoreSwitchLeftRotateClimber : public CommandGroup {
public:
	AutoCenterScoreSwitchLeftRotateClimber();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoCenterScoreSwitchLeftRotateClimber_H
