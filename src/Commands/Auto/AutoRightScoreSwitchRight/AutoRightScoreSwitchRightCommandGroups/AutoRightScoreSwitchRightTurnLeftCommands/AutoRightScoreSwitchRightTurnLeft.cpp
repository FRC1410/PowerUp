#include "AutoRightScoreSwitchRightTurnLeft.h"
#include "Robot.h"

AutoRightScoreSwitchRightTurnLeft::AutoRightScoreSwitchRightTurnLeft() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::drivetrain);
}

// Called just before this Command runs the first time
void AutoRightScoreSwitchRightTurnLeft::Initialize() {
	Robot::drivetrain.ConfigureEncoders();
	Robot::drivetrain.ResetEncodersandNavX();
}

// Called repeatedly when this Command is scheduled to run
void AutoRightScoreSwitchRightTurnLeft::Execute() {
	Robot::drivetrain.SmartDashboardnavX();
	Robot::drivetrain.ReturnDrivenInches(3);
	Robot::drivetrain.TankDrive(0.5, -0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoRightScoreSwitchRightTurnLeft::IsFinished() {
	if (Robot::drivetrain.SmartDashboardnavX() <= -90) {
		Robot::drivetrain.ConfigureEncoders();
		Robot::drivetrain.ResetEncodersandNavX();
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoRightScoreSwitchRightTurnLeft::End() {
	Robot::drivetrain.TankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoRightScoreSwitchRightTurnLeft::Interrupted() {

}
