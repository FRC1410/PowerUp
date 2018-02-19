#include "AutoCenterScoreSwitchLeftClawOpen.h"
#include "Robot.h"

AutoCenterScoreSwitchLeftClawOpen::AutoCenterScoreSwitchLeftClawOpen() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::cubeclaw);
}

// Called just before this Command runs the first time
void AutoCenterScoreSwitchLeftClawOpen::Initialize() {
	Robot::cubeclaw.GetSolenoid().Set(frc::DoubleSolenoid::kForward);
}

// Called repeatedly when this Command is scheduled to run
void AutoCenterScoreSwitchLeftClawOpen::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoCenterScoreSwitchLeftClawOpen::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void AutoCenterScoreSwitchLeftClawOpen::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoCenterScoreSwitchLeftClawOpen::Interrupted() {

}
