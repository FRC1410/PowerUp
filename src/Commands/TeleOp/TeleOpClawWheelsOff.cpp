#include "TeleOpClawWheelsOff.h"
#include "../../Robot.h"
#include "../../OI.h"

TeleOpClawWheelsOff::TeleOpClawWheelsOff() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::cubeclaw);
}

// Called just before this Command runs the first time
void TeleOpClawWheelsOff::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TeleOpClawWheelsOff::Execute() {
	Robot::cubeclaw.ClawWheels(0, 0);
}

// Make this return true when this Command no longer needs to run execute()
bool TeleOpClawWheelsOff::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TeleOpClawWheelsOff::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleOpClawWheelsOff::Interrupted() {

}
