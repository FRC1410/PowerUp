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
void Drive::Execute(/*double l, double r*/ /*double d, double m*/ /*double x, double y, double d, double m*/) {
	//Exponential
	//l = Robot::oi.GetDriveAxis(tankLeftAxis);
	//r = Robot::oi.GetDriveAxis(tankRightAxis);
	//Robot::drivetrain.TankDrive((l+pow(l,3)+pow(l,5)+pow(l,7)+pow(l,9)+pow(l,11))/-6, (r+pow(r,3)+pow(r,5)+pow(r,7)+pow(r,9)+pow(r,11))/-6);

	//Regular
	//Robot::drivetrain.TankDrive(-1*Robot::oi.GetDriveAxis(tankLeftAxis), -1*Robot::oi.GetDriveAxis(tankRightAxis));

	//Single Stick
	d = Robot::oi.GetDriveDirection();
	m = -Robot::oi.GetDriveMagnitude();

		//Exponential
		m = ((m+pow(m,3)+pow(m,5)+pow(m,7)+pow(m,9)+pow(m,11))/6);

	if (d >=0 && d < 90) {
		Robot::drivetrain.TankDrive(m, ((45 - d)/45) * m);
	} else if (d >= 90 && d < 180) {
		Robot::drivetrain.TankDrive(((135 - d)/45) * m, -m);
	} else if (d >= 180 && d < 270) {
		Robot::drivetrain.TankDrive(-m, ((d - 225)/45) * m);
	} else {
		Robot::drivetrain.TankDrive(((d - 315)/45) * m, m);
	}

	//Single Stick x and y
	/*r = sqrt(pow(Robot::oi.GetDriveAxis(0), 2) + pow(Robot::oi.GetDriveAxis(1), 2));
	if (r > 1) {
		x = Robot::oi.GetDriveAxis(0)/r;
		y = Robot::oi.GetDriveAxis(1)/r;
	} else {
		x = Robot::oi.GetDriveAxis(0);
		y = Robot::oi.GetDriveAxis(1);
	}
	m = -sqrt(pow(x, 2) + pow(y, 2));

		//Exponential
		//m = ((m+pow(m,3)+pow(m,5)+pow(m,7)+pow(m,9)+pow(m,11))/6);

	if (x >= 0) {
		d = 90 - (atan(y/x));
	} else {
		d = 270 - atan(y/x);
	}
	if (r == 0) {
		Robot::drivetrain.TankDrive(0, 0);
	} else if (d >=0 && d < 90) {
		Robot::drivetrain.TankDrive(r, ((45 - d)/45) * r);
	} else if (d >= 90 && d < 180) {
		Robot::drivetrain.TankDrive(((135 - d)/45) * r, -r);
	} else if (d >= 180 && d < 270) {
		Robot::drivetrain.TankDrive(-r, ((d - 225)/45) * r);
	} else {
		Robot::drivetrain.TankDrive(((d - 315)/45) * r, r);
	}*/
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
