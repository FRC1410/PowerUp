#include "AutoCenterScoreSwitchRightRaiseElevator.h"
#include "Robot.h"

AutoCenterScoreSwitchRightRaiseElevator::AutoCenterScoreSwitchRightRaiseElevator() {
	Requires(&Robot::elevation);
	timer = new frc::Timer();
}

// Called just before this Command runs the first time
void AutoCenterScoreSwitchRightRaiseElevator::Initialize() {
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoCenterScoreSwitchRightRaiseElevator::Execute() {
	Robot::elevation.ElevationWheel(-1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoCenterScoreSwitchRightRaiseElevator::IsFinished() {
	if (timer->Get()>=1.7)
	{
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoCenterScoreSwitchRightRaiseElevator::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoCenterScoreSwitchRightRaiseElevator::Interrupted() {

}
