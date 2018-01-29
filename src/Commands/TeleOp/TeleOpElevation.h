#ifndef TeleOpElevation_H
#define TeleOpElevation_H

#include "WPILib.h"
#include "Commands/Command.h"
class TeleOpElevation : public frc::Command {
public:
	TeleOpElevation();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TeleOpElevation_H
