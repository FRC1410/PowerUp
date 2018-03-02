#include "AutoRightScoreSwitchRightDriveForwardsShort.h"
#include "Robot.h"

AutoRightScoreSwitchRightDriveForwardsShort::AutoRightScoreSwitchRightDriveForwardsShort() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::drivetrain);
}

// Called just before this Command runs the first time
void AutoRightScoreSwitchRightDriveForwardsShort::Initialize() {
	Robot::drivetrain.ConfigureEncoders();
	Robot::drivetrain.ResetEncodersandNavX();
}

// Called repeatedly when this Command is scheduled to run
void AutoRightScoreSwitchRightDriveForwardsShort::Execute() {
	Robot::drivetrain.TankDrive(-0.5, -0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoRightScoreSwitchRightDriveForwardsShort::IsFinished() {
	if (Robot::drivetrain.ReturnDrivenInches(3) >= 20){
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoRightScoreSwitchRightDriveForwardsShort::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoRightScoreSwitchRightDriveForwardsShort::Interrupted() {

}
