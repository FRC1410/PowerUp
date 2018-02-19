#ifndef AutoCenterScoreSwitchLeftClawOpen_H
#define AutoCenterScoreSwitchLeftClawOpen_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoCenterScoreSwitchLeftClawOpen : public CommandGroup {
public:
	AutoCenterScoreSwitchLeftClawOpen();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoCenterScoreSwitchLeftClawOpen_H
