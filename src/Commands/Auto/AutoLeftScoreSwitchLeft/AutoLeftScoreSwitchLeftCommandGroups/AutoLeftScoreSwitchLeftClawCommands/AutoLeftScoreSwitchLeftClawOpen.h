#ifndef AutoLeftScoreSwitchLeftClawOpen_H
#define AutoLeftScoreSwitchLeftClawOpen_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoLeftScoreSwitchLeftClawOpen : public CommandGroup {
public:
	AutoLeftScoreSwitchLeftClawOpen();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoLeftScoreSwitchLeftClawOpen_H
