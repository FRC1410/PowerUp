#include "TeleOpRotation.h"

#include "../../Robot.h"
#include "../../OI.h"


TeleOpRotation::TeleOpRotation() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::rotator);
}

// Called just before this Command runs the first time
void TeleOpRotation::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TeleOpRotation::Execute() {
	Robot::rotator.RotateClaw(Robot::oi.GetOperatorAxis(rotator_axis));
}

// Make this return true when this Command no longer needs to run execute()
bool TeleOpRotation::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TeleOpRotation::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleOpRotation::Interrupted() {
End();
}
