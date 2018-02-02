#ifndef AutoEncodeDrive_H
#define AutoEncodeDrive_H

#include <Commands/Command.h>

class AutoEncodeDrive : public frc::Command {
public:
	AutoEncodeDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoEncodeDrive_H
