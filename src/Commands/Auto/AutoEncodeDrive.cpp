#include "AutoEncodeDrive.h"
#include "../../Robot.h"
#include <SmartDashboard/SmartDashboard.h>

AutoEncodeDrive::AutoEncodeDrive() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::drivetrain);
}

// Called just before this Command runs the first time
void AutoEncodeDrive::Initialize() {
	Robot::drivetrain.ResetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void AutoEncodeDrive::Execute() {
	Robot::drivetrain.TankDrive(0.5, 0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoEncodeDrive::IsFinished() {
	if (Robot::drivetrain.ReturnDrivenInches(3) >= (3.14159 * 2 * 3))
	{
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoEncodeDrive::End() {
	Robot::drivetrain.TankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoEncodeDrive::Interrupted() {

}
