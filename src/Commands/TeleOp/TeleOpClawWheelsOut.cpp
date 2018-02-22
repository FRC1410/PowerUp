#include "TeleOpClawWheelsOut.h"
#include "../../Robot.h"

TeleOpClawWheelsOut::TeleOpClawWheelsOut() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::cubeclaw);
}

// Called just before this Command runs the first time
void TeleOpClawWheelsOut::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TeleOpClawWheelsOut::Execute() {
	Robot::cubeclaw.ClawWheels(claw_wheels_outtake, -claw_wheels_outtake);
}

// Make this return true when this Command no longer needs to run execute()
bool TeleOpClawWheelsOut::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TeleOpClawWheelsOut::End() {
	Robot::cubeclaw.ClawWheels(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleOpClawWheelsOut::Interrupted() {

}
