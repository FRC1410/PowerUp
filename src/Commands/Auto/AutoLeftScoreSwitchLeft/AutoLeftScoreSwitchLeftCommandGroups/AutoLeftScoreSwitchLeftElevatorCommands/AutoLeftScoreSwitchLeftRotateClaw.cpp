#include "AutoLeftScoreSwitchLeftRotateClaw.h"
#include "Robot.h"

AutoLeftScoreSwitchLeftRotateClaw::AutoLeftScoreSwitchLeftRotateClaw() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::rotator);
	timer = new frc::Timer();
}

// Called just before this Command runs the first time
void AutoLeftScoreSwitchLeftRotateClaw::Initialize() {
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoLeftScoreSwitchLeftRotateClaw::Execute() {
	Robot::rotator.RotateClaw(0.6);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoLeftScoreSwitchLeftRotateClaw::IsFinished() {
	if (timer->Get()>=1.6)
	{
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoLeftScoreSwitchLeftRotateClaw::End() {
	Robot::rotator.RotateClaw(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoLeftScoreSwitchLeftRotateClaw::Interrupted() {

}
