#include <Commands/TeleOp/TeleOpClimb.h>
#include "../../Robot.h"
#include "../../OI.h"

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
		if (climbToggle == false) {
			Robot::climber.ClimbSolenoid().Set(frc::DoubleSolenoid::kReverse);
			climbToggle = true;
		} else {
			Robot::climber.ClimbSolenoid().Set(frc::DoubleSolenoid::kForward);
			climbToggle = false;
		} while(Robot::oi.GetOperatorButton(climb_button)){};
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
