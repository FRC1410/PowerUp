#include "TeleOpElevation.h"

#include "../../Robot.h"
#include "../../OI.h"

TeleOpElevation::TeleOpElevation() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::elevation);
}

// Called just before this Command runs the first time
void TeleOpElevation::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TeleOpElevation::Execute() {
	if (Robot::elevation.LimitSwitch() == false && Robot::oi.GetOperatorAxis(elevator_axis) < 0) {
		Robot::elevation.ElevationWheel(0);
	} else {
		Robot::elevation.ElevationWheel(Robot::oi.GetOperatorAxis(elevator_axis));
	}
}

// Make this return true when this Command no longer needs to run execute()
bool TeleOpElevation::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TeleOpElevation::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleOpElevation::Interrupted() {
	End();
}
