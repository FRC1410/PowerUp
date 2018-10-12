#include <Commands/TeleOp/TeleOpClawWheelsIn.h>
#include "../../Robot.h"
#include "../../OI.h"

TeleOpClawWheelsIn::TeleOpClawWheelsIn() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::cubeclaw);
}

// Called just before this Command runs the first time
void TeleOpClawWheelsIn::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TeleOpClawWheelsIn::Execute() {
	Robot::cubeclaw.ClawWheels(-claw_intake_left, claw_intake_right);
}

// Make this return true when this Command no longer needs to run execute()
bool TeleOpClawWheelsIn::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TeleOpClawWheelsIn::End() {
	Robot::cubeclaw.ClawWheels(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleOpClawWheelsIn::Interrupted() {
}
