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
	if (Robot::oi.GetOperatorButton(claw_wheels_in_button)) {
		Robot::cubeclaw.ClawWheels(claw_wheels_intake, -claw_wheels_intake);
	} else if (Robot::oi.GetOperatorButton(claw_wheels_out_button)) {
		Robot::cubeclaw.ClawWheels(-claw_wheels_outtake, claw_wheels_outtake);
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
