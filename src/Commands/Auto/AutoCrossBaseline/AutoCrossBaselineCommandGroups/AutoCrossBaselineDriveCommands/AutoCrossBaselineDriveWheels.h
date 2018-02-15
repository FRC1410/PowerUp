#ifndef AutoCrossBaselineDriveWheels_H
#define AutoCrossBaselineDriveWheels_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoCrossBaselineDriveWheels : public CommandGroup {
public:
	AutoCrossBaselineDriveWheels();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoCrossBaselineDriveWheels_H
