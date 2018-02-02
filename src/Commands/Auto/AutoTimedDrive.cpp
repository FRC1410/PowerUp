//#include <Commands/Auto/AutoTimedDriveForward/AutoTimedDriveForwardCommandGroups/AutoTimedDriveForwardCommands/AutoTimedDriveForwardDriveWheels.h>
#include <Commands/Auto/AutoTimedDrive.h>
#include "../../Robot.h"

AutoTimedDrive::AutoTimedDrive() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(&Robot::chassis);
	Requires(&Robot::drivetrain);
	timer = new frc::Timer();
}

// Called just before this Command runs the first time
void AutoTimedDrive::Initialize() {
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoTimedDrive::Execute() {
	Robot::drivetrain.TankDrive(-0.5, -0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoTimedDrive::IsFinished() {
	if (timer->Get()>=2)
	{
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoTimedDrive::End() {
	Robot::drivetrain.TankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoTimedDrive::Interrupted() {}
