#ifndef AutoCenterScoreSwitchLeftDriveForwardsShort_H
#define AutoCenterScoreSwitchLeftDriveForwardsShort_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoCenterScoreSwitchLeftDriveForwardsShort : public CommandGroup {
public:
	AutoCenterScoreSwitchLeftDriveForwardsShort();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoCenterScoreSwitchLeftDriveForwardsShort_H
