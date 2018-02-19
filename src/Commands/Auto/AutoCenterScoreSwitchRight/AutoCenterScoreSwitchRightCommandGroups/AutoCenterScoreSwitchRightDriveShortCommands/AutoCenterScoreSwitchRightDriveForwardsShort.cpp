#include "AutoCenterScoreSwitchRightDriveForwardsShort.h"
#include "Robot.h"

AutoCenterScoreSwitchRightDriveForwardsShort::AutoCenterScoreSwitchRightDriveForwardsShort() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::drivetrain);
}

// Called just before this Command runs the first time
void AutoCenterScoreSwitchRightDriveForwardsShort::Initialize() {
	Robot::drivetrain.ConfigureEncoders();
	Robot::drivetrain.ResetEncodersandNavX();
}

// Called repeatedly when this Command is scheduled to run
void AutoCenterScoreSwitchRightDriveForwardsShort::Execute() {
	Robot::drivetrain.TankDrive(-0.5, -0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoCenterScoreSwitchRightDriveForwardsShort::IsFinished() {
	if (Robot::drivetrain.ReturnDrivenInches(3) >= 24){
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoCenterScoreSwitchRightDriveForwardsShort::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoCenterScoreSwitchRightDriveForwardsShort::Interrupted() {

}
