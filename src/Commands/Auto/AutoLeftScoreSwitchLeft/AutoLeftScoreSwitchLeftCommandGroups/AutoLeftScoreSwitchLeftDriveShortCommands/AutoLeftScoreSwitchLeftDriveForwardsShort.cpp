#include "AutoLeftScoreSwitchLeftDriveForwardsShort.h"
#include "Robot.h"

AutoLeftScoreSwitchLeftDriveForwardsShort::AutoLeftScoreSwitchLeftDriveForwardsShort() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::drivetrain);
}

// Called just before this Command runs the first time
void AutoLeftScoreSwitchLeftDriveForwardsShort::Initialize() {
	Robot::drivetrain.ConfigureEncoders();
	Robot::drivetrain.ResetEncodersandNavX();
}

// Called repeatedly when this Command is scheduled to run
void AutoLeftScoreSwitchLeftDriveForwardsShort::Execute() {
	if (Robot::drivetrain.ReturnDrivenInches(3) >= 100){
		Robot::drivetrain.ResetEncodersandNavX();
	}
	Robot::drivetrain.TankDrive(-0.5, -0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoLeftScoreSwitchLeftDriveForwardsShort::IsFinished() {
	if (Robot::drivetrain.ReturnDrivenInches(3) >= 22){
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoLeftScoreSwitchLeftDriveForwardsShort::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoLeftScoreSwitchLeftDriveForwardsShort::Interrupted() {

}
