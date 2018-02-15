#include <Commands/Auto/AutoStraightSwitch/AutoStraightSwitchCommandGroups/AutoStraightSwitchElevatorCommands/AutoStraightSwitchRaiseElevator.h>
#include "../../../../../Robot.h"

AutoStraightSwitchRaiseElevator::AutoStraightSwitchRaiseElevator() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::elevation);
	timer = new frc::Timer();
}

// Called just before this Command runs the first time
void AutoStraightSwitchRaiseElevator::Initialize() {
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoStraightSwitchRaiseElevator::Execute() {
	Robot::elevation.ElevationWheel(-1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoStraightSwitchRaiseElevator::IsFinished() {
	if (timer->Get()>=1.7)
		{
			return true;
		}
		return false;
}

// Called once after isFinished returns true
void AutoStraightSwitchRaiseElevator::End() {
	Robot::elevation.ElevationWheel(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoStraightSwitchRaiseElevator::Interrupted() {

}
