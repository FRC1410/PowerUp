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
	Robot::rotator.ConfigureEncoder();
	Robot::rotator.ResetEncoder();
	frc::SmartDashboard::PutString("Rotator Direction:", "Inverted");
}

// Called repeatedly when this Command is scheduled to run
void TeleOpRotation::Execute() {
	if (Robot::oi.GetOperatorButton(invert_rotator_button)) {
		if (startWasPressed == false) {
			if (invert == 1) {
				invert = -1;
				frc::SmartDashboard::PutString("Inverted Driving", "Yes");
			} else {
				invert = 1;
				frc::SmartDashboard::PutString("Inverted Driving", "No");
			}
		}
		startWasPressed = true;
	} else {
		startWasPressed = false;
	}

	Robot::rotator.ReturnRotatorAngle();
	Robot::rotator.RotateClaw(invert * Robot::oi.GetOperatorAxis(rotator_axis));
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
}
