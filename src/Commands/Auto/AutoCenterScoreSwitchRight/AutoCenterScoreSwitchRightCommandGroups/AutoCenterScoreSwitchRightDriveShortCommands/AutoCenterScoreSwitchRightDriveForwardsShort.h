#ifndef AutoCenterScoreSwitchRightDriveForwardsShort_H
#define AutoCenterScoreSwitchRightDriveForwardsShort_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoCenterScoreSwitchRightDriveForwardsShort : public CommandGroup {
public:
	AutoCenterScoreSwitchRightDriveForwardsShort();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoCenterScoreSwitchRightDriveForwardsShort_H
