#include <Commands/TeleOp/TeleOpClimb.h>
#include "../../Robot.h"

TeleOpClimb::TeleOpClimb() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::climber);
}

// Called just before this Command runs the first time
void TeleOpClimb::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TeleOpClimb::Execute() {
	if (Robot::oi.GetOperatorButton(climb_button)) {
		if (wasPressed == false) {
			if (toggle == false) {
				frc::SmartDashboard::PutString("Jim", "Reverse");
				Robot::climber.ClimbSolenoid().Set(frc::DoubleSolenoid::kReverse);
				toggle = true;
			} else {
				frc::SmartDashboard::PutString("Jim", "Forward");
				Robot::climber.ClimbSolenoid().Set(frc::DoubleSolenoid::kForward);
				toggle = false;
			}
		}
		wasPressed = true;
	} else {
		wasPressed = false;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool TeleOpClimb::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TeleOpClimb::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleOpClimb::Interrupted() {
	End();
}
