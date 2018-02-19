#include "AutoRightScoreSwitchRightClawOpen.h"
#include "Robot.h"

AutoRightScoreSwitchRightClawOpen::AutoRightScoreSwitchRightClawOpen() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::cubeclaw);
}

// Called just before this Command runs the first time
void AutoRightScoreSwitchRightClawOpen::Initialize() {
	Robot::cubeclaw.GetSolenoid().Set(frc::DoubleSolenoid::kForward);
}

// Called repeatedly when this Command is scheduled to run
void AutoRightScoreSwitchRightClawOpen::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoRightScoreSwitchRightClawOpen::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void AutoRightScoreSwitchRightClawOpen::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoRightScoreSwitchRightClawOpen::Interrupted() {

}
