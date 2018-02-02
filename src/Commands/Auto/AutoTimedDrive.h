#pragma once

#ifndef AutoTimedDrive_H
#define AutoTimedDrive_H

#include <Commands/Command.h>
#include <Timer.h>

class AutoTimedDrive : public frc::Command {
public:
	AutoTimedDrive();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
private:
	frc::Timer * timer;
};

#endif
