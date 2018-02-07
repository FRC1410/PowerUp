#ifndef TeleOpRotation_H
#define TeleOpRotation_H

#include "WPILib.h"
#include "Commands/Command.h"

class TeleOpRotation : public frc::Command {
public:
	TeleOpRotation();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TeleOpRotation_H
