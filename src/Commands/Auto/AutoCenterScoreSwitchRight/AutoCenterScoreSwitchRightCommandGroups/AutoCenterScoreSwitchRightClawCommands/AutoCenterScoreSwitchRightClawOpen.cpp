#include "AutoCenterScoreSwitchRightClawOpen.h"
#include "Robot.h"

AutoCenterScoreSwitchRightClawOpen::AutoCenterScoreSwitchRightClawOpen() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::cubeclaw);
}

// Called just before this Command runs the first time
void AutoCenterScoreSwitchRightClawOpen::Initialize() {
	Robot::cubeclaw.GetSolenoid().Set(frc::DoubleSolenoid::kForward);
}

// Called repeatedly when this Command is scheduled to run
void AutoCenterScoreSwitchRightClawOpen::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoCenterScoreSwitchRightClawOpen::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void AutoCenterScoreSwitchRightClawOpen::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoCenterScoreSwitchRightClawOpen::Interrupted() {

}
