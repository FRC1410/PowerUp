#ifndef TeleOpClawWheelsOut_H
#define TeleOpClawWheelsOut_H

#include "Commands/Command.h"

class TeleOpClawWheelsOut : public frc::Command{
public:
	TeleOpClawWheelsOut();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TeleOpClawWheelsOut_H
