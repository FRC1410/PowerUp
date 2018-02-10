#ifndef AutoDoNothing_H
#define AutoDoNothing_H

#include <Commands/Command.h>

class AutoDoNothing : public frc::Command {
public:
	AutoDoNothing();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoDoNothing_H
