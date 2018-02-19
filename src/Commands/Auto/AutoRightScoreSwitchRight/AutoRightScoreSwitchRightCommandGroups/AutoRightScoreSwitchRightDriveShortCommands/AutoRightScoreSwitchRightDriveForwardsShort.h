#ifndef AutoRightScoreSwitchRightDriveForwardsShort_H
#define AutoRightScoreSwitchRightDriveForwardsShort_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoRightScoreSwitchRightDriveForwardsShort : public CommandGroup {
public:
	AutoRightScoreSwitchRightDriveForwardsShort();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoRightScoreSwitchRightDriveForwardsShort_H
