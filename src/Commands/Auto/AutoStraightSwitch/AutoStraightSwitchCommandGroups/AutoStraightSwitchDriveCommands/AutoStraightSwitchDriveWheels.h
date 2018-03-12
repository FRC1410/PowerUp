#ifndef AutoStraightSwitchDriveWheels_H
#define AutoStraightSwitchDriveWheels_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoStraightSwitchDriveWheels : public CommandGroup {
public:
	AutoStraightSwitchDriveWheels();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoStraightSwitchDriveWheels_H
