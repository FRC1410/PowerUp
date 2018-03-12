#include "AutoCenterScoreSwitchRightDriveForwardsFar.h"
#include "Robot.h"

AutoCenterScoreSwitchRightDriveForwardsFar::AutoCenterScoreSwitchRightDriveForwardsFar() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::drivetrain);
}

// Called just before this Command runs the first time
void AutoCenterScoreSwitchRightDriveForwardsFar::Initialize() {
	Robot::drivetrain.ConfigureEncoders();
	Robot::drivetrain.ResetEncodersandNavX();
}

// Called repeatedly when this Command is scheduled to run
void AutoCenterScoreSwitchRightDriveForwardsFar::Execute() {
	Robot::drivetrain.TankDrive(-0.5, -0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoCenterScoreSwitchRightDriveForwardsFar::IsFinished() {
	if (Robot::drivetrain.ReturnDrivenInches(3) >= 53){
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoCenterScoreSwitchRightDriveForwardsFar::End() {
	Robot::drivetrain.TankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoCenterScoreSwitchRightDriveForwardsFar::Interrupted() {

}
