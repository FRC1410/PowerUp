#ifndef TeleOpClimb_H
#define TeleOpClimb_H

#include <Commands/Command.h>
#include <WPILib.h>

class TeleOpClimb : public frc::Command {
public:
	TeleOpClimb();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
private:
	bool climbToggle = false;
};

#endif
