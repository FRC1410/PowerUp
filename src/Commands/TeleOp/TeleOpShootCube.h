#ifndef TeleOpShootCube_H
#define TeleOpShootCube_H

#include "Commands/Command.h"

class TeleOpShootCube : public frc::Command {
public:
	TeleOpShootCube();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TeleOpShootCube_H
