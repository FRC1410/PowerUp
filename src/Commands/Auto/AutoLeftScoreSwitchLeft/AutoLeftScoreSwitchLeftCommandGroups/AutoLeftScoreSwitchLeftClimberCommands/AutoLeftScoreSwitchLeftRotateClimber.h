#ifndef AutoLeftScoreSwitchLeftRotateClimber_H
#define AutoLeftScoreSwitchLeftRotateClimber_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoLeftScoreSwitchLeftRotateClimber : public CommandGroup {
public:
	AutoLeftScoreSwitchLeftRotateClimber();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoLeftScoreSwitchLeftRotateClimber_H
