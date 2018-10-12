#include "TeleOpClimberRotate.h"
#include "../../Robot.h"

TeleOpClimberRotate::TeleOpClimberRotate() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void TeleOpClimberRotate::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TeleOpClimberRotate::Execute() {

	//This just compares the previous input with the current input.
	//If the previous input was not pressed and the current input is pressed, toggle piston.

	if (Robot::oi.GetOperatorButton(climber_rotator_button)) {
		if (wasPressed == false) {
			if (rotateToggle == false) {
				frc::SmartDashboard::PutString("Slim Jim", "Reverse");
				Robot::climber.ClimberRotatorSolenoid().Set(frc::DoubleSolenoid::kReverse);
				rotateToggle = true;
			} else {
				frc::SmartDashboard::PutString("Slim Jim", "Forward");
				Robot::climber.ClimberRotatorSolenoid().Set(frc::DoubleSolenoid::kForward);
				rotateToggle = false;
			}
		}
		wasPressed = true;
	} else {
		wasPressed = false;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool TeleOpClimberRotate::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TeleOpClimberRotate::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleOpClimberRotate::Interrupted() {

}
