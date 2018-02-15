#include <Commands/Auto/AutoStraightSwitch/AutoStraightSwitchCommandGroups/AutoStraightSwitchClimberCommands/AutoStraightSwitchRotateClimber.h>
#include "../../../../../Robot.h"

AutoStraightSwitchRotateClimber::AutoStraightSwitchRotateClimber() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::climber);
}

// Called just before this Command runs the fi	rst time
void AutoStraightSwitchRotateClimber::Initialize() {
	Robot::climber.ClimberRotatorSolenoid().Set(frc::DoubleSolenoid::kForward);
}

// Called repeatedly when this Command is scheduled to run
void AutoStraightSwitchRotateClimber::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoStraightSwitchRotateClimber::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void AutoStraightSwitchRotateClimber::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoStraightSwitchRotateClimber::Interrupted() {

}
