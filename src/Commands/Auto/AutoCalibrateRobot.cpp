/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoCalibrateRobot.h"
#include "Robot.h"
#include "Math.h"

AutoCalibrateRobot::AutoCalibrateRobot() {
	timer = new frc::Timer();
	stage = 0;
	speed = 0;
	distance = 0;
}

// Called just before this Command runs the first time
void AutoCalibrateRobot::Initialize() {
	Robot::drivetrain.ConfigureEncoders();
	Robot::drivetrain.ResetEncodersandNavX();
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoCalibrateRobot::Execute() {
	switch (stage) {
		case 0:
			if (abs(Robot::drivetrain.ReturnDrivenInches(3) - distance) > 0.02) {

			} else {
				Robot::drivetrain.TankDrive(speed, speed);
			}
	}
	for (int x = 0; x < (sizeof(distance) / 8) - 1; x++) {
		distance[x] = distance[x + 1];
	}
	distance[(sizeof(distance) / 8) - 2] = Robot::drivetrain.ReturnDrivenInches(3);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoCalibrateRobot::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AutoCalibrateRobot::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoCalibrateRobot::Interrupted() {

}
