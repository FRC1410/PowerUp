#include <Commands/Auto/AutoCrossBaseline/AutoCrossBaselineCommandGroups/AutoCrossBaselineDriveCommands/AutoCrossBaselineDriveWheels.h>
#include "../../../../../Robot.h"

AutoCrossBaselineDriveWheels::AutoCrossBaselineDriveWheels() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::drivetrain);
}

// Called just before this Command runs the first time
void AutoCrossBaselineDriveWheels::Initialize() {
	Robot::drivetrain.ConfigureEncoders();
	Robot::drivetrain.ResetEncodersandNavX();
}

// Called repeatedly when this Command is scheduled to run
void AutoCrossBaselineDriveWheels::Execute() {
	Robot::drivetrain.TankDrive(-0.5, -0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoCrossBaselineDriveWheels::IsFinished() {
	if (Robot::drivetrain.ReturnDrivenInches(3) >= 100){
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoCrossBaselineDriveWheels::End() {
	Robot::drivetrain.TankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoCrossBaselineDriveWheels::Interrupted() {

}
