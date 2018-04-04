#include "AutoCrossBaselineRobonautsDelayTen.h"
#include "../../../../../Robot.h"

AutoCrossBaselineRobonautsDelayTen::AutoCrossBaselineRobonautsDelayTen() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::drivetrain);
	timer = new frc::Timer();
}

// Called just before this Command runs the first time
void AutoCrossBaselineRobonautsDelayTen::Initialize() {
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoCrossBaselineRobonautsDelayTen::Execute() {
	Robot::drivetrain.TankDrive(0, 0);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoCrossBaselineRobonautsDelayTen::IsFinished() {
	if (timer->Get()>=10)
	{
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoCrossBaselineRobonautsDelayTen::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoCrossBaselineRobonautsDelayTen::Interrupted() {

}
