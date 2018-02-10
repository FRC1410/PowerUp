#include "AutoDoNothing.h"
#include "../../Robot.h"

AutoDoNothing::AutoDoNothing() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::drivetrain);
}

// Called just before this Command runs the first time
void AutoDoNothing::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AutoDoNothing::Execute() {
	Robot::drivetrain.TankDrive(0, 0);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDoNothing::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AutoDoNothing::End() {
	Robot::drivetrain.TankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDoNothing::Interrupted() {

}
