#ifndef NavxTest_H
#define NavxTest_H

#include "Commands/Command.h"

class NavxTest : public frc::Command {
public:
	NavxTest();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // NavxTest_H
