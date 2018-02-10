#include "TeleOpShootCube.h"
#include "../../Robot.h"

TeleOpShootCube::TeleOpShootCube() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::cubeclaw);
}

// Called just before this Command runs the first time
void TeleOpShootCube::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TeleOpShootCube::Execute() {
	Robot::cubeclaw.ClawWheels(-claw_wheels_shoot, claw_wheels_shoot);
}

// Make this return true when this Command no longer needs to run execute()
bool TeleOpShootCube::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TeleOpShootCube::End() {
	Robot::cubeclaw.ClawWheels(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleOpShootCube::Interrupted() {

}
