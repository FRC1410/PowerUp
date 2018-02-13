#ifndef TeleOpClawWheelsOff_H
#define TeleOpClawWheelsOff_H

#include "Commands/Command.h"

class TeleOpClawWheelsOff : public frc::Command{
public:
	TeleOpClawWheelsOff();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TeleOpClawWheelsOff_H
