#include "AutoStraightSwitchClawOpen.h"
#include "../../../../../Robot.h"

AutoStraightSwitchClawOpen::AutoStraightSwitchClawOpen() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::cubeclaw);
}

// Called just before this Command runs the first time
void AutoStraightSwitchClawOpen::Initialize() {
	Robot::cubeclaw.GetSolenoid().Set(frc::DoubleSolenoid::kForward);
}

// Called repeatedly when this Command is scheduled to run
void AutoStraightSwitchClawOpen::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoStraightSwitchClawOpen::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void AutoStraightSwitchClawOpen::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoStraightSwitchClawOpen::Interrupted() {

}
