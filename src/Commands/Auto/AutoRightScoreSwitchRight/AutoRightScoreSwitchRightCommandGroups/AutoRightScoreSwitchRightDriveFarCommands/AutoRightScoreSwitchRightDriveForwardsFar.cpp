#include "AutoRightScoreSwitchRightDriveForwardsFar.h"
#include "Robot.h"

AutoRightScoreSwitchRightDriveForwardsFar::AutoRightScoreSwitchRightDriveForwardsFar() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::drivetrain);
}

// Called just before this Command runs the first time
void AutoRightScoreSwitchRightDriveForwardsFar::Initialize() {
	Robot::drivetrain.ConfigureEncoders();
	Robot::drivetrain.ResetEncodersandNavX();
}

// Called repeatedly when this Command is scheduled to run
void AutoRightScoreSwitchRightDriveForwardsFar::Execute() {
	Robot::drivetrain.TankDrive(-0.5, -0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoRightScoreSwitchRightDriveForwardsFar::IsFinished() {
	if (Robot::drivetrain.ReturnDrivenInches(3) >= 148){
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoRightScoreSwitchRightDriveForwardsFar::End() {
	Robot::drivetrain.TankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoRightScoreSwitchRightDriveForwardsFar::Interrupted() {

}
