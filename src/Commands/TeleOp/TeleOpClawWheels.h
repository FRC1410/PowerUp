#ifndef TeleOpClawWheels_H
#define TeleOpClawWheels_H

#include "Commands/Command.h"

class TeleOpClawWheels : public Command{
public:
	TeleOpClawWheels();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TeleOpClawWheels_H
