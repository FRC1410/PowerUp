#include "AutoCenterScoreSwitchLeftRaiseElevator.h"
#include "Robot.h"

AutoCenterScoreSwitchLeftRaiseElevator::AutoCenterScoreSwitchLeftRaiseElevator() {
	Requires(&Robot::elevation);
	timer = new frc::Timer();
}

// Called just before this Command runs the first time
void AutoCenterScoreSwitchLeftRaiseElevator::Initialize() {
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoCenterScoreSwitchLeftRaiseElevator::Execute() {
	Robot::elevation.ElevationWheel(-1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoCenterScoreSwitchLeftRaiseElevator::IsFinished() {
	if (timer->Get()>=1.7)
	{
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoCenterScoreSwitchLeftRaiseElevator::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoCenterScoreSwitchLeftRaiseElevator::Interrupted() {

}
