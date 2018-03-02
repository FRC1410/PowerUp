#ifndef AutoLeftScoreSwitchLeftDriveForwardsShort_H
#define AutoLeftScoreSwitchLeftDriveForwardsShort_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoLeftScoreSwitchLeftDriveForwardsShort : public CommandGroup {
public:
	AutoLeftScoreSwitchLeftDriveForwardsShort();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoLeftScoreSwitchLeftDriveForwardsShort_H
