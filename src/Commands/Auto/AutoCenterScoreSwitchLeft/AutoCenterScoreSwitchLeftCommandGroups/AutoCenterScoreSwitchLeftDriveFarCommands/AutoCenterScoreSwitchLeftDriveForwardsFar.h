#ifndef AutoCenterScoreSwitchLeftDriveForwardsFar_H
#define AutoCenterScoreSwitchLeftDriveForwardsFar_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoCenterScoreSwitchLeftDriveForwardsFar : public CommandGroup {
public:
	AutoCenterScoreSwitchLeftDriveForwardsFar();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoCenterScoreSwitchLeftDriveForwardsFar_H
