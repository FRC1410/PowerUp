#include "Drive.h"

#include "../../Robot.h"

Drive::Drive() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::drivetrain);
}

// Called just before this Command runs the first time
void Drive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {
	//auto& joystick = Robot::oi.GetJoystick();
	//Robot::drivetrain.TankDrive(joystick.GetRawAxis(1), joystick.GetRawAxis(5));
	Robot::drivetrain.TankDrive(Robot::oi.GetDriveAxis(tankLeftAxis), Robot::oi.GetDriveAxis(tankRightAxis));


}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Drive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted() {

}
