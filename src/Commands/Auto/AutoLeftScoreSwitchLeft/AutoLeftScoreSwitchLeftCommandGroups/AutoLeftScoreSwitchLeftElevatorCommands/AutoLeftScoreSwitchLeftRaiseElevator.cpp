#include "AutoLeftScoreSwitchLeftRaiseElevator.h"
#include "Robot.h"

AutoLeftScoreSwitchLeftRaiseElevator::AutoLeftScoreSwitchLeftRaiseElevator() {
	Requires(&Robot::elevation);
	timer = new frc::Timer();
}

// Called just before this Command runs the first time
void AutoLeftScoreSwitchLeftRaiseElevator::Initialize() {
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoLeftScoreSwitchLeftRaiseElevator::Execute() {
	Robot::elevation.ElevationWheel(-1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoLeftScoreSwitchLeftRaiseElevator::IsFinished() {
	if (timer->Get()>=1.7)
	{
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoLeftScoreSwitchLeftRaiseElevator::End() {
	Robot::elevation.ElevationWheel(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoLeftScoreSwitchLeftRaiseElevator::Interrupted() {

}
