#ifndef TeleOpClimberRotate_H
#define TeleOpClimberRotate_H

#include <Commands/Command.h>
#include <WPILib.h>

class TeleOpClimberRotate : public frc::Command {
public:
	TeleOpClimberRotate();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool rotateToggle = false;
	bool wasPressed = false;
};

#endif  // TeleOpClimberRotate_H
