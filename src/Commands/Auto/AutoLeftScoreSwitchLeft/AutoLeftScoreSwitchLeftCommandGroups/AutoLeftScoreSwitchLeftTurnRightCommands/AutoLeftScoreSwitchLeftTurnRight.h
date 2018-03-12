#ifndef AutoLeftScoreSwitchLeftTurnRight_H
#define AutoLeftScoreSwitchLeftTurnRight_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"

class AutoLeftScoreSwitchLeftTurnRight : public CommandGroup {
public:
	AutoLeftScoreSwitchLeftTurnRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoLeftScoreSwitchLeftTurnRight_H
