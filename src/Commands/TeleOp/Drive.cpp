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
	if (Robot::oi.GetDriverButton(driving_mode_button)) {
		if (rWasPressed == false) {
			if (driving_mode == 1) {
				driving_mode = 2;
				frc::SmartDashboard::PutString("Driving Mode:", "Single Stick");
			} else if (driving_mode == 2) {
				driving_mode = 3;
				frc::SmartDashboard::PutString("Driving Mode:", "Single Stick 4 Zones");
			} else {
				driving_mode = 1;
				frc::SmartDashboard::PutString("Driving Mode:", "Dual Sticks");
			}
		}
		rWasPressed = true;
	} else {
		rWasPressed = false;
	}

	//Cycles through exponents 1 - 4
	if (Robot::oi.GetDriverButton(exponential_driving_button)) {
		if (lWasPressed == false) {
			exponent = ((exponent % 4) + 1);
			frc::SmartDashboard::PutNumber("Exponent:", exponent);
		}
		lWasPressed = true;
	} else {
		lWasPressed = false;
	}

		if (Robot::oi.GetDriverButton(deadzone_increase_button)) {
		if (deadzone < 1) {
			deadzone += 0.001;
		}
	}

	if (Robot::oi.GetDriverButton(deadzone_decrease_button)) {
		if (deadzone > 0) {
			deadzone -= 0.001;
		}
	}

	frc::SmartDashboard::PutNumber("Deadzone %:", deadzone * 100);

	Robot::oi.PassDeadzone(deadzone);

	//Driving

	if (driving_mode == 1) {
		//x is left, y is right
		y = Robot::oi.ApplyExponent(Robot::oi.GetDriveAxis(tankRightAxis), exponent);
		x = Robot::oi.ApplyExponent(Robot::oi.GetDriveAxis(tankLeftAxis), exponent);

		Robot::drivetrain.TankDrive(x, y);
	} else {
		//Getting dimensions, if magnitude is more than one set it to one and adjust x and y with the same ratio
		m = sqrt(pow(Robot::oi.GetDriveAxis(tank_x_axis), 2) + pow(Robot::oi.GetDriveAxis(tank_y_axis), 2));
		if (m > 1) {
			x = -Robot::oi.GetDriveAxis(tank_x_axis)/m;
			y = Robot::oi.GetDriveAxis(tank_y_axis)/m;
		} else {
			x = -Robot::oi.GetDriveAxis(tank_x_axis);
			y = Robot::oi.GetDriveAxis(tank_y_axis);
		}
		m = sqrt(pow(x, 2) + pow(y, 2));
		m = Robot::oi.ApplyExponent(m, exponent);

			d = Robot::oi.GetDriveDirection(x, y);

		if (driving_mode == 2) {
		//Make the program not blow up when dividing by 0
			if (x == 0) {
				if (y > 0) {
					Robot::drivetrain.TankDrive(m, m);
				} else {
					Robot::drivetrain.TankDrive(-m, -m);
				}
				//Single stick math
			} else if (d >=0 && d < 90) {
				Robot::drivetrain.TankDrive(m, ((45 - d)/45) * m);
			} else if (d >= 90 && d < 180) {
				Robot::drivetrain.TankDrive(((135 - d)/45) * m, -m);
			} else if (d >= 180 && d < 270) {
				Robot::drivetrain.TankDrive(-m, ((d - 225)/45) * m);
			} else {
				Robot::drivetrain.TankDrive(((d - 315)/45) * m, m);
			}
		} else {
			//4 zones, only forwards, backwards, or rotating (turning)
			if (x == 0) {
				if (y > 0) {
					Robot::drivetrain.TankDrive(m, m);
				} else {
					Robot::drivetrain.TankDrive(-m, -m);
				}
			} else if (d > 45 && d < 135) {
				Robot::drivetrain.TankDrive(m, -m);
			} else if (d >= 135 && d <= 225) {
				Robot::drivetrain.TankDrive(-m, -m);
			} else if (d > 225 && d < 315) {
				Robot::drivetrain.TankDrive(-m, m);
			} else {
				Robot::drivetrain.TankDrive(m, m);
			}
		}
	}
	//Prints encoder distance to SmartDashboard
	Robot::drivetrain.SmartDashboardnavX();
	Robot::drivetrain.ReturnDrivenInches(3);
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
