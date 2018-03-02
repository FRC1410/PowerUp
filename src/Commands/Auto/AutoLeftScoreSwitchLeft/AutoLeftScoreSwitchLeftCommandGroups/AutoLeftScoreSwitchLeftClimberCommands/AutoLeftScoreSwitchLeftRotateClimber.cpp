#include "AutoLeftScoreSwitchLeftRotateClimber.h"
#include "Robot.h"

AutoLeftScoreSwitchLeftRotateClimber::AutoLeftScoreSwitchLeftRotateClimber() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::climber);
}

// Called just before this Command runs the first time
void AutoLeftScoreSwitchLeftRotateClimber::Initialize() {
	Robot::climber.ClimberRotatorSolenoid().Set(frc::DoubleSolenoid::kReverse);
}

// Called repeatedly when this Command is scheduled to run
void AutoLeftScoreSwitchLeftRotateClimber::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoLeftScoreSwitchLeftRotateClimber::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void AutoLeftScoreSwitchLeftRotateClimber::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoLeftScoreSwitchLeftRotateClimber::Interrupted() {

}
