#include <Commands/Auto/AutoStraightSwitch/AutoStraightSwitchCommandGroups/AutoStraightSwitchElevatorCommands/AutoStraightSwitchRotateClaw.h>
#include "../../../../../Robot.h"

AutoStraightSwitchRotateClaw::AutoStraightSwitchRotateClaw() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::rotator);
	timer = new frc::Timer();
}

// Called just before this Command runs the first time
void AutoStraightSwitchRotateClaw::Initialize() {
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoStraightSwitchRotateClaw::Execute() {
	Robot::rotator.RotateClaw(1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoStraightSwitchRotateClaw::IsFinished() {
	if (timer->Get() >= 2.4)
	{
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoStraightSwitchRotateClaw::End() {
	Robot::rotator.RotateClaw(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoStraightSwitchRotateClaw::Interrupted() {

}
