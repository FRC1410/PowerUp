#include "AutoCenterScoreSwitchLeftRotateClimber.h"
#include "Robot.h"

AutoCenterScoreSwitchLeftRotateClimber::AutoCenterScoreSwitchLeftRotateClimber() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::climber);
}

// Called just before this Command runs the first time
void AutoCenterScoreSwitchLeftRotateClimber::Initialize() {
	Robot::climber.ClimberRotatorSolenoid().Set(frc::DoubleSolenoid::kForward);
}

// Called repeatedly when this Command is scheduled to run
void AutoCenterScoreSwitchLeftRotateClimber::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoCenterScoreSwitchLeftRotateClimber::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void AutoCenterScoreSwitchLeftRotateClimber::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoCenterScoreSwitchLeftRotateClimber::Interrupted() {

}
