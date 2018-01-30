#include <Commands/TeleOp/TeleOpClawWheels.h>
#include "../../Robot.h"
#include "../../OI.h"

TeleOpClawWheels::TeleOpClawWheels() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::cubeclaw);
}

// Called just before this Command runs the first time
void TeleOpClawWheels::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TeleOpClawWheels::Execute() {
	if (Robot::oi.GetOperatorButton(6)) {
		Robot::cubeclaw.ClawWheels(0.5, -0.5);
	} else if (Robot::oi.GetOperatorButton(5)) {
		Robot::cubeclaw.ClawWheels(-0.3, 0.3);
	} else {
		Robot::cubeclaw.ClawWheels(0, 0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool TeleOpClawWheels::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TeleOpClawWheels::End() {
	Robot::cubeclaw.ClawWheels(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleOpClawWheels::Interrupted() {

}
