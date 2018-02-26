#ifndef TeleOpClawWheelsIn_H
#define TeleOpClawWheelsIn_H

#include "Commands/Command.h"

class TeleOpClawWheelsIn : public frc::Command {
public:
	TeleOpClawWheelsIn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TeleOpClawWheelsIn_H
