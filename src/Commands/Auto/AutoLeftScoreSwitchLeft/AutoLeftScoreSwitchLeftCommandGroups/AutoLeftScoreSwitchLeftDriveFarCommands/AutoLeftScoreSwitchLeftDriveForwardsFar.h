#ifndef AutoLeftScoreSwitchLeftDriveForwardsFar_H
#define AutoLeftScoreSwitchLeftDriveForwardsFar_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoLeftScoreSwitchLeftDriveForwardsFar : public CommandGroup {
public:
	AutoLeftScoreSwitchLeftDriveForwardsFar();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoLeftScoreSwitchLeftDriveForwardsFar_H
