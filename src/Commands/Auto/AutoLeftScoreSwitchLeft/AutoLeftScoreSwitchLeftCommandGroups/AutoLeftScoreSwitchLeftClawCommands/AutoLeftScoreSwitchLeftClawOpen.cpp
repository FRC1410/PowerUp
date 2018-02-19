#include "AutoLeftScoreSwitchLeftClawOpen.h"
#include "Robot.h"

AutoLeftScoreSwitchLeftClawOpen::AutoLeftScoreSwitchLeftClawOpen() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::cubeclaw);
}

// Called just before this Command runs the first time
void AutoLeftScoreSwitchLeftClawOpen::Initialize() {
	Robot::cubeclaw.GetSolenoid().Set(frc::DoubleSolenoid::kForward);
}

// Called repeatedly when this Command is scheduled to run
void AutoLeftScoreSwitchLeftClawOpen::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoLeftScoreSwitchLeftClawOpen::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void AutoLeftScoreSwitchLeftClawOpen::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoLeftScoreSwitchLeftClawOpen::Interrupted() {

}
