#ifndef AutoRightScoreSwitchRightDriveForwardsFar_H
#define AutoRightScoreSwitchRightDriveForwardsFar_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoRightScoreSwitchRightDriveForwardsFar : public CommandGroup {
public:
	AutoRightScoreSwitchRightDriveForwardsFar();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoRightScoreSwitchRightDriveForwardsFar_H
