#ifndef AutoCenterScoreSwitchRightDriveForwardsFar_H
#define AutoCenterScoreSwitchRightDriveForwardsFar_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoCenterScoreSwitchRightDriveForwardsFar : public CommandGroup {
public:
	AutoCenterScoreSwitchRightDriveForwardsFar();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoCenterScoreSwitchRightDriveForwardsFar_H
