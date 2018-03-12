#include <Commands/Auto/AutoCenterScoreLeft/AutoCenterScoreLeftCommandGroups/AutoCenterScoreLeftFirstDriveCommands/AutoCenterScoreLeftFirstDriveWheels.h>
#include "../../../../../Robot.h"

AutoCenterScoreLeftFirstDriveWheels::AutoCenterScoreLeftFirstDriveWheels() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::drivetrain);
}

// Called just before this Command runs the first time
void AutoCenterScoreLeftFirstDriveWheels::Initialize() {
	Robot::drivetrain.ConfigureEncoders();
	Robot::drivetrain.ResetEncodersandNavX();
}

// Called repeatedly when this Command is scheduled to run
void AutoCenterScoreLeftFirstDriveWheels::Execute() {
	Robot::drivetrain.TankDrive(-0.5, -0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoCenterScoreLeftFirstDriveWheels::IsFinished() {
	if (Robot::drivetrain.ReturnDrivenInches(3) >= 30){
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoCenterScoreLeftFirstDriveWheels::End() {
	Robot::drivetrain.TankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoCenterScoreLeftFirstDriveWheels::Interrupted() {

}
