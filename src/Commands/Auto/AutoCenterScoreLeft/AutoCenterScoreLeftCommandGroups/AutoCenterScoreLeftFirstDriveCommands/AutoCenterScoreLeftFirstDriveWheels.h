#ifndef AutoCenterScoreLeftFirstDriveWheels_H
#define AutoCenterScoreLeftFirstDriveWheels_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoCenterScoreLeftFirstDriveWheels : public CommandGroup {
public:
	AutoCenterScoreLeftFirstDriveWheels();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoCenterScoreLeftFirstDriveWheels_H
